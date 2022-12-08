#include "opendrip.h"

#include <QApplication>
#include <QTextStream>
#include "userrequest.h"
#include <QVector>
#include <QString>
#include <iostream>
#include "factory.h"
#include "computation.h"
#include "humidityservice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenDrip w;
    w.show();

    return a.exec();
}
