#include "displaycurrentdatastate.h"
/// @brief	    Displays data currently.
/// @details    displays any service at the current moment.
///		- display
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details    nothing needs constructing.
DisplayCurrentDataState::DisplayCurrentDataState() {

}

/// @brief  	deconstructor.
/// @details    nothing needs deconstructing.
DisplayCurrentDataState::~DisplayCurrentDataState() {

}

/// @brief  	displays the state.
/// @details    displays whichever service is active immediately.
void DisplayCurrentDataState::display() {
    this->_userInterfacing->displayCurrentData();
}
