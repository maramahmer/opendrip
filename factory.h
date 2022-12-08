#ifndef FACTORY_H
#define FACTORY_H

#include "dataservice.h"
#include "displaystate.h"
#include "dataservicestate.h"
#include "userinterfacing.h"
#include "userrequest.h"
#include <QVector>

class Factory {
private:
    static DisplayState* createDisplayState(UserRequest req);
    static DataServiceState* createDataServiceState(UserRequest req);

public:
    Factory();
    ~Factory();
    static QVector<DataService*> createDataService(UserRequest *req, WeatherData *data);
    static QVector<UserInterfacing*> createDisplay(UserRequest *req, WeatherData *data, Ui::OpenDrip *UI);

};

#endif // FACTORY_H
