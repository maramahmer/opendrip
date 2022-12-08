#include "humidityservice.h"
#include "weatherinterface.h"
#include "weatherData.h"
#include <iostream>
#include <QJsonArray>

/// @brief	    humidityService is used to access the API data for the humidity and send it to our handling functions.
/// @details    humidityService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
HumidityService::HumidityService()
{
}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
HumidityService::~HumidityService()
{
    delete this->_state;
}

/// @brief  	sends the humidity.
/// @details	sends the data gotten from this to displayHumidity.
void HumidityService::doService()
{
    this->_state->doService();
}

/// @brief  	gets the current humidity.
/// @details	gets the humidity at the current time from the API.
void HumidityService::currentDataService()
{
    QJsonObject json = interface->APICall();

    QJsonObject mainJson = json["main"].toObject();

    QJsonValue jhumidity = mainJson["humidity"];

    int humidity = jhumidity.toInt();

    this->data->setCurrentHumidity(humidity);
}

/// @brief  	gets the humidity over the next 24 hours.
/// @details	gets the humidity for each hour over the next 24 hours from the API.
void HumidityService::twentyFourHourDataService(){

    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<int> hourlyHum;


    for (int i = 0; i < 8; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jHum = valobj["humidity"];

        int hum = jHum.toInt();
        hourlyHum.append(hum);
    }

    data->setTwentyFourHumidity(hourlyHum);

}

/// @brief  	gets the humidity over the next 4 days.
/// @details	gets the humidity for each day over the next 4 days from the API.
void HumidityService::fourDayDataService(){
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<int> hourlyHum;


    for (int i = 0; i < 40; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jHum = valobj["humidity"];

        int hum = jHum.toInt();
        hourlyHum.append(hum);
    }

    QVector<int> vec;

    for (int i = 0; i < 5; i++) {
        double sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += hourlyHum[i*8 + j];
        }
        vec.append(sum / 8);
    }


    data->setFourDayHumidity(vec);

}
