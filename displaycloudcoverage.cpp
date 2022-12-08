#include "displaycloudcoverage.h"
#include "ui_opendrip.h"

/// @brief	    displaycloudcoverage is used to display data from cloudcoverageservice.
/// @details    displaycloudcoverage has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayCloudCoverage::DisplayCloudCoverage()
{

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
DisplayCloudCoverage::~DisplayCloudCoverage()
{
    delete this->_state;
}

/// @brief  	sends the cloud coverage.
/// @details	sends the display gotten from this to computation.
void DisplayCloudCoverage::display(){
    this->_state->display();
}

/// @brief  	displays the current cloud coverage.
/// @details	gets the display for the cloud coverage at the current time.
void DisplayCloudCoverage::displayCurrentData() {

    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 2),(QVariant(data->getCurrentCloudCoverage()).toString()));
}

/// @brief  	displays the cloud coverage over the next 4 days.
/// @details	gets the display for the cloud coverage over the next 4 days.
void DisplayCloudCoverage::display4DayData() {
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 2),(QVariant(data->getFourDayCloudCoverage()[i]).toString()));
    }
}

/// @brief  	displays the cloud coverage over the next 24 hours.
/// @details	gets the display for the cloud coverage over the next 24 hours.
void DisplayCloudCoverage::display24HoursData() {

    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 2),(QVariant(data->getTwentyFourCloudCoverage()[i]).toString()));
    }
}
