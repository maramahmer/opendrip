#include "windspeedservice.h"
#include <iostream>
#include <QJsonArray>

/// @brief	    windspeedService is used to access the API data for the windspeed and send it to our handling functions.
/// @details    windspeedService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
WindSpeedService::WindSpeedService()
{

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
WindSpeedService::~WindSpeedService()
{
    delete this->_state;
}

/// @brief  	sends the windspeed.
/// @details	sends the data gotten from this to displaywindspeed.
void WindSpeedService::doService() {
    this->_state->doService();
}

/// @brief  	gets the current windspeed.
/// @details	gets the windspeed at the current time from the API.
void WindSpeedService::currentDataService(){

    QJsonObject json = interface->APICall();

    QJsonObject mainJson = json["wind"].toObject();

    QJsonValue jwind = mainJson["speed"];

    double windSpeed = jwind.toDouble();

    data->setCurrentWindSpeed(windSpeed);
}

/// @brief  	gets the windspeed over the next 24 hours.
/// @details	gets the windspeed for each hour over the next 24 hours from the API.
void WindSpeedService::twentyFourHourDataService(){
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<double> hourlyWind;


    for (int i = 0; i < 8; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonObject valobjWind = obj["wind"].toObject();
        QJsonValue jWind = valobjWind["speed"];

        double wind = jWind.toDouble();
        hourlyWind.append(wind);
    }

    data->setTwentyFourWindSpeed(hourlyWind);

}

/// @brief  	gets the windspeed over the next 4 days.
/// @details	gets the windspeed for each day over the next 4 days from the API.
void WindSpeedService::fourDayDataService(){

    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<int> hourlyWind;


    for (int i = 0; i < 40; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonObject valobjWind = obj["wind"].toObject();
        QJsonValue jWind = valobjWind["speed"];

        int cloud = jWind.toDouble();
        hourlyWind.append(cloud);
    }

    QVector<double> vec;

    for (int i = 0; i < 5; i++) {
        double sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += hourlyWind[i*8 + j];
        }
        vec.append(sum / 8);
    }


    data->setFourDayWindSpeed(vec);

}
