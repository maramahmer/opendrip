#ifndef DISPLAYEQUIPMENT_H
#define DISPLAYEQUIPMENT_H

#include "userinterfacing.h"
#include <iostream>

class DisplayEquipment : public UserInterfacing {
public:
    DisplayEquipment();
    ~DisplayEquipment();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYEQUIPMENT_H
