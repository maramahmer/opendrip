#ifndef HUMIDITYSERVICE_H
#define HUMIDITYSERVICE_H

#include "dataservice.h"

class HumidityService: public DataService {
    public:
        HumidityService();
        ~HumidityService();
        virtual void doService();
        virtual void currentDataService();
        virtual void twentyFourHourDataService();
        virtual void fourDayDataService();

};

#endif // HUMIDITYSERVICE_H
