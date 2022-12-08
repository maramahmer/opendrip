#ifndef WEATHERINTERFACE_H
#define WEATHERINTERFACE_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QJsonObject>
#include <QUrl>
#include <QEventLoop>
#include "userrequest.h"


class WeatherInterface {

private:
    static const QString APIKey;
    QString location;
    QString duration;
    QEventLoop loop;
    QNetworkAccessManager *manager;
    QJsonObject json;
    static bool isAPICalled;

public:
    ~WeatherInterface();
    const QJsonObject APICall();
    WeatherInterface(UserRequest req);

};

#endif // WEATHERINTERFACE_H
