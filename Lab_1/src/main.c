#include <gtk/gtk.h>
#include "../inc/app.h"


int main (int argc, char **argv)
{
    GtkApplication *app = gtk_application_new ("MerckShrum.cum", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
    int status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}