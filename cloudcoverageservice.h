#ifndef CLOUDCOVERAGESERVICE_H
#define CLOUDCOVERAGESERVICE_H

#include "dataservice.h"


class CloudCoverageService : public DataService {
public:
    CloudCoverageService();
    ~CloudCoverageService();
    void doService();
    void currentDataService();
    void twentyFourHourDataService();
    void fourDayDataService();
};

#endif // CLOUDCOVERAGESERVICE_H
