#include "display24hoursdatastate.h"
/// @brief	    Displays over the next 24 hours.
/// @details    displays any service over the next 24 hours.
///		- display
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details    nothing needs constructing.
Display24HoursDataState::Display24HoursDataState(): DisplayState() {

}

Display24HoursDataState::~Display24HoursDataState() {

}


/// @brief  	displays the state.
/// @details    displays whichever service is active over the next 24 hours.
void Display24HoursDataState::display() {
    this->_userInterfacing->display24HoursData();
}
