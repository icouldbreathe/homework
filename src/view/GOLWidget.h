#ifndef GOLWIDGET_H
#define GOLWIDGET_H

#include <QFrame>
#include <QPaintEvent>
#include <QTimer>
#include "../gol/GameOfLife.h"

class GOLWidget : public QFrame
{
    Q_OBJECT
private:
    int padding;
    unsigned long tickCount;
    GameOfLife *gol;
    QTimer *timer;
    int timerInterval;
    int gridWidth;
    int gridHeight;
    int cellPixelSize;
    QColor cellColor;
public:
    explicit GOLWidget(QWidget *parent = 0);
    void Start();
    void Pause();
    void Clear();
    void Populate();
    void ChangeSpeed(int value);
    ~GOLWidget();
private slots:
    void tick();
protected:
    void paintEvent(QPaintEvent *) override;
private:
    void drawCell(QPainter &painter, int x, int y);

};

#endif // GOLWIDGET_H
