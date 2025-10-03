#include <gtk/gtk.h>
#include <string.h>
#include "view.h"

static TRIANGLE_DTO_T view_get_triangle_dto(void *object);
static void view_set_triangle_result(void *object, const char *message);
static bool view_run(void *object);
static void view_graphic_init(VIEW_T *view, VIEW_ARGS_T *args);

bool view_init(VIEW_T *view)
{
    bool status = false;

    if (view != NULL)
    {
        memset(view, 0, sizeof(VIEW_T));
        view->base.object = view;
        view->base.get_triangle_dto = view_get_triangle_dto;
        view->base.set_triangle_result = view_set_triangle_result;
        view->base.run = view_run;

        status = true;
    }

    return status;
}

bool view_open(VIEW_T *view, VIEW_ARGS_T *args)
{
    bool status = false;

    if (view != NULL)
    {
        view->con = args->con;
        view_graphic_init(view, args);

        status = true;
    }

    return status;
}

bool view_close(VIEW_T *view)
{
    g_slice_free(VIEW_WIDGETS_T, view->vw);
    return true;
}

static bool view_run(void *object)
{
    VIEW_T *view = (VIEW_T *)object;

    gtk_widget_show(view->vw->window);

    gtk_main();

    return true;
}

static TRIANGLE_DTO_T view_get_triangle_dto(void *object)
{
    TRIANGLE_DTO_T dto;
    VIEW_T *view = (VIEW_T *)object;

    dto.side_a = (char *)gtk_entry_get_text(GTK_ENTRY(view->vw->txt_side_a));
    dto.side_b = (char *)gtk_entry_get_text(GTK_ENTRY(view->vw->txt_side_b));
    dto.side_c = (char *)gtk_entry_get_text(GTK_ENTRY(view->vw->txt_side_c));

    return dto;
}

static void view_set_triangle_result(void *object, const char *message)
{
    VIEW_T *view = (VIEW_T *)object;
    gtk_label_set_text(GTK_LABEL(view->vw->lb_result), message);
}

static void view_graphic_init(VIEW_T *view, VIEW_ARGS_T *args)
{
    GtkBuilder *builder;
    GError *error = NULL;

    view->vw = g_slice_new(VIEW_WIDGETS_T);
    gtk_init(&args->argc, &args->argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "glade/window.glade", &error);

    if (error)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    view->vw->window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    view->vw->txt_side_a = GTK_ENTRY(gtk_builder_get_object(builder, "txt_side_a"));
    view->vw->txt_side_b = GTK_ENTRY(gtk_builder_get_object(builder, "txt_side_b"));
    view->vw->txt_side_c = GTK_ENTRY(gtk_builder_get_object(builder, "txt_side_c"));
    view->vw->bt_submit = GTK_BUTTON(gtk_builder_get_object(builder, "bt_submit"));
    view->vw->lb_result = GTK_LABEL(gtk_builder_get_object(builder, "lb_result"));

    gtk_builder_connect_signals(builder, view);

    g_object_unref(builder);

    return;
}

void on_main_window_destroy(void)
{
    gtk_main_quit();
}

void on_txt_side_changed(GtkEditable *txt_side_a, void *data)
{
    VIEW_T *v = (VIEW_T *)data;
    v->con->on_change(v->con->object);
}

void on_bt_check_clicked(GtkEditable *txt_side_a, void *data)
{
    VIEW_T *v = (VIEW_T *)data;
    v->con->on_submit(v->con->object);
}
