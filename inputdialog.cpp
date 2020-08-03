#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    positionX = new QLineEdit();
    positionY = new QLineEdit();
    positionZ = new QLineEdit();
    scale = new QLineEdit();

    positionX->setFixedWidth(50);
    positionY->setFixedWidth(50);
    positionZ->setFixedWidth(50);
    scale->setFixedWidth(50);

    positionX->setText("0");
    positionY->setText("0");
    positionZ->setText("0");
    scale->setText("1");

    QLabel *positionXLabel = new QLabel("Position X");
    QLabel *positionYLabel = new QLabel("Position Y");
    QLabel *positionZLabel = new QLabel("Position Z");
    QLabel *scaleLabel = new QLabel("Scale");

    positionXLabel->setBuddy(positionX);
    positionYLabel->setBuddy(positionY);
    positionZLabel->setBuddy(positionZ);
    scaleLabel->setBuddy(scale);

    QPushButton* buttonOk     = new QPushButton("Ok");
    QPushButton* buttonCancel = new QPushButton("Cancel");

    connect(buttonOk, SIGNAL(clicked()), SLOT(accept()));
    connect(buttonCancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout();
    ptopLayout->addWidget(positionXLabel, 0, 0);
    ptopLayout->addWidget(positionYLabel, 0, 2);
    ptopLayout->addWidget(positionZLabel, 0, 4);
    ptopLayout->addWidget(scaleLabel, 1, 0);
    ptopLayout->addWidget(positionX, 0, 1);
    ptopLayout->addWidget(positionY, 0, 3);
    ptopLayout->addWidget(positionZ, 0, 5);
    ptopLayout->addWidget(scale, 1, 1);
    ptopLayout->addWidget(buttonOk, 2, 2);
    ptopLayout->addWidget(buttonCancel, 2, 3);
    setLayout(ptopLayout);
}

float InputDialog::getPositionX()
{
    if(positionX->text().isEmpty())
        return 0.0f;
    return positionX->text().toFloat();
}

float InputDialog::getPositionY()
{
    if(positionY->text().isEmpty())
        return 0.0f;
    return positionY->text().toFloat();
}

float InputDialog::getPositionZ()
{
    if(positionZ->text().isEmpty())
        return 0.0f;
    return positionZ->text().toFloat();
}

float InputDialog::getScale()
{
    if(scale->text().isEmpty())
        return 1.0f;
    return scale->text().toFloat();
}
