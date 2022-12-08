#include "cloudcoverageservice.h"
#include <QJsonArray>>

/// @brief	    CloudCoverageService is used to access the API data for cloud coverage and send it to our handling functions.
/// @details    CloudCoverageService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
CloudCoverageService::CloudCoverageService()
{
}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
CloudCoverageService::~CloudCoverageService()
{
    delete this->_state;
}

/// @brief  	sends the cloud coverage.
/// @details	sends the data gotten from this to displayCloudCoverage.
void CloudCoverageService::doService()
{
    this->_state->doService();
}

/// @brief  	gets the current cloud coverage.
/// @details	gets the cloud coverage at the current time from the API.
void CloudCoverageService::currentDataService()
{

    QJsonObject json = interface->APICall();

    QJsonObject mainJson = json["clouds"].toObject();

    QJsonValue jCloud = mainJson["all"];

    int cloudCoverage = jCloud.toInt();

    data->setCurrentCloudCoverage(cloudCoverage);
}
/// @brief  	gets the cloud coverage over the next 24 hours.
/// @details	gets the cloud coverage for each hour over the next 24 hours from the API.
void CloudCoverageService::twentyFourHourDataService()
{
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<int> hourlyCloud;


    for (int i = 0; i < 8; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["clouds"].toObject();
        QJsonValue jCloud = valobj["all"];

        int cloud = jCloud.toInt();
        hourlyCloud.append(cloud);
    }

    data->setTwentyFourCloudCoverage(hourlyCloud);

}

/// @brief  	gets the cloud coverage over the next 4 days.
/// @details	gets the cloud coverage for each day over the next 4 days from the API.
void CloudCoverageService::fourDayDataService(){
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<int> hourlyCloud;


    for (int i = 0; i < 40; i++) {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonObject valobjClouds = obj["clouds"].toObject();
        QJsonValue jCloud = valobjClouds["all"];

        int cloud = jCloud.toInt();
        hourlyCloud.append(cloud);
    }

    QVector<int> vec;

    for (int i = 0; i < 5; i++) {
        double sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += hourlyCloud[i*8 + j];
        }
        vec.append(sum / 8);
    }
    data->setFourDayCloudCoverage(vec);

}
