#include "dataservicestate.h"
/// @brief	    Interface for the API calls.
/// @details    The interface through which the required API calls are made.
///		- setDataService
/// @authors	Soren, Ali

/// @brief  	constructor.
/// @details    nothing needs constructing.
DataServiceState::DataServiceState() {

}

/// @brief  	deconstructor.
/// @details    nothing needs deconstructing.
DataServiceState::~DataServiceState() {

}

/// @brief  	sets the data service.
/// @details    selects the data service to use.
void DataServiceState::setDataService(DataService *dataService) {
    _dataService = dataService;
}
