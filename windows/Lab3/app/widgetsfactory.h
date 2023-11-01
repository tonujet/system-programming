#ifndef WIDGETSFACTORY_H
#define WIDGETSFACTORY_H
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <string>

class WidgetsFactory
{
public:
    WidgetsFactory(){};
    virtual ~WidgetsFactory() = default;

    virtual QPushButton *createPushButton(const QString &text, int x, int y, QWidget *parent) = 0;
    virtual QLabel *createLabel(const QString &text, int x, int y, QWidget *parent) = 0;
    virtual QSpinBox *createSpinBox(int x, int y, QWidget *parent) = 0;
};
#endif // WIDGETSFACTORY_H
