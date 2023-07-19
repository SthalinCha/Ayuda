#include "reglamento.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    REGLAMENTO w;
    w.show();
    return a.exec();
}
