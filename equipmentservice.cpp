#include "equipmentservice.h"
#include "qjsonarray.h"

/// @brief	    equipmentService is used to access the API data for the equipment and send it to our handling functions.
/// @details    equipmentService has the following functions which pass parameters to computation
///		- doService
///		- currentDataService
///		- twentyFourHourDataService
///		- fourDayDataService
/// @authors	Maram

/// @brief  	constructor.
/// @details	nothing needs to be done here.
EquipmentService::EquipmentService()
{
}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
EquipmentService::~EquipmentService()
{
        delete this->_state;
}

/// @brief  	sends the equipment.
/// @details	sends the data gotten from this to displayequipment.
void EquipmentService::doService() {
    this->_state->doService();
}

/// @brief  	gets the current equipment.
/// @details	gets the equipment at the current time from the API.
void EquipmentService::currentDataService(){

    QJsonObject json = interface->APICall();

    QJsonObject mainJson = json["main"].toObject();

    QJsonValue jCondition = mainJson["id"];
    int condition = jCondition[0].toInt();

    if(condition == 2){
        data->setCurrentEquipment("raincoat, umbrella, and rainboots");
    }
    if(condition == 3){
        data->setCurrentEquipment("raincoat, umbrella, and rainboots");
    }
    if(condition == 5){
        data->setCurrentEquipment("raincoat, umbrella, and rainboots");
    }
    if(condition == 6){
        data->setCurrentEquipment("coat, hat, gloves and snow boots");
    }
    if(condition == 8){
        data->setCurrentEquipment("sunglasses");
    }
    else{
        data->setCurrentEquipment("no equipment needed");
    }

}

/// @brief  	gets the equipment over the next 24 hours.
/// @details	gets the equipment for each hour over the next 24 hours from the API.
void EquipmentService::twentyFourHourDataService(){

    QJsonObject json = interface->APICall();
    QJsonArray list = json["list"].toArray();
    QVector<QString> hourlyId;

    for(int i = 0; i < 8; i++){
        // iterate through the values, do the comparison and append msg with equipment to vector
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jId = valobj["id"];
        int condition = jId[0].toInt();

        if(condition == 2){
            hourlyId.append("raincoat, umbrella, and rainboots");
        }
        if(condition == 3){
            hourlyId.append("raincoat, umbrella, and rainboots");
        }
        if(condition == 5){
            hourlyId.append("raincoat, umbrella, and rainboots");
        }
        if(condition == 6){
            hourlyId.append("coat, hat, gloves and snow boots");
        }
        if(condition == 8){
            hourlyId.append("sunglasses");
        }
        else{
            hourlyId.append("no equipment needed");
        }
        data->setTwentyFourEquipment(hourlyId);

    }
}

/// @brief  	gets the equipment over the next 4 days.
/// @details	gets the equipment for each day over the next 4 days from the API.
void EquipmentService::fourDayDataService(){
    QJsonObject json = interface->APICall();
    QJsonArray list = json["list"].toArray();
    QVector<QString> hourlyId;

    for(int i = 4; i < 40; i+=8){
        // iterate through the values, do the comparison and append msg with equipment to vector
        QJsonObject obj = list[i].toObject();
        QJsonObject valobj = obj["main"].toObject();
        QJsonValue jId = valobj["id"];
        int condition = jId[0].toInt();

        if(condition == 2){
            hourlyId.append("raincoat, umbrella, and rainboots");
        }
        if(condition == 3){
            hourlyId.append("raincoat, umbrella, and rainboots");
        }
        if(condition == 5){
            hourlyId.append("raincoat, umbrella, and rainboots");
        }
        if(condition == 6){
            hourlyId.append("coat, hat, gloves and snow boots");
        }
        if(condition == 8){
            hourlyId.append("sunglasses");
        }
        else{
            hourlyId.append("no equipment needed");
        }
        data->setFourDayEquipment(hourlyId);

    }
}
