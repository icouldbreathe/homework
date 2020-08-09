#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "GOLWidget.h"
#include <QLayout>
#include <QPushButton>
#include <QSlider>

class Window : public QWidget
{
    Q_OBJECT
public:
    Window();
    ~Window();
public slots:
    void handleStartButton();
    void handlePauseButton();
    void handleSpeedValueChange(int value);
    void handleClearButton();
    void handlePopulateButton();
private:
    GOLWidget *golWidget;
    QVBoxLayout *layout;
    QHBoxLayout *horizontalControlsLayout;
    QWidget *controlsWidget;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *clearButton;
    QPushButton *populateButton;
    QSlider *speedSlider;
};

#endif // WINDOW_H
