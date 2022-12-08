#include "fourdaydataservicestate.h"
/// @brief	    Gets the data over the next 4 days.
/// @details    processes the service over the next 4 days.
///		- doService
/// @authors	Soren, Ali

/// @brief  	constructor.
/// @details    nothing needs constructing.
FourDayDataServiceState::FourDayDataServiceState(): DataServiceState() {

}

FourDayDataServiceState::~FourDayDataServiceState() {

}

/// @brief  	processes the service.
/// @details    gets the data for whichever service is active over the next 4 days.
void FourDayDataServiceState::doService() {
    this->_dataService->fourDayDataService();
}
