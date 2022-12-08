#include "displayprecipitation.h"
#include "weatherData.h"
#include <iostream>
#include "ui_opendrip.h"

/// @brief	    displayprecipitation is used to display data from precipitationservice.
/// @details    displayprecipitation has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayPrecipitation::DisplayPrecipitation() {

}

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayPrecipitation::~DisplayPrecipitation() {
    delete this->_state;
}

/// @brief  	sends the precipitation.
/// @details	sends the display gotten from this to computation.
void DisplayPrecipitation::display(){
    this->_state->display();
}

/// @brief  	displays the current precipitation.
/// @details	gets the display for the precipitation at the current time.
void DisplayPrecipitation::displayCurrentData() {

    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 4),(QVariant(data->getCurrentPrecipitation()).toString()));
}

/// @brief  	displays the precipitation over the next 4 days.
/// @details	gets the display for the precipitation over the next 4 days.
void DisplayPrecipitation::display4DayData() {
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 4),(QVariant(data->getFourDayPrecipitation()[i]).toString()));
    }
}

/// @brief  	displays the precipitation over the next 24 hours.
/// @details	gets the display for the precipitation over the next 24 hours.
void DisplayPrecipitation::display24HoursData() {
    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 4),(QVariant(data->getTwentyFourPrecipitation()[i]).toString()));
    }
}
