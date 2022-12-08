#ifndef GROUP4_PRECIPITATIONSERVICE_H
#define GROUP4_PRECIPITATIONSERVICE_H
#include "dataservice.h"


class PrecipitationService : public DataService {

public:
    PrecipitationService();
    ~PrecipitationService();
    void doService();
    void currentDataService();
    void twentyFourHourDataService();
    void fourDayDataService();
};


#endif //GROUP4_PRECIPITATIONSERVICE_H
