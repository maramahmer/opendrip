#include "factory.h"
#include <QVectorIterator>
#include "displayequipment.h"
#include "displayoutfit.h"
#include "equipmentservice.h"
#include "outfitService.h"
#include "precipitationService.h"
#include "humidityservice.h"
#include "windspeedservice.h"
#include "temperatureservice.h"
#include "cloudcoverageservice.h"
#include "displayprecipitation.h"
#include "displayhumidity.h"
#include "displaycloudcoverage.h"
#include "displaywindspeed.h"
#include "displaytemperature.h"
#include "display24hoursdatastate.h"
#include "display4daysdatastate.h"
#include "displaycurrentdatastate.h"
#include "currentdataservicestate.h"
#include "fourdaydataservicestate.h"
#include "twentyfourhoursdataservicestate.h"
#include "userrequest.h"
/// @brief	    Processes Requests
/// @details    Interfaces with computation to process user requests using these functions:
///		- createDisplayState
///     - createDataServiceState
///     - createDataService
///     - createDisplay

/// @authors	Soren, Ali, Maram, Arnav

/// @brief  	constructor.
/// @details	nothing needs to be done here.
Factory::Factory() {

}

/// @brief  	deconstructor.
/// @details	nothing needs to be done here.
Factory::~Factory() {

}

/// @brief      takes user request to return display.
/// @details    returns appropriate data for required times.
/// @returns    display object of data for required time.
/// @param      req used to extract the required time range.
DisplayState* Factory::createDisplayState(UserRequest req) {
    QString duration = req.getRequestedDuration();
    if (!QString::compare(duration, "current")){
        return new DisplayCurrentDataState();
    }
    if (!QString::compare(duration, "fourDay")){
        return new Display4DaysDataState();
    }
    if (!QString::compare(duration, "twentyFourHour")){
        return new Display24HoursDataState();
    }
}

/// @brief      takes user request to return service.
/// @details    returns correct data for the requested times.
/// @returns    service object for the time.
/// @param      req used to find the required time range.
DataServiceState* Factory::createDataServiceState(UserRequest req) {
    QString duration = req.getRequestedDuration();
    if (!QString::compare(duration, "current")){
        return new CurrentDataServiceState();
    }
    if (!QString::compare(duration, "fourDay")){
        return new FourDayDataServiceState();
    }
    if (!QString::compare(duration, "twentyFourHour")){
        return new TwentyFourHoursDataServiceState();
    }
}

/// @brief      populates the services based on requested information
/// @details    sets the state, data service, user request, weather data, and weather interface
/// @returns    returns a vector of the services
/// @param      req is the requested services and duration, data uses that to get the data from the API.
QVector<DataService*> Factory::createDataService(UserRequest *req, WeatherData *data) {

    QVector<QString> services = req->getRequestedServices();
    QVector<DataService*> dataService;
    WeatherInterface *interface = new WeatherInterface(*req);

    QVectorIterator<QString> i(services);

    while (i.hasNext()) {
        QString s = i.next();

        if (!QString::compare(s, "precipitation")) {
            PrecipitationService* service = new PrecipitationService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }
        else if (!QString::compare(s, "humidity")) {
            HumidityService* service = new HumidityService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }
        else if (!QString::compare(s, "windSpeed")) {
            WindSpeedService* service = new WindSpeedService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }
        else if (!QString::compare(s, "temperature")) {
            TemperatureService* service = new TemperatureService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }
        else if (!QString::compare(s, "cloudCoverage")) {
            CloudCoverageService* service = new CloudCoverageService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }
        else if (!QString::compare(s, "equipment")) {
            EquipmentService* service = new EquipmentService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }
        else if (!QString::compare(s, "outfit")) {
            OutfitService* service = new OutfitService();
            DataServiceState* state = Factory::createDataServiceState(*req);
            service->setState(state);
            state->setDataService(service);
            service->setUserRequest(req);
            service->setWeatherData(data);
            service->setWeatherInterface(interface);
            dataService.append(service);
        }

    }

    return dataService;
}

/// @brief      populates the display based on requested information
/// @details    sets the state, data service, user request, weather data, and weather interface
/// @returns    returns a vector of the displays
/// @param      req is the requested services and duration .
/// @param      data uses that to get the data from the API.
/// @param      UI is the UI to load the displays onto.
QVector<UserInterfacing*> Factory::createDisplay(UserRequest *req, WeatherData *data, Ui::OpenDrip *UI) {

    QVector<QString> services = req->getRequestedServices();
    QVector<UserInterfacing*> displays;

    QVectorIterator<QString> i(services);

    while (i.hasNext()) {
        QString s = i.next();

        if (!QString::compare(s, "precipitation")) {
            DisplayPrecipitation* display = new DisplayPrecipitation();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }
        else if (!QString::compare(s, "humidity")) {
            DisplayHumidity* display = new DisplayHumidity();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }
        else if (!QString::compare(s, "windSpeed")) {
            DisplayWindSpeed* display = new DisplayWindSpeed();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }
        else if (!QString::compare(s, "temperature")) {
            DisplayTemperature* display = new DisplayTemperature();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }
        else if (!QString::compare(s, "cloudCoverage")) {
            DisplayCloudCoverage* display = new DisplayCloudCoverage();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }
        else if (!QString::compare(s, "outfit")) {
            DisplayOutfit* display = new DisplayOutfit();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }
        else if (!QString::compare(s, "equipment")) {
            DisplayEquipment* display = new DisplayEquipment();
            DisplayState* state = Factory::createDisplayState(*req);
            display->setState(state);
            state->setUserInterfacing(display);
            display->setUI(UI);
            display->setWeatherData(data);
            displays.append(display);
        }

    }
    return displays;
}

