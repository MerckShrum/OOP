//
// Created by merckshrum on 06.03.25.
//

#include "../inc/app.h"

typedef struct {
    gpointer window;
    gpointer user_data;
} window_data_t;

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

// Обработчик ответа от диалога выбора файла
static void on_file_dialog_response(GtkNativeDialog *dialog, int response, gpointer user_data) {
    if (response == GTK_RESPONSE_ACCEPT) {
        // Получаем выбранный файл
        GFile *file = gtk_file_chooser_get_file(GTK_FILE_CHOOSER(dialog));
        if (file != NULL) {
            char *filename = g_file_get_path(file); // Получаем путь к файлу
            // action_t action;
            // action_set_file(&action, filename);
            // action_set_canvas(&action, user_data);



            // AppData *data = (AppData *)user_data;
            // Обновляем размер квадрата
            // data->square_size = 100;
            // Вызываем перерисовку
            // gtk_widget_queue_draw(data->drawing_area);





            g_print("Выбран файл: %s\n", filename);
            g_free(filename); // Освобождаем память
            g_object_unref(file); // Освобождаем объект GFile
        }
    }

    // Закрываем диалог
    g_object_unref(dialog);
}

// Обработчик для пункта "Открыть"
static void on_open_action(GSimpleAction *action, GVariant *parameter, window_data_t user_data) {
    GtkWindow *window = GTK_WINDOW(user_data.window);

    // Создаём диалог выбора файла
    GtkFileChooserNative *native = gtk_file_chooser_native_new(
        "Открыть файл", // Заголовок диалога
        window,         // Родительское окно
        GTK_FILE_CHOOSER_ACTION_OPEN, // Режим открытия файла
        "_Открыть",     // Текст на кнопке подтверждения
        "_Отмена"       // Текст на кнопке отмены
    );

    // Подключаем обработчик сигнала "response"
    g_signal_connect(native, "response", G_CALLBACK(on_file_dialog_response), user_data.user_data);

    // Показываем диалог
    gtk_native_dialog_show(GTK_NATIVE_DIALOG(native));
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

void app_activate (GtkApplication *app, gpointer *user_data) {

    GtkBuilder* builder = gtk_builder_new_from_file("../ui/mainwindow.ui");
    GObject* window = gtk_builder_get_object (builder, "mainwindow");





    GtkWidget *drawing_area = GTK_WIDGET(gtk_builder_get_object(builder, "drawingArea"));

    AppData *data = g_new0(AppData, 1);
    data->square_size = 40; // Начальный размер квадрата
    data->drawing_area = drawing_area ; // Указатель на GtkDrawingArea


    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA (drawing_area), draw_function, data, NULL);

    window_data_t window_data;
    window_data.window = window;
    window_data.user_data = data;






    // Создание модели меню "Файл"
    GMenu *file_menu = g_menu_new();
    g_menu_append(file_menu, "Открыть", "app.open");
    GSimpleAction *open_action = g_simple_action_new("open", NULL);
    g_signal_connect(open_action, "activate", G_CALLBACK(on_open_action), &window_data);
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(open_action));

    // Связывание модели меню с GtkPopoverMenu
    GtkWidget *file_menu_popover = GTK_WIDGET(gtk_builder_get_object(builder, "file-menu-popover"));
    gtk_popover_menu_set_menu_model(GTK_POPOVER_MENU(file_menu_popover), G_MENU_MODEL(file_menu));

    // Получаем кнопку из интерфейса
    GtkWidget *button_moving_x_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonMovingXInc"));
    // Подключаем обработчик сигнала "clicked" с пользовательскими данными
    g_signal_connect(button_moving_x_inc, "clicked", G_CALLBACK(on_button_moving_x_inc_clicked), "Чел, кринжуешь");

    GtkWidget *button_moving_x_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonMovingXDec"));
    g_signal_connect(button_moving_x_dec, "clicked", G_CALLBACK(on_button_moving_x_dec_clicked), "Чел, суперкринжуешь");

    GtkWidget *button_moving_y_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonMovingYInc"));
    g_signal_connect(button_moving_y_inc, "clicked", G_CALLBACK(on_button_moving_y_inc_clicked), "Чел, мегакринжуешь");

    GtkWidget *button_moving_y_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonMovingYDec"));
    g_signal_connect(button_moving_y_dec, "clicked", G_CALLBACK(on_button_moving_y_dec_clicked), "Чел, ультракринжуешь");

    GtkWidget *button_moving_z_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonMovingZInc"));
    g_signal_connect(button_moving_z_inc, "clicked", G_CALLBACK(on_button_moving_z_inc_clicked), "Чел, гигакринжуешь");

    GtkWidget *button_moving_z_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonMovingZDec"));
    g_signal_connect(button_moving_z_dec, "clicked", G_CALLBACK(on_button_moving_z_dec_clicked), "Чел, пиздец как кринжуешь");



    GtkWidget *button_rotation_x_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRotationXInc"));
    g_signal_connect(button_rotation_x_inc, "clicked", G_CALLBACK(on_button_rotation_x_inc_clicked), "Что с лицом?");

    GtkWidget *button_rotation_x_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRotationXDec"));
    g_signal_connect(button_rotation_x_dec, "clicked", G_CALLBACK(on_button_rotation_x_dec_clicked), "Что с мордой лица?");

    GtkWidget *button_rotation_y_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRotationYInc"));
    g_signal_connect(button_rotation_y_inc, "clicked", G_CALLBACK(on_button_rotation_y_inc_clicked), "Что с рожей?");

    GtkWidget *button_rotation_y_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRotationYDec"));
    g_signal_connect(button_rotation_y_dec, "clicked", G_CALLBACK(on_button_rotation_y_dec_clicked), "Что с физиономией?");

    GtkWidget *button_rotation_z_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRotationZInc"));
    g_signal_connect(button_rotation_z_inc, "clicked", G_CALLBACK(on_button_rotation_z_inc_clicked), "Что с таблом?");

    GtkWidget *button_rotation_z_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRotationZDec"));
    g_signal_connect(button_rotation_z_dec, "clicked", G_CALLBACK(on_button_rotation_z_dec_clicked), "Что с хлеборезкой?");


    GtkWidget *button_scaling_x_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonScalingXInc"));
    g_signal_connect(button_scaling_x_inc, "clicked", G_CALLBACK(on_button_scaling_x_inc_clicked), "Минусы?");

    GtkWidget *button_scaling_x_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonScalingXDec"));
    g_signal_connect(button_scaling_x_dec, "clicked", G_CALLBACK(on_button_scaling_x_dec_clicked), "Минусы будут?");

    GtkWidget *button_scaling_y_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonScalingYInc"));
    g_signal_connect(button_scaling_y_inc, "clicked", G_CALLBACK(on_button_scaling_y_inc_clicked), "А по минусам?");

    GtkWidget *button_scaling_y_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonScalingYDec"));
    g_signal_connect(button_scaling_y_dec, "clicked", G_CALLBACK(on_button_scaling_y_dec_clicked), "Минусов не вижу");

    GtkWidget *button_scaling_z_inc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonScalingZInc"));
    g_signal_connect(button_scaling_z_inc, "clicked", G_CALLBACK(on_button_scaling_z_inc_clicked), "Чел, назови минусы");

    GtkWidget *button_scaling_z_dec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonScalingZDec"));
    g_signal_connect(button_scaling_z_dec, "clicked", G_CALLBACK(on_button_scaling_z_dec_clicked), "А минусы?");

    GtkWidget *scale = GTK_WIDGET(gtk_builder_get_object(builder, "scaleFOV"));
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

    g_object_unref (builder);
    // Показ окна
    gtk_window_present(GTK_WINDOW(window));
}