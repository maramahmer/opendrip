#include "dataservice.h"
/// @brief	    Dataservice is the interface between the individual services and the factory.
/// @details    gets the data for all the other classes with the functions:
///		- setState
///		- setUserRequest
///		- setWeatherData
///		- setWeatherInterface
/// @authors	Soren, Ali

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DataService::DataService() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
DataService::~DataService() {

}

/// @brief  	sets a state.
/// @details	The state set is based on the user request.
/// @param      state given from user.
void DataService::setState(DataServiceState* state) {
    this->_state = state;
}

/// @brief  	sets the user request.
/// @details	sets it to the given parameter from main.
/// @param      req is the user request. 
void DataService::setUserRequest(UserRequest *req) {
    this->req = req;
}

/// @brief  	sets weather data.
/// @details	sets the weather data to the parameter from main.
/// @param      data is the weather data to be set.
void DataService::setWeatherData(WeatherData *data) {
    this->data = data;
}

/// @brief  	sets the interface for the weather.
/// @details	sets the interface for use of our program.
/// @param      interface is the given interface to be set to.
void DataService::setWeatherInterface(WeatherInterface *interface) {
    this->interface = interface;
}
