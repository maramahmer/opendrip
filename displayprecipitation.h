#ifndef DISPLAYPRECIPITATION_H
#define DISPLAYPRECIPITATION_H

#include "userinterfacing.h"

class DisplayPrecipitation : public UserInterfacing
{
public:
    DisplayPrecipitation();
    ~DisplayPrecipitation();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYPRECIPITATION_H
