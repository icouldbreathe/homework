#include "Window.h"

Window::Window()
{
    setWindowTitle(tr("Conway\'s Game of Life"));

    // Fixed size as the view is currently limited.
    setFixedSize(620, 720);

    // Initialize Game of Life widget
    golWidget = new GOLWidget;

    horizontalControlsLayout = new QHBoxLayout();
    controlsWidget = new QWidget();
    controlsWidget->setLayout(horizontalControlsLayout);

    startButton = new QPushButton();
    startButton->setText("Play");
    startButton->setFixedWidth(100);

    pauseButton = new QPushButton();
    pauseButton->setText("Pause");
    pauseButton->setFixedWidth(100);

    clearButton = new QPushButton();
    clearButton->setText("Clear");
    clearButton->setFixedWidth(100);

    populateButton = new QPushButton();
    populateButton->setText("Populate");
    populateButton->setFixedWidth(100);

    speedSlider = new QSlider();
    speedSlider->setToolTip("Execution speed");
    speedSlider->setOrientation(Qt::Horizontal);
    speedSlider->setRange(0, 1000);
    speedSlider->setValue(0);
    speedSlider->setTickInterval(100);
    speedSlider->setFixedWidth(100);

    horizontalControlsLayout->addWidget(startButton);
    horizontalControlsLayout->addWidget(pauseButton);
    horizontalControlsLayout->addWidget(clearButton);
    horizontalControlsLayout->addWidget(populateButton);
    horizontalControlsLayout->addWidget(speedSlider);

    layout = new QVBoxLayout;
    layout->setMargin(10);
    layout->addWidget(controlsWidget);
    layout->addWidget(golWidget);
    layout->setAlignment(golWidget, Qt::AlignHCenter);
    setLayout(layout);

    // Connect signals
    connect(startButton, SIGNAL(released()), this, SLOT(handleStartButton()));
    connect(pauseButton, SIGNAL(released()), this, SLOT(handlePauseButton()));
    connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(handleSpeedValueChange(int)));
    connect(clearButton, SIGNAL(released()), this, SLOT(handleClearButton()));
    connect(populateButton, SIGNAL(released()), this, SLOT(handlePopulateButton()));
}

void Window::handleStartButton()
{
    golWidget->Start();
}

void Window::handlePauseButton()
{
    golWidget->Pause();
}

void Window::handleSpeedValueChange(int value)
{
    golWidget->ChangeSpeed(value);
}

void Window::handleClearButton()
{
    golWidget->Clear();
}

void Window::handlePopulateButton()
{
    golWidget->Populate();
}

Window::~Window()
{
    delete golWidget;
}
