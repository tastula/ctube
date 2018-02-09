#include "ct-app.h"
#include "ct-window.h"
#include <gtk/gtk.h>

struct _CTWindow
{
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(CTWindow, ct_window, GTK_TYPE_APPLICATION_WINDOW);

static void ct_window_init(CTWindow* window)
{
    gtk_widget_init_template(GTK_WIDGET(window));
}

static void ct_window_class_init(CTWindowClass* class)
{
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/gtk/ctube/ui/window.ui"
    );
}

CTWindow* ct_window_new(CTApp* app)
{
    return g_object_new(CT_WINDOW_TYPE,
                        "application", app,
                        NULL);
}
