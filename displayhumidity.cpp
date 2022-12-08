#include "displayhumidity.h"
#include "ui_opendrip.h"
#include "weatherData.h"
#include <iostream>

/// @brief	    displayhumidity is used to display data from humidityservice.
/// @details    displayhumidity has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayHumidity::DisplayHumidity() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
 DisplayHumidity::~DisplayHumidity() {
    delete this->_state;
 }

/// @brief  	sends the humidity.
/// @details	sends the display gotten from this to computation.
void DisplayHumidity::display(){
    this->_state->display();
}

/// @brief  	displays the current humidity.
/// @details	gets the display for the humidity at the current time.
void DisplayHumidity::displayCurrentData() {
    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 1),(QVariant(data->getCurrentHumidity()).toString()));
}

/// @brief  	displays the humidity over the next 4 days.
/// @details	gets the display for the humidity over the next 4 days.
void DisplayHumidity::display4DayData() {
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 1),(QVariant(data->getFourDayHumidity()[i]).toString()));
    }

}

/// @brief  	displays the humidity over the next 24 hours.
/// @details	gets the display for the humidity over the next 24 hours.
void DisplayHumidity::display24HoursData() {
    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 1),(QVariant(data->getTwentyFourHumidity()[i]).toString()));
    }
}
