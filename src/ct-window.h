#ifndef CT_WINDOW_H
#define CT_WINDOW_H

#include "ct-app.h"
#include <gtk/gtk.h>

#define CT_TYPE_WINDOW (ct_window_get_type())
G_DECLARE_FINAL_TYPE(CTWindow, ct_window, CT, Window, GtkApplicationWindow)

struct _CTWindow
{
    GtkApplicationWindow parent;
};

CTWindow* ct_window_new(CTApp* app);

#endif /* CT_WINDOW_H */
