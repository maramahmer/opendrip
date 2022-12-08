#ifndef WEATHERDATA_TWENTYFOURHOURSDATASERVICESTATE_H
#define WEATHERDATA_TWENTYFOURHOURSDATASERVICESTATE_H
#include "dataservicestate.h"
#include "dataservice.h"

class TwentyFourHoursDataServiceState: public DataServiceState{
public:
    TwentyFourHoursDataServiceState();
    ~TwentyFourHoursDataServiceState();
    virtual void doService();
};


#endif //WEATHERDATA_TWENTYFOURHOURSDATASERVICESTATE_H
