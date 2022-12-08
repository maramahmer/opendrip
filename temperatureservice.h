#ifndef TEMPERATURESERVICE_H
#define TEMPERATURESERVICE_H

#include "dataservice.h"

class TemperatureService : public DataService
{
public:
    TemperatureService();
    ~TemperatureService();
    void doService();
    void currentDataService();
    void twentyFourHourDataService();
    void fourDayDataService();
};

#endif // TEMPERATURESERVICE_H
