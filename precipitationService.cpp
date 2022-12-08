#include "precipitationService.h"
#include <QJsonArray>
#include <iostream>
#include <ostream>
/// @brief	    precipitationService is used to access the API data for the precipitation and send it to our handling functions.
/// @details    precipitationService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
PrecipitationService::PrecipitationService() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
PrecipitationService::~PrecipitationService() {
        delete this->_state;
}

/// @brief  	sends the precipitation.
/// @details	sends the data gotten from this to displayPrecipitation.
void PrecipitationService::doService() {
    this->_state->doService();
}

/// @brief  	gets the current precipitation.
/// @details	gets the precipitation at the current time from the API.
void PrecipitationService::currentDataService(){

    QJsonObject json = interface->APICall();

    QJsonArray arrayJson = json["weather"].toArray();

    QJsonObject jsonWeather = arrayJson[0].toObject();

    QJsonValue jPres = jsonWeather["description"];

    data->setCurrentPrecipitation(jPres.toString());
}

/// @brief  	gets the precipitation over the next 24 hours.
/// @details	gets the precipitation for each hour over the next 24 hours from the API.
void PrecipitationService::twentyFourHourDataService(){
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<QString> hourlyPrecip;


    for (int i = 0; i < 8; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonArray arrayJson = obj["weather"].toArray();


        QJsonObject jsonWeather = arrayJson[0].toObject();

        QJsonValue jPres = jsonWeather["description"];

        QString hum = jPres.toString();
        hourlyPrecip.append(hum);
    }

    data->setTwentyFourPrecipitation(hourlyPrecip);

}

/// @brief  	gets the precipitation over the next 4 days.
/// @details	gets the precipitation for each day over the next 4 days from the API.
void PrecipitationService::fourDayDataService(){

    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<QString> hourlyPrecip;


    for (int i = 0; i < 40; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonArray arrayJson = obj["weather"].toArray();

        QJsonObject jsonWeather = arrayJson[0].toObject();

        QJsonValue jPres = jsonWeather["description"];

        QString hum = jPres.toString();
        hourlyPrecip.append(hum);
    }

    QVector<QString> vec;

    for (int i = 0; i < 5; i++) {

        vec.append(hourlyPrecip.at(i*4));
    }


    data->setFourDayPrecipitation(hourlyPrecip);
}

