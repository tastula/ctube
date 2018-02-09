#ifndef CT_APPLICATION_H
#define CT_APPLICATION_H

#include <gtk/gtk.h>

#define CT_APP_TYPE (ct_app_get_type())
G_DECLARE_FINAL_TYPE(CTApp, ct_app, CT, APP, GtkApplication)

CTApp* ct_app_new(void);

#endif /* CT_APPLICATION_H */
