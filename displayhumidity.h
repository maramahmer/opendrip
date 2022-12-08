#ifndef DISPLAYHUMIDITY_H
#define DISPLAYHUMIDITY_H

#include "userinterfacing.h"

class DisplayHumidity : public UserInterfacing
{
public:
    DisplayHumidity();
    ~DisplayHumidity();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYHUMIDITY_H
