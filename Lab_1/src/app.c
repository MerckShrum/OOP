//
// Created by merckshrum on 06.03.25.
//

#include "../inc/app.h"


void app_activate (GtkApplication *app, gpointer *user_data) {

    GtkBuilder* builder = gtk_builder_new_from_file("../ui/mainwindow.ui");
    GObject* window = gtk_builder_get_object (builder, "mainwindow");
    gtk_window_set_application(GTK_WINDOW(window), app);

    // Загрузка CSS
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(css_provider, "../ui/styles.css");

    // Применение CSS ко всему приложению
    GdkDisplay *display = gdk_display_get_default();
    gtk_style_context_add_provider_for_display(
        display,
        GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );

    g_object_unref (builder);
    // Показ окна
    gtk_window_present(GTK_WINDOW(window));
}