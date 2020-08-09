#include "GOLWidget.h"
#include <QPaintEvent>
#include <QPainter>
#include <iostream>

GOLWidget::GOLWidget(QWidget *parent) : QFrame(parent)
{
    // TODO: Implement change field size feature.
    cellPixelSize = 4;
    gridWidth = 150;
    gridHeight = 150;
    padding = 3;
    cellColor = Qt::black;

    setFixedSize(gridWidth*cellPixelSize, gridHeight*cellPixelSize);
    setStyleSheet("background-color: white; border-style: inset; border-width: 4px; border-color: rgba(100, 100, 100, 0.2);");

    // Initialize GameOfLife instance
    gol = new GameOfLife(gridWidth+padding, gridHeight+padding, time(NULL));
    gol->Populate();

    // Set up Timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timerInterval = 500;
    tickCount = 0;
}

void GOLWidget::Start()
{
    if (!timer->isActive())
    {
       timer->start(timerInterval);
    }

}

void GOLWidget::Clear()
{
    if (timer->isActive())
    {
        timer->stop();
    }
    gol->Clear();
    tickCount = 0;
    update();
}

void GOLWidget::Populate()
{
    gol->Populate();
    gol->Update();
    tickCount = 0;
    update();
}

void GOLWidget::Pause()
{
    if(timer->isActive())
    {
        timer->stop();
    }
}

void GOLWidget::ChangeSpeed(int value)
{
    timerInterval = 1000 - value;
    if (timer->isActive())
    {
        timer->setInterval(timerInterval);
    }
}

void GOLWidget::tick()
{
    gol->Update();
    tickCount++;
    update();
}

void GOLWidget::drawCell(QPainter &painter, int x, int y)
{
    painter.fillRect(x*cellPixelSize, y*cellPixelSize, cellPixelSize, cellPixelSize, cellColor);
}

void GOLWidget::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);

    for(int i = 0; i < gol->GetAliveCells().size(); i++)
    {
        drawCell(painter, gol->GetAliveCells().at(i).x, gol->GetAliveCells().at(i).y);
    }
}

GOLWidget::~GOLWidget()
{
    delete timer;
    delete gol;
}
