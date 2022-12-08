#include "display4daysdatastate.h"
/// @brief	    Displays over the next 4 days.
/// @details    displays any service over the next 4 days.
///		- display
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details    nothing needs constructing.
Display4DaysDataState::Display4DaysDataState(): DisplayState() {

}

Display4DaysDataState::~Display4DaysDataState() {

}

/// @brief  	displays the state.
/// @details    displays whichever service is active over the next 4 days.
void Display4DaysDataState::display() {
    this->_userInterfacing->display4DayData();
}
