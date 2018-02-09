#include "ct-app.h"
#include "ct-window.h"
#include <gtk/gtk.h>
#include <gst/gst.h>

static GstElement *playbin, *sink;

typedef struct
{
    GtkWidget* drawing_area;
    GtkWidget* overlay;
} CTWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(CTWindow, ct_window, GTK_TYPE_APPLICATION_WINDOW);

static void ct_window_init(CTWindow* self)
{
    /* Setting up and embedding gstreamer is copied straight from
     * Stack Overflow, at least for now.
     * https://stackoverflow.com/questions/38375102/unable-to-embed-gstreamer-video-in-a-gtk-window
     */

    CTWindowPrivate* priv = ct_window_get_instance_private(self);
    gtk_widget_init_template(GTK_WIDGET(self));

    playbin = gst_element_factory_make("playbin", NULL);
    g_object_set(playbin, "uri", "https://freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm", NULL);

    sink = gst_element_factory_make ("gtksink", NULL);
    g_object_set(playbin, "video-sink", sink, NULL);

    GtkWidget *overlay = gtk_overlay_new();
    gtk_container_add(GTK_CONTAINER(self), overlay);

    GtkWidget *video_drawing_area = gtk_drawing_area_new();

    g_object_get (sink, "widget", &video_drawing_area, NULL);
    gtk_widget_set_size_request(video_drawing_area, 800, 600);
    gtk_container_add(GTK_CONTAINER(overlay), video_drawing_area);

    gst_element_set_state(playbin, GST_STATE_PLAYING);
    gtk_widget_show_all(self);

}

static void ct_window_class_init(CTWindowClass* class)
{
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/gtk/ctube/ui/window.ui"
    );
    gtk_widget_class_bind_template_child_private(
        GTK_WIDGET_CLASS(class), CTWindow, overlay
    );
    gtk_widget_class_bind_template_child_private(
        GTK_WIDGET_CLASS(class), CTWindow, drawing_area
    );
}

CTWindow* ct_window_new(CTApp* app)
{
    return g_object_new(CT_TYPE_WINDOW,
                        "application", app,
                        NULL);
}
