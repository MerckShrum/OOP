//
// Created by merckshrum on 06.03.25.
//

#include "../inc/app.h"

typedef struct {
    int square_size;
    GtkWidget *drawing_area;
} AppData;

static void draw_function(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {
    AppData *data = (AppData *)user_data;
    int square_size = data->square_size;
    // Рисуем квадрат
    cairo_rectangle(cr, width / 2 - square_size / 2, height / 2 - square_size / 2, square_size, square_size);
    cairo_stroke(cr);
}

static void on_button_moving_x_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_moving_x_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_moving_y_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_moving_y_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_moving_z_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_moving_z_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_rotation_x_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_rotation_x_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_rotation_y_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_rotation_y_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_rotation_z_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_rotation_z_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_scaling_x_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_scaling_x_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_scaling_y_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_scaling_y_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_scaling_z_inc_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_button_scaling_z_dec_clicked(GtkButton *button, gpointer user_data) {
    const char *message = (const char *)user_data;
    g_print("%s\n", message);
}

static void on_scale_value_changed(GtkRange *scale, gpointer user_data) {
    double value = gtk_range_get_value(scale); // Получаем текущее значение
    g_print("Чел: %.2f\n", value);
}

// Обработчик завершения диалога выбора файла
static void on_file_dialog_finish(GObject *source_object, GAsyncResult *result, gpointer user_data) {
    GtkFileDialog *dialog = GTK_FILE_DIALOG(source_object);
    GFile *file = gtk_file_dialog_open_finish(dialog, result, NULL);

    if (file != NULL) {
        char *filename = g_file_get_path(file);
        g_print("Выбран файл: %s\n", filename);
        g_free(filename);
        g_object_unref(file); // Освобождаем GFile
    }
}

// Обработчик действия "Открыть"
static void open_activated(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
    GtkWindow *window = GTK_WINDOW(user_data);
    GtkFileDialog *dialog;

    // Создаем диалог выбора файла
    dialog = gtk_file_dialog_new();
    gtk_file_dialog_set_title(dialog, "Открыть файл");

    // Показываем диалог (асинхронно)
    gtk_file_dialog_open(dialog, window, NULL, on_file_dialog_finish, NULL);
}



void app_activate(GtkApplication *app, gpointer *user_data) {
    // Загружаем интерфейс из файла
    GtkBuilder *builder_mainwindow = gtk_builder_new_from_file("../ui/mainwindow.ui");
    GObject *window = gtk_builder_get_object(builder_mainwindow, "mainwindow");

    // Явно приводим окно к GtkApplicationWindow
    GtkApplicationWindow *app_window = GTK_APPLICATION_WINDOW(window);

    // Загружаем меню из UI-файла
    GtkBuilder *builder_menu = gtk_builder_new_from_file("../ui/menu.ui");
    GMenuModel *menu = G_MENU_MODEL(gtk_builder_get_object(builder_menu, "app-menu"));

    // Устанавливаем меню в приложение
    gtk_application_set_menubar(GTK_APPLICATION(app), menu);

    // Получаем GtkDrawingArea
    GtkWidget *drawing_area = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "drawingArea"));

    // Создаем структуру данных для рисования
    AppData *data = g_new0(AppData, 1);
    data->square_size = 80; // Начальный размер квадрата
    data->drawing_area = drawing_area; // Указатель на GtkDrawingArea

    // Устанавливаем функцию рисования
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), draw_function, data, NULL);

    // Регистрируем действие "open" в приложении
    GSimpleAction *open_action = g_simple_action_new("open", NULL);
    g_signal_connect(open_action, "activate", G_CALLBACK(open_activated), app_window);
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(open_action));

    // Подключаем обработчики кнопок
    GtkWidget *button_moving_x_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonMovingXInc"));
    g_signal_connect(button_moving_x_inc, "clicked", G_CALLBACK(on_button_moving_x_inc_clicked), "Чел, кринжуешь");

    GtkWidget *button_moving_x_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonMovingXDec"));
    g_signal_connect(button_moving_x_dec, "clicked", G_CALLBACK(on_button_moving_x_dec_clicked), "Чел, суперкринжуешь");

    GtkWidget *button_moving_y_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonMovingYInc"));
    g_signal_connect(button_moving_y_inc, "clicked", G_CALLBACK(on_button_moving_y_inc_clicked), "Чел, мегакринжуешь");

    GtkWidget *button_moving_y_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonMovingYDec"));
    g_signal_connect(button_moving_y_dec, "clicked", G_CALLBACK(on_button_moving_y_dec_clicked), "Чел, ультракринжуешь");

    GtkWidget *button_moving_z_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonMovingZInc"));
    g_signal_connect(button_moving_z_inc, "clicked", G_CALLBACK(on_button_moving_z_inc_clicked), "Чел, гигакринжуешь");

    GtkWidget *button_moving_z_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonMovingZDec"));
    g_signal_connect(button_moving_z_dec, "clicked", G_CALLBACK(on_button_moving_z_dec_clicked), "Чел, пиздец как кринжуешь");

    GtkWidget *button_rotation_x_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonRotationXInc"));
    g_signal_connect(button_rotation_x_inc, "clicked", G_CALLBACK(on_button_rotation_x_inc_clicked), "Что с лицом?");

    GtkWidget *button_rotation_x_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonRotationXDec"));
    g_signal_connect(button_rotation_x_dec, "clicked", G_CALLBACK(on_button_rotation_x_dec_clicked), "Что с мордой лица?");

    GtkWidget *button_rotation_y_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonRotationYInc"));
    g_signal_connect(button_rotation_y_inc, "clicked", G_CALLBACK(on_button_rotation_y_inc_clicked), "Что с рожей?");

    GtkWidget *button_rotation_y_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonRotationYDec"));
    g_signal_connect(button_rotation_y_dec, "clicked", G_CALLBACK(on_button_rotation_y_dec_clicked), "Что с физиономией?");

    GtkWidget *button_rotation_z_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonRotationZInc"));
    g_signal_connect(button_rotation_z_inc, "clicked", G_CALLBACK(on_button_rotation_z_inc_clicked), "Что с таблом?");

    GtkWidget *button_rotation_z_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonRotationZDec"));
    g_signal_connect(button_rotation_z_dec, "clicked", G_CALLBACK(on_button_rotation_z_dec_clicked), "Что с хлеборезкой?");

    GtkWidget *button_scaling_x_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonScalingXInc"));
    g_signal_connect(button_scaling_x_inc, "clicked", G_CALLBACK(on_button_scaling_x_inc_clicked), "Минусы?");

    GtkWidget *button_scaling_x_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonScalingXDec"));
    g_signal_connect(button_scaling_x_dec, "clicked", G_CALLBACK(on_button_scaling_x_dec_clicked), "Минусы будут?");

    GtkWidget *button_scaling_y_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonScalingYInc"));
    g_signal_connect(button_scaling_y_inc, "clicked", G_CALLBACK(on_button_scaling_y_inc_clicked), "А по минусам?");

    GtkWidget *button_scaling_y_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonScalingYDec"));
    g_signal_connect(button_scaling_y_dec, "clicked", G_CALLBACK(on_button_scaling_y_dec_clicked), "Минусов не вижу");

    GtkWidget *button_scaling_z_inc = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonScalingZInc"));
    g_signal_connect(button_scaling_z_inc, "clicked", G_CALLBACK(on_button_scaling_z_inc_clicked), "Чел, назови минусы");

    GtkWidget *button_scaling_z_dec = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "buttonScalingZDec"));
    g_signal_connect(button_scaling_z_dec, "clicked", G_CALLBACK(on_button_scaling_z_dec_clicked), "А минусы?");

    GtkWidget *scale = GTK_WIDGET(gtk_builder_get_object(builder_mainwindow, "scaleFOV"));
    g_signal_connect(scale, "value-changed", G_CALLBACK(on_scale_value_changed), NULL);

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

    // Освобождаем GtkBuilder
    g_object_unref(builder_menu);
    g_object_unref(builder_mainwindow);

    // Показ окна
    gtk_window_present(GTK_WINDOW(window));
}