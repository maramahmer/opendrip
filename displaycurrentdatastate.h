#ifndef WEATHERDATA_DISPLAYCURRENTDATASTATE_H
#define WEATHERDATA_DISPLAYCURRENTDATASTATE_H

#include "displaystate.h"
#include "userinterfacing.h"

class DisplayCurrentDataState : public DisplayState{
public:
    DisplayCurrentDataState();
    ~DisplayCurrentDataState();
    virtual void display();
};


#endif //WEATHERDATA_DISPLAYCURRENTDATASTATE_H
