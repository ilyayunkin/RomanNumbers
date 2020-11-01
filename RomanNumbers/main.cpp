#include "RomanNumbersWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RomanNumbersWidget w;
    w.show();
    return a.exec();
}
