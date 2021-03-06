#pragma once

#include <QWidget>
#include "scene.h"

namespace Ui {
class AppWindow;
}

/*
 *   RTR demo App, AppWindow
 *   Author: Hartmut Schirmacher
 *
 *   The AppWindow holds the GUI of the application that has been created
 *   and can be edited in Qt UI designer.
 *
 *   It consists of an OpenGL Widget for rendering the OpenGL Scene,
 *   plus additional UI elements like buttons.
 *
 *   It also acts as controller that connects app-wide keyboard events
 *   with respective actions in the scene.
 *
 */

class AppWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = 0);
    ~AppWindow();

    // convenience shortcut to the OpenGL scene
    Scene &scene();
    QRgb circle_color_;

public slots:

    /* show buttons etc, and a border around the OpenGL widget */
    void showUI();
    /* hide all buttons etc, and remove border around the OpenGL widget */
    void hideUI();

    /* process app-wide key events and trigger respective actions in UI or in the scene */
    void keyPressEvent(QKeyEvent *event);

private slots:

    void on_spinBox_cel_level_valueChanged(int arg1);

    void on_horizontalSlider_x_rotation_valueChanged(int value);

    void on_pushButton_colorPicker_clicked();

    void on_spinBox_radius_valueChanged(int arg1);

    void on_spinBox_density_valueChanged(int arg1);

    void on_horizontalSlider_y_rotation_valueChanged(int value);

private:
    // this is the connection to the class that will come out of the UI designer
    Ui::AppWindow *ui;
};

