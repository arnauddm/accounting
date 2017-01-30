#include "accounting.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Accounting w;
    w.show();

    return a.exec();
}
