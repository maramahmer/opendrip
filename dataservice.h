#ifndef DATASERVICE_H
#define DATASERVICE_H


#include "dataservicestate.h"
//#include <QJsonObject>
//#include <iostream>
//#include <QJsonArray>
#include "userrequest.h"
#include "weatherData.h"
#include "weatherinterface.h"

class DataService {

public:
    DataService();
    virtual ~DataService() = 0;
    virtual void doService() = 0;
    virtual void currentDataService() = 0;
    virtual void twentyFourHourDataService() = 0;
    virtual void fourDayDataService() = 0;
    void setState(DataServiceState* state);
    void setUserRequest(UserRequest* request);
    void setWeatherData(WeatherData* data);
    void setWeatherInterface(WeatherInterface* interface);

protected:
    DataServiceState* _state;
    UserRequest *req;
    WeatherData *data;
    WeatherInterface *interface;
};

#endif // DATASERVICE_H
