#include "weatherinterface.h"
#include "userrequest.h"
#include <QJsonDocument>
#include <iostream>
/// @brief	    Interface for the API calls.
/// @details    The interface through which the required API calls are made.
///		- APICall
/// @authors	Soren, Ali, Maram


const QString WeatherInterface::APIKey  = "a461401fccc587d20db509d13040afc6";

bool WeatherInterface::isAPICalled = false;

/// @brief  	constructor.
/// @details    gets the requested location and displays it.
/// @param      req is the location to initially display the weather for.
WeatherInterface::WeatherInterface(UserRequest req) {
    location = req.getRequestedLocation();
    duration = req.getRequestedDuration();

}

/// @brief  	deconstructor.
/// @details    nothing needs destructing.
WeatherInterface::~WeatherInterface() {

}

/// @brief      makes the API call
/// @details    Makes the API call through the OpenWeatherMap API.
/// @returns    the object that the API finds as a JSON
const QJsonObject WeatherInterface::APICall(){

    if (WeatherInterface::isAPICalled) return WeatherInterface::json;
    manager = new QNetworkAccessManager();
    loop.connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    isAPICalled = true;
    QString current_str = "https://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=70cf83ee366b48f9956387131e7b4de8";
    QString forcast_str = "https://api.openweathermap.org/data/2.5/forecast?q=" + location + "&appid=70cf83ee366b48f9956387131e7b4de8";
    QUrl currentWeatherUrl = QUrl(current_str);
    QUrl forcastUrl = QUrl(forcast_str);
    QNetworkReply *dataReply;
    if (duration == "current") {
        dataReply = manager->get(QNetworkRequest(currentWeatherUrl));
    }
    else {
        dataReply = manager->get(QNetworkRequest(forcastUrl));
    }


    loop.exec();

    QString data = dataReply->readAll();


    QJsonObject jsonResponse = QJsonDocument::fromJson(data.toUtf8()).object();


    dataReply->deleteLater();

    time_t currTime;
    time(&currTime);
    this->json = jsonResponse;

    return jsonResponse;

    return jsonResponse;

}
