#include "../defaultwidgetfactory.h"

DefaultWidgetFactory::DefaultWidgetFactory(){}

QPushButton *DefaultWidgetFactory::createPushButton(const QString &text, int x, int y, QWidget *parent)
{
    QPushButton *pushButton = new QPushButton(text, parent);
    pushButton->setGeometry(x, y, 150, 50);
    return pushButton;
}

QLabel *DefaultWidgetFactory::createLabel(const QString &text, int x, int y, QWidget *parent)
{
    QLabel *label = new QLabel(text, parent);
    label->setGeometry(x, y, 50, 10);
    return label;
}

QSpinBox *DefaultWidgetFactory::createSpinBox(int x, int y, QWidget *parent)
{
    QSpinBox *spinBox = new QSpinBox(parent);
    spinBox->setMinimum(0);
    spinBox->setMaximum(std::numeric_limits<int>::max());
    spinBox->setSingleStep(1);
    spinBox->setValue(0);
    spinBox->setGeometry(x, y, 50, 20);
    return spinBox;
}
