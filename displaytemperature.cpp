#include "displaytemperature.h"
#include "ui_opendrip.h"
/// @brief	    displaytemperature is used to display data from temperatureservice.
/// @details    displaytemperature has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayTemperature::DisplayTemperature() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
DisplayTemperature::~DisplayTemperature() {
    delete this->_state;
}

/// @brief  	sends the temperature.
/// @details	sends the display gotten from this to computation.
void DisplayTemperature::display(){
    this->_state->display();
}

/// @brief  	displays the current temperature.
/// @details	gets the display for the temperature at the current time.
void DisplayTemperature::displayCurrentData() {
    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 0),(QVariant(data->getCurrentTemperature()).toString()));

}

/// @brief  	displays the temperature over the next 4 days.
/// @details	gets the display for the temperature over the next 4 days.
void DisplayTemperature::display4DayData() {
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 0),(QVariant(data->getFourDayTemperature()[i]).toString()));
    }

}

/// @brief  	displays the temperature over the next 24 hours.
/// @details	gets the display for the temperature over the next 24 hours.
void DisplayTemperature::display24HoursData() {
    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 0),(QVariant(data->getTwentyFourTemperature()[i]).toString()));
    }
}
