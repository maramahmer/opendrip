#ifndef WEATHERDATA_DISPLAY24HOURSDATA_H
#define WEATHERDATA_DISPLAY24HOURSDATA_H

#include "displaystate.h"
#include "userinterfacing.h"


class Display24HoursDataState : public DisplayState{
public:
    Display24HoursDataState();
    ~Display24HoursDataState();
    virtual void display();
};


#endif //WEATHERDATA_DISPLAY24HOURSDATA_H
