#include "displaywindspeed.h"
#include "ui_opendrip.h"

/// @brief	    displaywindspeed is used to display data from windspeedservice.
/// @details    displaywindspeed has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayWindSpeed::DisplayWindSpeed() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
DisplayWindSpeed::~DisplayWindSpeed() {
    delete this->_state;
}

/// @brief  	sends the wind speed.
/// @details	sends the display gotten from this to computation.
void DisplayWindSpeed::display(){
    this->_state->display();
}

/// @brief  	displays the current wind speed.
/// @details	gets the display for the wind speed at the current time.
void DisplayWindSpeed::displayCurrentData() {
    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 3),(QVariant(data->getCurrentWindSpeed()).toString()));
}

/// @brief  	displays the wind speed over the next 4 days.
/// @details	gets the display for the wind speed over the next 4 days.
void DisplayWindSpeed::display4DayData() {
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 3),(QVariant(data->getFourDayWindSpeed()[i]).toString()));
    }
}

/// @brief  	displays the wind speed over the next 24 hours.
/// @details	gets the display for the wind speed over the next 24 hours.
void DisplayWindSpeed::display24HoursData() {
    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 3),(QVariant(data->getTwentyFourWindSpeed()[i]).toString()));
    }
}
