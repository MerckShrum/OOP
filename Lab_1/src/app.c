//
// Created by merckshrum on 06.03.25.
//

#include "../inc/app.h"


void app_activate (GtkApplication *app, gpointer *user_data)
{

    GtkBuilder* builder = gtk_builder_new_from_file("../ui/mainwindow.ui");
    GObject* window = gtk_builder_get_object (builder, "mainwindow");

    // Создание модели меню "Файл"
    GMenu *file_menu = g_menu_new();
    // g_menu_append(file_menu, "Новый", "app.new");
    g_menu_append(file_menu, "Открыть", "app.open");
    // g_menu_append(file_menu, "Сохранить", "app.save");
    // g_menu_append(file_menu, "Выйти", "app.quit");

    // Связывание модели меню с GtkPopoverMenu
    GtkWidget *file_menu_popover = GTK_WIDGET(gtk_builder_get_object(builder, "file-menu-popover"));
    gtk_popover_menu_set_menu_model(GTK_POPOVER_MENU(file_menu_popover), G_MENU_MODEL(file_menu));

    // Установка приложения для окна
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