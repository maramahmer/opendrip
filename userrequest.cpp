#include "userrequest.h"

//const UserRequest* UserRequest::_instance = NULL;

/// @brief	    Interface for the API calls.
/// @details    The interface through which the required API calls are made.
///		- getRequestedTemperatureType
///		- setRequestedTemperatureType
///		- getRequestedLocation
///		- setRequestedLocation
///		- getRequestedDuration
///		- setRequestedDuration
///		- getRequestedServices
///		- setRequestedServices
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details    nothing needs constructing.
UserRequest::UserRequest() {
    
}

/// @brief  	deconstructor.
/// @details    nothing needs destructing.
UserRequest::~UserRequest() {
    
}

/// @brief  	gets the temperatures type.
/// @details    retrives either "celsius" or "fahrenheit".
/// @returns    either celsius or farenheit.
const int &UserRequest::getRequestedTemperatureType() const {
    return requestedTemperatureType;
}

/// @brief  	sets the temperatures type.
/// @details    sets the temp to be either "celsius" or "fahrenheit".
/// @param      temperatureType should be either celsius or farenheit converted to QString.
void UserRequest::setRequestedTemperatureType(const int &temperatureType) {
    requestedTemperatureType = temperatureType;
}

/// @brief  	gets the location.
/// @details    retrives the inputted location.
/// @returns    the location inputted.
const QString &UserRequest::getRequestedLocation() const {
    return requestedLocation;
}

/// @brief  	sets the location.
/// @details    applies the inputted location.
/// @param      requestedLocation the location inputted.
void UserRequest::setRequestedLocation(const QString &requestedLocation) {
    this->requestedLocation = requestedLocation;
}

/// @brief  	gets the duration.
/// @details    retrives the desired duration.
/// @returns    the duration desired.
const QString &UserRequest::getRequestedDuration() const {
    return requestedDuration;
}

/// @brief  	sets the duration.
/// @details    applies the given duration.
/// @param      requestedDuration is the duration to set.
void UserRequest::setRequestedDuration(const QString &requestedDuration) {
    this->requestedDuration = requestedDuration;
}

/// @brief  	gets the desired services.
/// @details    retrives the given services.
/// @returns    the desired services.
const QVector<QString> &UserRequest::getRequestedServices() const {
    return requestedServices;
}

/// @brief  	sets the desired services.
/// @details    applies the desired services.
/// @param      requestedServices applies the desired services.
void UserRequest::setRequestedServices(const QVector<QString> &requestedServices) {
    this->requestedServices = requestedServices;
}


