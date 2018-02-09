#include "ct-app.h"
#include "ct-window.h"
#include <gtk/gtk.h>

struct _CTApp
{
    GtkApplication parent;
};

G_DEFINE_TYPE(CTApp, ct_app, GTK_TYPE_APPLICATION);

static void ct_app_init(CTApp* app)
{
}

static void ct_app_activate(GApplication* app)
{
    CTWindow* window;

    window = ct_window_new(CT_APP(app));
    gtk_window_present(GTK_WINDOW(window));
}

static void ct_app_class_init(CTAppClass* class)
{
    G_APPLICATION_CLASS(class)->activate = ct_app_activate;
}

CTApp* ct_app_new(void)
{
    return g_object_new(CT_APP_TYPE,
                        "application-id", "org.gtk.ctube",
                        "flags", G_APPLICATION_HANDLES_OPEN,
                        NULL);
}
