#include <gtk/gtk.h>

typedef struct WIDGETS_T
{
    GtkWidget *window;
    GtkEntry *txt_counter;
    GtkButton *bt_counter;
} WIDGETS_T;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *error = NULL;

    WIDGETS_T *widgets = g_slice_new(WIDGETS_T);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "glade/window.glade", &error);
    if (error)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    widgets->bt_counter = GTK_BUTTON(gtk_builder_get_object(builder, "bt_counter"));
    widgets->txt_counter = GTK_ENTRY(gtk_builder_get_object(builder, "txt_counter"));

    gtk_entry_set_text(GTK_ENTRY(widgets->txt_counter), "0");

    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    if (!widgets->window)
        g_printerr("Window is NULL\n");

    gtk_widget_show(widgets->window);

    gtk_main();

    g_slice_free(WIDGETS_T, widgets);

    return 0;
}

void on_window_destroy(void)
{
    gtk_main_quit();
}

void on_bt_counter_clicked(GtkButton *bt_counter, void *data)
{
    WIDGETS_T *w = (WIDGETS_T *)data;

    static int value = 0;
    char buffer[1024] = {0};

    snprintf(buffer, 1024, "%d", ++value);

    gtk_entry_set_text(GTK_ENTRY(w->txt_counter), buffer);
}
