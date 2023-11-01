#ifndef DEFAULTWIDGETFACTORY_H
#define DEFAULTWIDGETFACTORY_H

#include "widgetsfactory.h"



class DefaultWidgetFactory: public WidgetsFactory
{
public:
    DefaultWidgetFactory();

public:
    QPushButton *createPushButton(const QString &text, int x, int y, QWidget *parent) override;
    QLabel *createLabel(const QString &text, int x, int y, QWidget *parent) override;
    QSpinBox *createSpinBox(int x, int y, QWidget *parent) override;
};

#endif // DEFAULTWIDGETFACTORY_H
