#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <fstream>
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QSpinBox>
#include <QMessageBox>
#include <QCloseEvent>
#include <limits>
#include <random>
#include "mainwindow.h"
#include "owner.h"
#include "taxicompany.h"
#include "car.h"

using std::string;


MainWindow::MainWindow(
    TaxiCompany &company, OwnerView &ownerView,
    CarView &carView,OwnerCsvService &ownerCsvService,
    CarCsvService &carCsvService, CarCsvService &removedCarCsvService,
    WidgetsFactory *defaulWidgetFactory, WidgetsFactory *hugeWidgetFactory,
    QWidget *parent
): QMainWindow(parent), company(company),
    ownerView(ownerView), carView(carView),
    ownerCsvService(ownerCsvService), carCsvService(carCsvService),
    removedCarCsvService(removedCarCsvService),
    defaulWidgetFactory(defaulWidgetFactory), hugeWidgetFactory(hugeWidgetFactory)
{
    setWindowTitle("Car company");
    setGeometry(500, 500, 500, 500);
    setMinimumSize(500, 500);
    setMaximumSize(500, 500);

    outputField = new QTextEdit(this);
    outputField->setGeometry(10, 10, 480, 150);
    outputField->setReadOnly(true);

    createInputs();
    createButtons();

}


void MainWindow::createButtons(){

    QPushButton *viewCarButton =
        defaulWidgetFactory->createPushButton("View car", 10, 180, this);
    connect(viewCarButton, SIGNAL (released()), this, SLOT (onViewCar()));

    QPushButton *changeOwnerForCarButton =
        defaulWidgetFactory->createPushButton("Change owner for car", 340, 180, this);
    connect(changeOwnerForCarButton, SIGNAL (released()), this, SLOT (onChangeOwnerForCar()));

    QPushButton *deleteCarButton =
        defaulWidgetFactory->createPushButton("Delete car", 10, 250, this);
    connect(deleteCarButton, SIGNAL (released()), this, SLOT (onDeleteCar()));

    QPushButton *increaseMileageButton =
        defaulWidgetFactory->createPushButton("Increase mileage \nby random value", 175, 250, this);
    connect(increaseMileageButton, SIGNAL (released()), this, SLOT (onIncreaseMileage()));

    QPushButton *regainCarButton =
        defaulWidgetFactory->createPushButton("Regain car", 340, 250, this);
    connect(regainCarButton, SIGNAL (released()), this, SLOT (onRegainCar()));

    QPushButton *viewCarsButton =
        hugeWidgetFactory->createPushButton("View cars", 10, 315, this);
    connect(viewCarsButton, SIGNAL (released()), this, SLOT (onViewCars()));

    QPushButton *viewRemovedCarsButton =
        hugeWidgetFactory->createPushButton("View removed cars", 260, 315, this);
    connect(viewRemovedCarsButton, SIGNAL (released()), this, SLOT (onViewRemovedCars()));

    QPushButton *viewCarOwnersButton =
        hugeWidgetFactory->createPushButton("View car owners", 10, 410, this);
    connect(viewCarOwnersButton, SIGNAL (released()), this, SLOT (onViewCarOwners()));

    QPushButton *exit =
        hugeWidgetFactory->createPushButton("Exit", 260, 410, this);
    connect(exit, SIGNAL (released()), this, SLOT (onExitButton()));

}

void MainWindow::createInputs(){
    carIdInput =
        defaulWidgetFactory->createSpinBox(190, 200, this);

    ownerIdInput =
        defaulWidgetFactory->createSpinBox(260, 200, this);

    QLabel *carIdInputLabel =
        defaulWidgetFactory->createLabel("Car id:", 190, 186, this);

    QLabel *ownerIdInputLabel =
        defaulWidgetFactory->createLabel("Owner id:", 260, 186, this);
}


void MainWindow::onViewCar(){
    int id = carIdInput->value();
    Car *car = company.getCar(id);
    string res = carView.getFull(car);
    if(res.length() == 0) res = carView.carNotFound(id);
    QString output = QString::fromStdString(res);
    outputField->setText(output);
}

void MainWindow::onViewCars(){
    viewCars(company.getCars());
}

void MainWindow::onViewRemovedCars(){
    viewCars(company.getRemovedCars());
}

void MainWindow::onViewCarOwners(){
    std::vector<Owner *> *cars = company.getOwners();
    QString output = QString::fromStdString(ownerView.getFull(cars));
    outputField->setText(output);
}

void MainWindow::onChangeOwnerForCar(){
    int ownerId = ownerIdInput->value();
    int carId = carIdInput->value();
    string result;
    Owner *owner = company.getOwner(ownerId);
    if(owner == nullptr){
        result = ownerView.ownerNotFound(ownerId);
        outputField->setText(QString::fromStdString(result));
        return;
    }

    Car *car = company.changeOwner(owner, carId);
    if(car == nullptr) {
        result = carView.carNotFound(carId);
        outputField->setText(QString::fromStdString(result));
        return;
    }

    result = carView.changedOwner(car, owner);
    outputField->setText(QString::fromStdString(result));

}

void MainWindow::onDeleteCar(){
    int id = carIdInput->value();
    Car *car = company.deleteCar(id);
    string result = carView.deletingCar(car, id);
    outputField->setText(QString::fromStdString(result));
}

void MainWindow::onRegainCar(){
    int id = carIdInput->value();
    Car *car = company.regainCar(id);
    string result = carView.regainingCar(car, id);
    outputField->setText(QString::fromStdString(result));
}

void MainWindow::onIncreaseMileage(){
    int id = carIdInput->value();
    Car *car = company.increaseMileageInRange(id, 1, 100);
    QString output = QString::fromStdString(carView.increasedMileage(car, id));
    outputField->setText(output);
}


void MainWindow::viewCars(std::vector<Car *> *cars){
    string result = carView.getFull(cars);
    outputField->setText(QString::fromStdString(result));
}

void MainWindow::saveData()
{
    try{
        carCsvService.write(company.getCars());
        removedCarCsvService.write(company.getRemovedCars());
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void MainWindow::onExitButton(){
    saveData();
    close();
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit",
                                                               tr("Are you sure?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        saveData();
        event->accept();
    }
}


MainWindow::~MainWindow(){
    delete defaulWidgetFactory;
    delete hugeWidgetFactory;
}

