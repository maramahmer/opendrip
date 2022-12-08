#ifndef OPENDRIP_H
#define OPENDRIP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class OpenDrip; }
QT_END_NAMESPACE

class OpenDrip : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_SubmitLocation_clicked();

private:
    Ui::OpenDrip *ui;

public:
    OpenDrip(QWidget *parent = nullptr);
    Ui::OpenDrip* getUI() {return ui;}
    ~OpenDrip();
};
#endif // OPENDRIP_H
