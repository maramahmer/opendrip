#include "displaystate.h"
/// @brief	    Parent for all time displays.
/// @details    this includes current, 24 hour, and 4 day.
///		- display
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details    nothing needs constructing.
DisplayState::DisplayState() {

}

/// @brief  	deconstructor.
/// @details    nothing needs deconstructing.
DisplayState::~DisplayState() {

}

/// @brief      sets the service input by the user.
/// @details    takes given input and applies the display for it.
/// @param      userInterfacing is the desired service to display as a type UserInterfacing.
void DisplayState::setUserInterfacing(UserInterfacing *userInterfacing){
    _userInterfacing = userInterfacing;
}

