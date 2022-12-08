#ifndef USERREQUEST_H
#define USERREQUEST_H

#include <QString>
#include <QVector>

using namespace std;

class UserRequest {
private:
    int requestedTemperatureType;
    QString requestedLocation;
    QString requestedDuration;
    QVector<QString> requestedServices;

public:
    const int &getRequestedTemperatureType() const;

    void setRequestedTemperatureType(const int &temperatureType);

    const QString &getRequestedLocation() const;

    void setRequestedLocation(const QString &requestedLocation);

    const QString &getRequestedDuration() const;

    void setRequestedDuration(const QString &requestedDuration);

    const QVector<QString> &getRequestedServices() const;

    void setRequestedServices(const QVector<QString> &requestedServices);

    UserRequest();
    ~UserRequest();
};

#endif // USERREQUEST_H
