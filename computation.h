#ifndef COMPUTATION_H
#define COMPUTATION_H

#include <QVector>
#include "factory.h"
#include "weatherData.h"
#include "userrequest.h"

class Computation {

private:
    QVector<DataService*> services;
    QVector<UserInterfacing*> displays;

public:
    Computation();
    ~Computation();
    void performServices(UserRequest *req, WeatherData *data);
    void performDisplay(UserRequest *req, WeatherData *data, Ui::OpenDrip *ui);
};

#endif // COMPUTATION_H
