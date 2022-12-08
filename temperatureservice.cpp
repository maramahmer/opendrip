#include "temperatureservice.h"
#include <QJsonArray>
#include <iostream>
#include <cmath>

/// @brief	    temperatureService is used to access the API data for the temperature and send it to our handling functions.
/// @details    temperatureService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
TemperatureService::TemperatureService()
{
}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
TemperatureService::~TemperatureService()
{
        delete this->_state;
}

/// @brief  	sends the temperature.
/// @details	sends the data gotten from this to displayTemperature.
void TemperatureService::doService()
{
    this->_state->doService();
}

/// @brief  	gets the current temperature.
/// @details	gets the temperature at the current time from the API.
void TemperatureService::currentDataService()
{

    QJsonObject json = interface->APICall();

    QJsonObject mainJson = json["main"].toObject();

    QJsonValue jTemp = mainJson["temp"];

    double temp = jTemp.toDouble() - 273;

    if (req->getRequestedTemperatureType() == 1)
    {
        temp = temp * (9.0 / 5.0) + 32;
    }

    data->setCurrentTemperature(std::ceil(temp));
}

/// @brief  	gets the temperature over the next 24 hours.
/// @details	gets the temperature for each hour over the next 24 hours from the API.
void TemperatureService::twentyFourHourDataService()
{
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<double> hourlyTemp;

    for (int i = 0; i < 8; i++)
    {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jTemp = valobj["temp"];

        int temp = jTemp.toDouble() - 273;
        if (req->getRequestedTemperatureType() == 1)
        {
            temp = temp * (9.0 / 5.0) + 32;
        }
        hourlyTemp.append(std::ceil(temp));
    }

    data->setTwentyFourTemperature(hourlyTemp);
}

/// @brief  	gets the temperature over the next 4 days.
/// @details	gets the temperature for each day over the next 4 days from the API.
void TemperatureService::fourDayDataService()
{

    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<double> hourlyTemp;

    for (int i = 0; i < 40; i++)
    {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jTemp = valobj["temp"];

        double temp = jTemp.toDouble();
        hourlyTemp.append(temp);
    }

    QVector<double> vec;

    for (int i = 0; i < 5; i++)
    {
        double sum = 0;
        for (int j = 0; j < 8; j++)
        {
            sum += hourlyTemp[i * 8 + j];
        }
        vec.append(std::ceil((sum / 8) - 273));
    }

    if (req->getRequestedTemperatureType() == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            vec[i] = vec[i] * (9.0 / 5.0) + 32;
        }
    }

    data->setFourDayTemperature(vec);
}
