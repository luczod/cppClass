#include <gtk/gtk.h>
#include <string.h>
#include "view.h"

void view_set_text(void *object, const char *text);
void view_run(void *object);
bool view_graphic_init(VIEW_T *view);

bool view_init(VIEW_T *view)
{
    bool status = false;
    if (view != NULL)
    {
        memset(view, 0, sizeof(VIEW_T));

        view->base.object = view;
        view->base.set_text = view_set_text;
        view->base.run = view_run;

        status = true;
    }

    return status;
}

bool view_open(VIEW_T *view, VIEW_ARGS_T *args)
{
    bool status = true;

    if (view != NULL && args != NULL)
    {
        view->constroller_base = args->constroller_base;
        view->argc = args->argc;
        view->argv = args->argv;

        status = view_graphic_init(view);
    }
    return status;
}

bool view_close(VIEW_T *view)
{
    bool status = true;

    if (view != NULL)
    {
        g_slice_free(WIDGETS_T, view->widgets);

        memset(view, 0, sizeof(VIEW_T));

        status = true;
    }

    return status;
}

void view_set_text(void *object, const char *text)
{
    VIEW_T *view = (VIEW_T *)object;
    gtk_entry_set_text(GTK_ENTRY(view->widgets->txt_counter), text);
}

void view_run(void *object)
{
    VIEW_T *view = (VIEW_T *)object;

    if (!view->widgets->window)
        g_printerr("Window is NULL\n");

    gtk_widget_show(view->widgets->window);

    gtk_main();
}

bool view_graphic_init(VIEW_T *view)
{
    GtkBuilder *builder;
    GError *error = NULL;

    view->widgets = g_slice_new(WIDGETS_T);

    gtk_init(&view->argc, &view->argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "glade/window.glade", &error);
    if (error)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    view->widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    view->widgets->bt_counter = GTK_BUTTON(gtk_builder_get_object(builder, "bt_counter"));
    view->widgets->txt_counter = GTK_ENTRY(gtk_builder_get_object(builder, "txt_counter"));

    gtk_builder_connect_signals(builder, view);

    g_object_unref(builder);

    return true;
}

void on_window_destroy(void)
{
    gtk_main_quit();
    printf("Close");
}

void on_bt_counter_clicked(GtkButton *bt_counter, void *data)
{
    VIEW_T *view = (VIEW_T *)data;
    view->constroller_base->on_click(view->constroller_base->object);
}
