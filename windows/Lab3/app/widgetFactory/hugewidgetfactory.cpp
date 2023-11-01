#include "../hugewidgetfactory.h"

HugeWidgetFactory::HugeWidgetFactory(){}

QPushButton *HugeWidgetFactory::createPushButton(const QString &text, int x, int y, QWidget *parent)
{
    QPushButton *pushButton = new QPushButton(text, parent);
    pushButton->setGeometry(x, y, 230, 80);
    return pushButton;
}

QLabel *HugeWidgetFactory::createLabel(const QString &text, int x, int y, QWidget *parent)
{
    QLabel *label = new QLabel(text, parent);
    label->setGeometry(x, y, 100, 20);
    return label;
}

QSpinBox *HugeWidgetFactory::createSpinBox(int x, int y, QWidget *parent)
{
    QSpinBox *spinBox = new QSpinBox(parent);
    spinBox->setMinimum(0);
    spinBox->setMaximum(std::numeric_limits<int>::max());
    spinBox->setSingleStep(1);
    spinBox->setValue(0);
    spinBox->setGeometry(x, y, 100, 50);
    return spinBox;
}
