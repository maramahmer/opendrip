#ifndef USERINTERFACING_H
#define USERINTERFACING_H

#include "displaystate.h"
#include "weatherData.h"
#include "opendrip.h"

class UserInterfacing
{
public:
    UserInterfacing();
    virtual ~UserInterfacing() = 0;
    virtual void display() = 0;
    virtual void displayCurrentData() = 0;
    virtual void display4DayData() = 0;
    virtual void display24HoursData() = 0;
    void setState(DisplayState* state);
    void setWeatherData(WeatherData *data);
    void setUI(Ui::OpenDrip *UI);

protected:
    DisplayState* _state;
    WeatherData* data;
    Ui::OpenDrip *UI;
};

#endif // USERINTERFACING_H
