#ifndef GROUP4_WEATHERDATA_H
#define GROUP4_WEATHERDATA_H

#include <QString>
#include <QMap>
#include <QVector>

class WeatherData {
private:
    QString currentActivity;
    QVector<QString> twentyFourActivity;
    QVector<QString> fourDayActivity;

    int currentCloudCoverage;
    QVector<int> twentyFourCloudCoverage;
    QVector<int> fourDayCloudCoverage;

    QString currentEquipment;
    QVector<QString> twentyFourEquipment;
    QVector<QString> fourDayEquipment;

    int currentHumidity;
    QVector<int> twentyFourHumidity;
    QVector<int> fourDayHumidity;

    QString currentOutfit;
    QVector<QString> twentyFourOutfit;
    QVector<QString> fourDayOutfit;

    QString currentPrecipitation;
    QVector<QString> twentyFourPrecipitation;
    QVector<QString> fourDayPrecipitation;

    double currentTemperature;
    QVector<double> twentyFourTemperature;
    QVector<double> fourDayTemperature;

    int currentWindSpeed;
    QVector<double> twentyFourWindSpeed;
    QVector<double> fourDayWindSpeed;

public:
    WeatherData();
    ~WeatherData();

    const QString &getCurrentActivity() const;

    void setCurrentActivity(const QString &currentActivity);

    const QVector<QString> &getTwentyFourActivity() const;

    void setTwentyFourActivity(const QVector<QString> &twentyFourActivity);

    const QVector<QString> &getFourDayActivity() const;

    void setFourDayActivity(const QVector<QString> &fourDayActivity);

    int getCurrentCloudCoverage() const;

    void setCurrentCloudCoverage(int currentCloudCoverage);

    const QVector<int> &getTwentyFourCloudCoverage() const;

    void setTwentyFourCloudCoverage(const QVector<int> &twentyFourCloudCoverage);

    const QVector<int> &getFourDayCloudCoverage() const;

    void setFourDayCloudCoverage(const QVector<int> &fourDayCloudCoverage);

    const QString &getCurrentEquipment() const;

    void setCurrentEquipment(const QString &currentEquipment);

    const QVector<QString> &getTwentyFourEquipment() const;

    void setTwentyFourEquipment(const QVector<QString> &twentyFourEquipment);

    const QVector<QString> &getFourDayEquipment() const;

    void setFourDayEquipment(const QVector<QString> &fourDayEquipment);

    int getCurrentHumidity() const;

    void setCurrentHumidity(int currentHumidity);

    const QVector<int> &getTwentyFourHumidity() const;

    void setTwentyFourHumidity(const QVector<int> &twentyFourHumidity);

    const QVector<int> &getFourDayHumidity() const;

    void setFourDayHumidity(const QVector<int> &fourDayHumidity);

    const QString &getCurrentOutfit() const;

    void setCurrentOutfit(const QString &currentOutfit);

    const QVector<QString> &getTwentyFourOutfit() const;

    void setTwentyFourOutfit(const QVector<QString> &twentyFourOutfit);

    const QVector<QString> &getFourDayOutfit() const;

    void setFourDayOutfit(const QVector<QString> &fourDayOutfit);

    QString getCurrentPrecipitation() const;

    void setCurrentPrecipitation(QString currentPrecipitation);

    const QVector<QString> &getTwentyFourPrecipitation() const;

    void setTwentyFourPrecipitation(const QVector<QString> &twentyFourPrecipitation);

    const QVector<QString> &getFourDayPrecipitation() const;

    void setFourDayPrecipitation(const QVector<QString> &fourDayPrecipitation);

    double getCurrentTemperature() const;

    void setCurrentTemperature(double currentTemperature);

    const QVector<double> &getTwentyFourTemperature() const;

    void setTwentyFourTemperature(const QVector<double> &twentyFourTemperature);

    const QVector<double> &getFourDayTemperature() const;

    void setFourDayTemperature(const QVector<double> &fourDayTemperature);

    double getCurrentWindSpeed() const;

    void setCurrentWindSpeed(double currentWindSpeed);

    const QVector<double> &getTwentyFourWindSpeed() const;

    void setTwentyFourWindSpeed(const QVector<double> &twentyFourWindSpeed);

    const QVector<double> &getFourDayWindSpeed() const;

    void setFourDayWindSpeed(const QVector<double> &fourDayWindSpeed);
};


#endif //GROUP4_WEATHERDATA_H
