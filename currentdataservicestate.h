
#ifndef WEATHERDATA_CURRENTDATASERVICESTATE_H
#define WEATHERDATA_CURRENTDATASERVICESTATE_H

#include "dataservicestate.h"
#include "dataservice.h"

class CurrentDataServiceState: public DataServiceState{
public:
    CurrentDataServiceState();
    ~CurrentDataServiceState();
    void doService();
};


#endif //WEATHERDATA_CURRENTDATASERVICESTATE_H
