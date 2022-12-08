#include <weatherData.h>
/// @brief
/// @details
///		- getCurrentActivity
///     - setCurrentActivity
///     - getTwentyFourActivity
///     - setTwentyFourActivity
///     - getFourDayActivity
///     - setFourDayActivity
///     - getCurrentCloudCoverage
///		- setCurrentCloudCoverage
///     - getTwentyFourCloudCoverage
///     - setTwentyFourCloudCoverage
///     - getFourDayCloudCoverage
///     - setFourDayCloudCoverage
///     - getCurrentEquipment
///     - setCurrentEquipment
///     - getTwentyFourEquipment
///     - setTwentyFourEquipment
///     - getFourDayEquipment
///     - setFourDayEquipment
///     - getCurrentHumidity
///     - setCurrentHumidity
///     - getTwentyFourHumidity
///     - setTwentyFourHumidity
///     - getFourDayHumidity
///     - setFourDayHumidity
///     - getCurrentOutfit
///     - setCurrentOutfit
///     - getTwentyFourOutfit
///     - setTwentyFourOutfit
///     - getFourDayOutfit
///     - setFourDayOutfit
///     - getCurrentPrecipitation
///     - setCurrentPrecipitation
///     - getTwentyFourPrecipitation
///     - setTwentyFourPrecipitation
///     - getFourDayPrecipitation
///     - setFourDayPrecipitation
///     - getCurrentTemperature
///     - setCurrentTemperature
///     - getTwentyFourTemperature
///     - setTwentyFourTemperature
///     - getFourDayTemperature
///     - setFourDayTemperature
///     - getCurrentWindSpeed
///     - setCurrentWindSpeed
///     - getTwentyFourWindSpeed
///     - setTwentyFourWindSpeed
///     - getFourDayWindSpeed
///     - setFourDayWindSpeed

/// @authors	Soren, Ali, Maram, Arnav

/// @brief  	constructor.
/// @details    intentionally left blank, nothing to contstruct.
WeatherData::WeatherData() {}

/// @brief  	deconstructor.
/// @details    in the same vein, nothing to destruct.
WeatherData::~WeatherData() {}

/// @brief  	gets current activity.
/// @details    gets the activity for the current time period.
/// @returns    QString for the activity.
const QString &WeatherData::getCurrentActivity() const
{
    return currentActivity;
}

/// @brief  	sets current activity.
/// @details    sets the activity for the current time period.
/// @param      QString for the activity.
void WeatherData::setCurrentActivity(const QString &currentActivity)
{
    WeatherData::currentActivity = currentActivity;
}

/// @brief  	gets 24 hour activites.
/// @details    gets the activites over the next 24 hours.
/// @returns    QStrings for the activity.
const QVector<QString> &WeatherData::getTwentyFourActivity() const
{
    return twentyFourActivity;
}

/// @brief  	sets 24 hour activites.
/// @details    sets the activites over the next 24 hours.
/// @param      QStrings for the activity.
void WeatherData::setTwentyFourActivity(const QVector<QString> &twentyFourActivity)
{
    WeatherData::twentyFourActivity = twentyFourActivity;
}

/// @brief  	gets 4 days activites.
/// @details    gets the activites over the next 4 days.
/// @returns    QStrings for the activity.
const QVector<QString> &WeatherData::getFourDayActivity() const
{
    return fourDayActivity;
}

/// @brief  	sets 24 hour activites.
/// @details    sets the activites over the next 24 hours.
/// @param      QStrings for the activity.
void WeatherData::setFourDayActivity(const QVector<QString> &fourDayActivity)
{
    WeatherData::fourDayActivity = fourDayActivity;
}

/// @brief  	gets the current cloud coverage.
/// @details    gets the cloud coverage for the current time.
/// @returns    QStrings for the cloud coverage.
int WeatherData::getCurrentCloudCoverage() const
{
    return currentCloudCoverage;
}

/// @brief  	sets the current cloud coverage.
/// @details    sets the cloud coverage for the current time.
/// @param      QStrings for the cloud coverage.
void WeatherData::setCurrentCloudCoverage(int currentCloudCoverage)
{
    WeatherData::currentCloudCoverage = currentCloudCoverage;
}
/// @brief  	gets 24 hour cloud coverage.
/// @details    gets the cloud coverage over the next 24 hours.
/// @returns    QStrings for the cloud coverage.
const QVector<int> &WeatherData::getTwentyFourCloudCoverage() const
{
    return twentyFourCloudCoverage;
}
/// @brief  	sets 24 hour cloud coverage.
/// @details    sets the cloud coverage over the next 24 hours.
/// @param      QStrings for the cloud coverage.
void WeatherData::setTwentyFourCloudCoverage(const QVector<int> &twentyFourCloudCoverage)
{
    WeatherData::twentyFourCloudCoverage = twentyFourCloudCoverage;
}
/// @brief  	gets 4 days cloud coverage.
/// @details    gets the cloud coverage over the next 4 days.
/// @returns    QStrings for the cloud coverage.
const QVector<int> &WeatherData::getFourDayCloudCoverage() const
{
    return fourDayCloudCoverage;
}
/// @brief  	sets 4 days cloud coverage.
/// @details    sets the cloud coverage over the next 4 days.
/// @param      QStrings for the cloud coverage.
void WeatherData::setFourDayCloudCoverage(const QVector<int> &fourDayCloudCoverage)
{
    WeatherData::fourDayCloudCoverage = fourDayCloudCoverage;
}
/// @brief  	gets the current equipment.
/// @details    gets the equipment for the current time.
/// @returns    QStrings for the equipment.
const QString &WeatherData::getCurrentEquipment() const
{
    return currentEquipment;
}
/// @brief  	sets the current equipment.
/// @details    sets the equipment for the current time.
/// @param      QStrings for the equipment.
void WeatherData::setCurrentEquipment(const QString &currentEquipment)
{
    WeatherData::currentEquipment = currentEquipment;
}
/// @brief  	gets 24 hour equipment.
/// @details    gets the equipment over the next 24 hours.
/// @returns    QStrings for the equipment.
const QVector<QString> &WeatherData::getTwentyFourEquipment() const
{
    return twentyFourEquipment;
}
/// @brief  	sets 24 hour equipment.
/// @details    sets the equipment over the next 24 hours.
/// @param      QStrings for the equipment.
void WeatherData::setTwentyFourEquipment(const QVector<QString> &twentyFourEquipment)
{
    WeatherData::twentyFourEquipment = twentyFourEquipment;
}
/// @brief  	gets 4 days equipment.
/// @details    gets the equipment over the next 4 days.
/// @returns    QStrings for the equipment.
const QVector<QString> &WeatherData::getFourDayEquipment() const
{
    return fourDayEquipment;
}
/// @brief  	sets 4 days equipment.
/// @details    sets the equipment over the next 4 days.
/// @param      QStrings for the equipment.
void WeatherData::setFourDayEquipment(const QVector<QString> &fourDayEquipment)
{
    WeatherData::fourDayEquipment = fourDayEquipment;
}
/// @brief  	gets the current humidity.
/// @details    gets the humidity for the current time.
/// @returns    QStrings for the humidity.
int WeatherData::getCurrentHumidity() const
{
    return currentHumidity;
}
/// @brief  	sets the current humidity.
/// @details    sets the humidity for the current time.
/// @param      QStrings for the humidity.
void WeatherData::setCurrentHumidity(int currentHumidity)
{
    WeatherData::currentHumidity = currentHumidity;
}
/// @brief  	gets 24 hour humidity.
/// @details    gets the humidity over the next 24 hours.
/// @returns    QStrings for the humidity.
const QVector<int> &WeatherData::getTwentyFourHumidity() const
{
    return twentyFourHumidity;
}
/// @brief  	sets 24 hour humidity.
/// @details    sets the humidity over the next 24 hours.
/// @param      QStrings for the humidity.
void WeatherData::setTwentyFourHumidity(const QVector<int> &twentyFourHumidity)
{
    WeatherData::twentyFourHumidity = twentyFourHumidity;
}
/// @brief  	gets 4 days humidity.
/// @details    gets the humidity over the next 4 days.
/// @returns    QStrings for the humidity.
const QVector<int> &WeatherData::getFourDayHumidity() const
{
    return fourDayHumidity;
}
/// @brief  	sets 4 days humidity.
/// @details    sets the humidity over the next 4 days.
/// @param      QStrings for the humidity.
void WeatherData::setFourDayHumidity(const QVector<int> &fourDayHumidity)
{
    WeatherData::fourDayHumidity = fourDayHumidity;
}
/// @brief  	gets the current outfit.
/// @details    gets the outfit for the current time.
/// @returns    QStrings for the outfit.
const QString &WeatherData::getCurrentOutfit() const
{
    return currentOutfit;
}
/// @brief  	sets the current outfit.
/// @details    sets the outfit for the current time.
/// @param      QStrings for the outfit.
void WeatherData::setCurrentOutfit(const QString &currentOutfit)
{
    WeatherData::currentOutfit = currentOutfit;
}
/// @brief  	gets 24 hour outfit.
/// @details    gets the outfit over the next 24 hours.
/// @returns    QStrings for the outfit.
const QVector<QString> &WeatherData::getTwentyFourOutfit() const
{
    return twentyFourOutfit;
}
/// @brief  	sets 24 hour outfit.
/// @details    sets the outfit over the next 24 hours.
/// @param      QStrings for the outfit.
void WeatherData::setTwentyFourOutfit(const QVector<QString> &twentyFourOutfit)
{
    WeatherData::twentyFourOutfit = twentyFourOutfit;
}
/// @brief  	gets 4 days outfit.
/// @details    gets the outfit over the next 4 days.
/// @returns    QStrings for the outfit.
const QVector<QString> &WeatherData::getFourDayOutfit() const
{
    return fourDayOutfit;
}
/// @brief  	sets 4 days outfit.
/// @details    sets the outfit over the next 4 days.
/// @param      QStrings for the outfit.
void WeatherData::setFourDayOutfit(const QVector<QString> &fourDayOutfit)
{
    WeatherData::fourDayOutfit = fourDayOutfit;
}
/// @brief  	gets the current precipitation.
/// @details    gets the precipitation for the current time.
/// @returns    QStrings for the precipitation.
QString WeatherData::getCurrentPrecipitation() const
{
    return currentPrecipitation;
}
/// @brief  	sets the current precipitation.
/// @details    sets the precipitation for the current time.
/// @param      QStrings for the precipitation.
void WeatherData::setCurrentPrecipitation(QString currentPrecipitation)
{
    WeatherData::currentPrecipitation = currentPrecipitation;
}
/// @brief  	gets 24 hour precipitation.
/// @details    gets the precipitation over the next 24 hours.
/// @returns    QStrings for the precipitation.
const QVector<QString> &WeatherData::getTwentyFourPrecipitation() const
{
    return twentyFourPrecipitation;
}
/// @brief  	sets 24 hour precipitation.
/// @details    sets the precipitation over the next 24 hours.
/// @param      QStrings for the precipitation.
void WeatherData::setTwentyFourPrecipitation(const QVector<QString> &twentyFourPrecipitation)
{
    WeatherData::twentyFourPrecipitation = twentyFourPrecipitation;
}
/// @brief  	gets 4 days precipitation.
/// @details    gets the precipitation over the next 4 days.
/// @returns    QStrings for the precipitation.
const QVector<QString> &WeatherData::getFourDayPrecipitation() const
{
    return fourDayPrecipitation;
}
/// @brief  	sets 4 days precipitation.
/// @details    sets the precipitation over the next 4 days.
/// @param      QStrings for the precipitation.
void WeatherData::setFourDayPrecipitation(const QVector<QString> &fourDayPrecipitation)
{
    WeatherData::fourDayPrecipitation = fourDayPrecipitation;
}
/// @brief  	gets the current temperature.
/// @details    gets the temperature for the current time.
/// @returns    QStrings for the temperature.
double WeatherData::getCurrentTemperature() const
{
    return currentTemperature;
}
/// @brief  	sets the current temperature.
/// @details    sets the temperature for the current time.
/// @param      QStrings for the temperature.
void WeatherData::setCurrentTemperature(double currentTemperature)
{
    WeatherData::currentTemperature = currentTemperature;
}
/// @brief  	gets 24 hour temperature.
/// @details    gets the temperature over the next 24 hours.
/// @returns    QStrings for the temperature.
const QVector<double> &WeatherData::getTwentyFourTemperature() const
{
    return twentyFourTemperature;
}
/// @brief  	sets 24 hour temperature.
/// @details    sets the temperature over the next 24 hours.
/// @param      QStrings for the temperature.
void WeatherData::setTwentyFourTemperature(const QVector<double> &twentyFourTemperature)
{
    WeatherData::twentyFourTemperature = twentyFourTemperature;
}
/// @brief  	gets 4 days temperature.
/// @details    gets the temperature over the next 4 days.
/// @returns    QStrings for the temperature.
const QVector<double> &WeatherData::getFourDayTemperature() const
{
    return fourDayTemperature;
}
/// @brief  	sets 4 days temperature.
/// @details    sets the temperature over the next 4 days.
/// @param      QStrings for the temperature.
void WeatherData::setFourDayTemperature(const QVector<double> &fourDayTemperature)
{
    WeatherData::fourDayTemperature = fourDayTemperature;
}
/// @brief  	gets the current wind speed.
/// @details    gets the wind speed for the current time.
/// @returns    QStrings for the wind speed.
double WeatherData::getCurrentWindSpeed() const
{
    return currentWindSpeed;
}
/// @brief  	sets the current wind speed.
/// @details    sets the wind speed for the current time.
/// @param      QStrings for the wind speed.
void WeatherData::setCurrentWindSpeed(double currentWindSpeed)
{
    WeatherData::currentWindSpeed = currentWindSpeed;
}
/// @brief  	gets 24 hour wind speed.
/// @details    gets the wind speed over the next 24 hours.
/// @returns    QStrings for the wind speed.
const QVector<double> &WeatherData::getTwentyFourWindSpeed() const
{
    return twentyFourWindSpeed;
}
/// @brief  	sets 24 hour wind speed.
/// @details    sets the wind speed over the next 24 hours.
/// @param      QStrings for the wind speed.
void WeatherData::setTwentyFourWindSpeed(const QVector<double> &twentyFourWindSpeed)
{
    WeatherData::twentyFourWindSpeed = twentyFourWindSpeed;
}
/// @brief  	gets 4 days wind speed.
/// @details    gets the wind speed over the next 4 days.
/// @returns    QStrings for the wind speed.
const QVector<double> &WeatherData::getFourDayWindSpeed() const
{
    return fourDayWindSpeed;
}
/// @brief  	sets 4 days wind speed.
/// @details    sets the wind speed over the next 4 days.
/// @param      QStrings for the wind speed.
void WeatherData::setFourDayWindSpeed(const QVector<double> &fourDayWindSpeed)
{
    WeatherData::fourDayWindSpeed = fourDayWindSpeed;
}
