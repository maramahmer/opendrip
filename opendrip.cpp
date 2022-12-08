#include "opendrip.h"
#include "./ui_opendrip.h"
#include "computation.h"
#include "userrequest.h"
#include "weatherData.h"
/// @brief	    UI processing class.
/// @details    Where all the doings of the UI are happening with the following commands:
///		- TODO: put functions
/// @authors	Nabeel


/// @brief  	constructor.
/// @details    start the setup for the UI.
OpenDrip::OpenDrip(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OpenDrip)
{
    ui->setupUi(this);

    //Set Table names
    QStringList horizontalHeaders = {"Temperature", "Humidity", "Cloud Coverage", "Wind Speed", "Precipitation", "Outfit", "Equipment"};
    ui->HourlyForecast->setHorizontalHeaderLabels(horizontalHeaders);
}

/// @brief  	deconstructor.
/// @details    closes the UI.
OpenDrip::~OpenDrip()
{
    delete ui;
}

/// @brief  	What happens when submit is pressed.
/// @details    Gets and displays all desired data and details the table accordingly.
void OpenDrip::on_SubmitLocation_clicked()
{

    // This will set up the data from the API calls
    QVector<QString> services;
    services.push_back("humidity");
    services.push_back("windSpeed");
    services.push_back("temperature");
    services.push_back("cloudCoverage");
    services.push_back("precipitation");
    services.push_back("outfit");
    services.push_back("equipment");

    UserRequest req = UserRequest();
    req.setRequestedServices(services);
    // Get the inputs from the user and use it for API call
    QString loc = ui->Location->text();
    req.setRequestedLocation(loc);

    if(ui->Fahrenheit->isChecked()) {
        req.setRequestedTemperatureType(1);
    } else {
        req.setRequestedTemperatureType(0);
    }

    if (ui->Current->isChecked()) {
        req.setRequestedDuration("current");
        QStringList verticalHeaders = {"Current", "", "", "", "", "", "", ""};
        ui->HourlyForecast->setVerticalHeaderLabels(verticalHeaders);

    } else if(ui->FourDays->isChecked()) {
        req.setRequestedDuration("fourDay");
        QStringList verticalHeaders = {"Day 1", "Day 2", "Day 3", "Day 4", "", "", "", ""};
        ui->HourlyForecast->setVerticalHeaderLabels(verticalHeaders);
    } else {
        req.setRequestedDuration("twentyFourHour");
        QStringList verticalHeaders = {"Hour 3", "Hour 6", "Hour 9", "Hour 12", "Hour 15", "Hour 18", "Hour 21", "Hour 24"};
        ui->HourlyForecast->setVerticalHeaderLabels(verticalHeaders);
    }

    Computation comp;
    WeatherData data;
    comp.performServices(&req, &data);
    comp.performDisplay(&req, &data, ui);

    for (int i = 4; i < 7; i++) {
        ui->HourlyForecast->resizeColumnToContents(i);
    }

}
