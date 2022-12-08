#ifndef DISPLAYOUTFIT_H
#define DISPLAYOUTFIT_H

#include "userinterfacing.h"
#include <iostream>


class DisplayOutfit : public UserInterfacing {
public:
    DisplayOutfit();
    ~DisplayOutfit();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYOUTFIT_H
