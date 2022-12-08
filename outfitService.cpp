#include "outfitService.h"
#include <QJsonArray>
#include <iostream>

/// @brief	    outfitService is used to check the data for whichever outfit is desired and send it to our handling functions.
/// @details    outfitService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Maram

/// @brief  	constructor.
/// @details	nothing needs to be done here.
OutfitService::OutfitService()
{
}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
OutfitService::~OutfitService()
{
        delete this->_state;
}

/// @brief  	sends the outfit.
/// @details	sends the data gotten from this to displayOutfit.
void OutfitService::doService()
{
    this->_state->doService();
}

/// @brief  	gets the current outfit.
/// @details	gets the outfit at the current time from the API.
void OutfitService::currentDataService()
{

    QJsonObject json = interface->APICall();

    QJsonObject mainJson = json["main"].toObject();

    QJsonValue jTemp = mainJson["temp"];

    double temp = jTemp.toDouble();

    if (temp > 27)
    {
        data->setCurrentOutfit("A t-shirt and shorts");
    }
    else if (temp < 26 && temp >= 18)
    {
        data->setCurrentOutfit("A t-shirt and pants");
    }
    else if (temp < 17 && temp >= 0)
    {
        data->setCurrentOutfit("A long sleeve shirt and pants");
    }
    else if (temp < 0)
    {
        data->setCurrentOutfit("A sweater and warm pants");
    }
}

/// @brief  	gets the outfits over the next 24 hours.
/// @details	gets the outfits for each hour over the next 24 hours from the API.
void OutfitService::twentyFourHourDataService()
{

    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<QString> hourlyOutfit;

    for (int i = 0; i < 8; i++)
    {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jTemp = valobj["temp"];

        int temp = jTemp.toDouble();
        if (req->getRequestedTemperatureType() == 'f')
        {
            temp = temp * (9.0 / 5.0) + 32;
        }
        if (temp > 27)
        {
            hourlyOutfit.append("A t-shirt and shorts");
        }
        else if (temp < 26 && temp >= 18)
        {
            hourlyOutfit.append("A t-shirt and pants");
        }
        else if (temp < 17 && temp >= 0)
        {
            hourlyOutfit.append("A long sleeve shirt and pants");
        }
        else if (temp < 0)
        {
            hourlyOutfit.append("A sweater and warm pants");
        }
    }

    data->setTwentyFourOutfit(hourlyOutfit);
}

/// @brief  	gets the outfits over the next 4 days.
/// @details	gets the outfits for each day over the next 4 days from the API.
void OutfitService::fourDayDataService()
{
    QJsonObject json = interface->APICall();

    QJsonArray list = json["list"].toArray();
    QVector<QString> clothesDays;

    QVector<double> hourlyTemp;
    for (int i = 0; i < 40; i++)
    {
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jTemp = valobj["temp"];

        double temp = jTemp.toDouble();
        hourlyTemp.append(temp);
    }

    double temp = 0;
    for (int i = 0; i < 5; i++)
    {
        double sum = 0;
        for (int j = 0; j < 8; j++)
        {
            sum += hourlyTemp[i * 8 + j];
        }
        temp = sum / 8;
        if (temp > 27)
        {
            clothesDays.append("A t-shirt and shorts");
        }
        else if (temp < 26 && temp >= 18)
        {
            clothesDays.append("A t-shirt and pants");
        }
        else if (temp < 17 && temp >= 0)
        {
            clothesDays.append("A long sleeve shirt and pants");
        }
        else if (temp < 0)
        {
            clothesDays.append("A sweater and warm pants");
        }
    }

    data->setFourDayOutfit(clothesDays);
}
