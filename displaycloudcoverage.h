#ifndef DISPLAYCLOUDCOVERAGE_H
#define DISPLAYCLOUDCOVERAGE_H

#include "userinterfacing.h"
#include <iostream>


class DisplayCloudCoverage : public UserInterfacing {
public:
    DisplayCloudCoverage();
    ~DisplayCloudCoverage();
    virtual void display();
    virtual void displayCurrentData();
    virtual void display4DayData();
    virtual void display24HoursData();
};

#endif // DISPLAYCLOUDCOVERAGE_H
