#include <QApplication>
#include "view/Window.h"


int main(int argc, char *argv[])
{
    QApplication GameOfLifeApplication(argc, argv);

    Window window;
    window.show();

    return GameOfLifeApplication.exec();
}
