#ifndef DISPLAYTEMPERATURE_H
#define DISPLAYTEMPERATURE_H

#include "userinterfacing.h"
#include <iostream>


class DisplayTemperature : public UserInterfacing {
public:
    DisplayTemperature();
    ~DisplayTemperature();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYTEMPERATURE_H
