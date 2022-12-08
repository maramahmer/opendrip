#ifndef WEATHERDATA_FOURDAYDATASERVICESTATE_H
#define WEATHERDATA_FOURDAYDATASERVICESTATE_H
#include "dataservicestate.h"
#include "dataservice.h"

class FourDayDataServiceState : public DataServiceState{
public:
    FourDayDataServiceState();
    ~FourDayDataServiceState();
    void doService() override;
};


#endif //WEATHERDATA_FOURDAYDATASERVICESTATE_H
