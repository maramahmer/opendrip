#include "computation.h"
#include <iostream>
#include "opendrip.h"

/// @brief	    processes all services and displays.
/// @details    gets the data for each service and display to be used in main.
///		- performServices
///		- performDisplay
/// @authors	Soren, Ali

/// @brief  	constructor.
/// @details    nothing needs constructing.
Computation::Computation() {
}

/// @brief  	destructor.
/// @details    nothing needs deconstructing.
Computation::~Computation() {
    QVectorIterator<DataService*> i(services);
    while (i.hasNext()) {
        delete i.next();
    }
    QVectorIterator<UserInterfacing*> j(displays);
    while (j.hasNext()) {
        delete j.next();
    }
}

/// @brief      processes the services.
/// @details    has each service preform its doService function with the given data.
/// @param req  whichever services have been requested.
/// @param data whatever data is needed from the API.
void Computation::performServices(UserRequest *req, WeatherData *data) {
    services = Factory::createDataService(req, data);

    QVectorIterator<DataService*> i(services);
    while (i.hasNext()) {
        DataService* s = i.next();
        s->doService();
    }
}

/// @brief      processes the displays.
/// @details    has each display preform its display function with the given data.
/// @param req  whichever display have been requested.
/// @param data whatever data is needed from the API.
/// @param ui   the UI to put the displays on
void Computation::performDisplay(UserRequest *req, WeatherData *data, Ui::OpenDrip *ui) {
    displays = Factory::createDisplay(req, data, ui);


    QVectorIterator<UserInterfacing*> i(displays);
    while (i.hasNext()) {
        UserInterfacing* d = i.next();
        d->display();
    }
}
