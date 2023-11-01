#ifndef HUGEWIDGETFACTORY_H
#define HUGEWIDGETFACTORY_H

#include "widgetsfactory.h"



class HugeWidgetFactory: public WidgetsFactory
{
public:
    HugeWidgetFactory();


public:
    QPushButton *createPushButton(const QString &text, int x, int y, QWidget *parent);
    QLabel *createLabel(const QString &text, int x, int y, QWidget *parent);
    QSpinBox *createSpinBox(int x, int y, QWidget *parent);
};

#endif // HUGEWIDGETFACTORY_H
