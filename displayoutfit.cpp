#include "displayoutfit.h"
#include "ui_opendrip.h"
/// @brief	    displayoutfit is used to display data from outfitservice.
/// @details    displayoutfit has the following functions which pass parameters to computation:
///		- display
///		- displayCurrentData
///		- display4DayData
///		- display24HoursData
/// @authors	Soren, Ali, Maram

/// @brief  	constructor.
/// @details	nothing needs to be done here.
DisplayOutfit::DisplayOutfit() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
DisplayOutfit::~DisplayOutfit() {
    delete this->_state;
}

/// @brief  	sends the outfit.
/// @details	sends the display gotten from this to computation.
void DisplayOutfit::display(){
    this->_state->display();
}

/// @brief  	displays the current outfit.
/// @details	gets the display for the outfit at the current time.
void DisplayOutfit::displayCurrentData() {
    auto model = UI->HourlyForecast->model();
    model->setData(model->index(0, 5),(QVariant(data->getCurrentOutfit()).toString()));
}

/// @brief  	displays the outfit over the next 4 days.
/// @details	gets the display for the outfit over the next 4 days.
void DisplayOutfit::display4DayData() {
//    for(int i = 0; i < 4; i ++){
//        UI->OutfitPlaceholder1->setText(data->getFourDayOutfit()[i]);
//    }
    for(int i = 0; i < 4; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 5),(QVariant(data->getFourDayOutfit()[i]).toString()));
    }
}

/// @brief  	displays the outfit over the next 24 hours.
/// @details	gets the display for the outfit over the next 24 hours.
void DisplayOutfit::display24HoursData() {
//    for(int i = 0; i < 8; i ++){
//        UI->OutfitPlaceholder1->setText(data->getTwentyFourOutfit()[i]);
//    }
    for(int i = 0; i < 8; i ++){
        auto model = UI->HourlyForecast->model();
        model->setData(model->index(i, 5),(QVariant(data->getTwentyFourOutfit()[i]).toString()));
    }
}
