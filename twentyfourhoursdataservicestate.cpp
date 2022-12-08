#include "twentyfourhoursdataservicestate.h"
/// @brief	    Gets the data over the next 24 hours.
/// @details    processes the service over the next 24 hours.
///		- doService
/// @authors	Soren, Ali

/// @brief  	constructor.
/// @details    nothing needs constructing.
TwentyFourHoursDataServiceState::TwentyFourHoursDataServiceState(): DataServiceState(){

}

TwentyFourHoursDataServiceState::~TwentyFourHoursDataServiceState() {

}


/// @brief  	processes the service.
/// @details    gets the data for whichever service is active over the next 24 hours.
void TwentyFourHoursDataServiceState::doService() {
    this->_dataService->twentyFourHourDataService();
}
