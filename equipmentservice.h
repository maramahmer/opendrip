#ifndef EQUIPMENTSERVICE_H
#define EQUIPMENTSERVICE_H

#include "dataservice.h"

class EquipmentService: public DataService
{
public:
    EquipmentService();
    ~EquipmentService();
    void doService();
    void currentDataService();
    void twentyFourHourDataService();
    void fourDayDataService();
};

#endif // EQUIPMENTSERVICE_H
