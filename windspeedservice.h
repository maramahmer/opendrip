#ifndef WINDSPEEDSERVICE_H
#define WINDSPEEDSERVICE_H

#include "dataservice.h"

class WindSpeedService : public DataService
{
public:
    WindSpeedService();
    ~WindSpeedService();
    void doService();
    void currentDataService();
    void twentyFourHourDataService();
    void fourDayDataService();
};

#endif // WINDSPEEDSERVICE_H
