#ifndef WEATHERDATA_DISPLAY4DAYSDATA_H
#define WEATHERDATA_DISPLAY4DAYSDATA_H
#include "displaystate.h"
#include "userinterfacing.h"

class Display4DaysDataState : public DisplayState{
public:
    Display4DaysDataState();
    ~Display4DaysDataState();
    virtual void display();
};

#endif //WEATHERDATA_DISPLAY4DAYSDATA_H
