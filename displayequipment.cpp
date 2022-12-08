#include "displayequipment.h"
#include "ui_opendrip.h"

/// @brief	    displayequipment is used to display data from equipmentservice.
/// @details    displayequipment has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Maram

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayEquipment::DisplayEquipment() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
 DisplayEquipment::~DisplayEquipment() {
        delete this->_state;
}

/// @brief  	sends the equipment.
/// @details	sends the display gotten from this to computation.
void DisplayEquipment::display(){
    this->_state->display();
}

/// @brief  	displays the current equipment.
/// @details	gets the display for the equipment at the current time.
void DisplayEquipment::displayCurrentData() {
    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 6),(QVariant(data->getCurrentEquipment()).toString()));
}

/// @brief  	displays the equipment over the next 4 days.
/// @details	gets the display for the equipment over the next 4 days.
void DisplayEquipment::display4DayData() {
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 6),(QVariant(data->getFourDayEquipment()[i]).toString()));
    }
}

/// @brief  	displays the equipment over the next 24 hours.
/// @details	gets the display for the equipment over the next 24 hours.
void DisplayEquipment::display24HoursData() {
    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 6),(QVariant(data->getTwentyFourEquipment()[i]).toString()));
    }
}
