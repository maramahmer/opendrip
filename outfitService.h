#ifndef GROUP4_OUTFITSERVICE_H
#define GROUP4_OUTFITSERVICE_H

#include "dataservice.h"

class OutfitService : public DataService {
    public:
        OutfitService();
        ~OutfitService();
        void doService();
        void currentDataService();
        void twentyFourHourDataService();
        void fourDayDataService();
};


#endif //GROUP4_OUTFITSERVICE_H
