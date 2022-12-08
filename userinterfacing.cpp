#include "userinterfacing.h"

UserInterfacing::UserInterfacing() {
}

UserInterfacing::~UserInterfacing() {

}


void UserInterfacing::setState(DisplayState *state) {
    this->_state = state;
}

void UserInterfacing::setWeatherData(WeatherData *data) {
    this->data = data;
}

void UserInterfacing::setUI(Ui::OpenDrip *UI) {
    this->UI = UI;
}
