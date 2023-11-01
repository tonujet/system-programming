#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include "taxicompany.h"
#include "carview.h"
#include "ownerview.h"
#include "ownercsvservice.h"
#include "carcsvservice.h"
#include "widgetsfactory.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(
        TaxiCompany &company, OwnerView &ownerView,
        CarView &carView, OwnerCsvService &ownerCsvService,
        CarCsvService &carCsvService, CarCsvService &removedCarCsvService,
        WidgetsFactory *defaulWidgetFactory, WidgetsFactory *hugeWidgetFactory,
        QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onViewCar();
    void onViewCars();
    void onViewRemovedCars();
    void onViewCarOwners();
    void onChangeOwnerForCar();
    void onDeleteCar();
    void onRegainCar();
    void onExitButton();
    void onIncreaseMileage();
private:
    void closeEvent (QCloseEvent *event) override;

    void createButtons();
    void createInputs();
    void viewCars(std::vector<Car *> *cars);
    void saveData();


    QSpinBox *carIdInput;
    QSpinBox *ownerIdInput;
    QTextEdit *outputField;
    TaxiCompany &company;
    CarView &carView;
    OwnerView &ownerView;
    OwnerCsvService &ownerCsvService;
    CarCsvService &carCsvService;
    CarCsvService &removedCarCsvService;
    WidgetsFactory *defaulWidgetFactory;
    WidgetsFactory *hugeWidgetFactory;


};



#endif // MAINWINDOW_H
