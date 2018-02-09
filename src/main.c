#include "ct-app.h"
#include <gtk/gtk.h>
#include <gst/gst.h>

int main(int argc, char** argv)
{
    gst_init(&argc, &argv);

    GtkApplication* app = ct_app_new();
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
