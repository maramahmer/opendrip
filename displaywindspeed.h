#ifndef DISPLAYWINDSPEED_H
#define DISPLAYWINDSPEED_H

#include "userinterfacing.h"
#include <iostream>


class DisplayWindSpeed : public UserInterfacing {
public:
    DisplayWindSpeed();
    ~DisplayWindSpeed();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYWINDSPEED_H
