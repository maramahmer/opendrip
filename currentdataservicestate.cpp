#include "currentdataservicestate.h"
#include <iostream>
/// @brief	    Gets the data currently.
/// @details    processes the service for the current time.
///		- doService
/// @authors	Soren, Ali

/// @brief  	constructor.
/// @details    nothing needs constructing.
CurrentDataServiceState::CurrentDataServiceState() {

}

/// @brief  	destructor.
/// @details    nothing needs deconstructing.
CurrentDataServiceState::~CurrentDataServiceState() {

}

/// @brief  	processes the service.
/// @details    gets the data for whichever service is active for the current time.
void CurrentDataServiceState::doService() {

    this->_dataService->currentDataService();
}
