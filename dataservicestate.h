#ifndef WEATHERDATA_DATASERVICESTATE_H
#define WEATHERDATA_DATASERVICESTATE_H



class DataService;
class DataServiceState {
protected:
    DataService* _dataService;
public:
    DataServiceState();
    virtual ~DataServiceState() = 0;
    virtual void doService() = 0;
    void setDataService(DataService *dataService);
};


#endif //WEATHERDATA_DATASERVICESTATE_H
