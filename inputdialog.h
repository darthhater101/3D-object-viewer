#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class InputDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* positionX;
    QLineEdit* positionY;
    QLineEdit* positionZ;
    QLineEdit* scale;

public:
    InputDialog(QWidget *parent = nullptr);

    float getPositionX();
    float getPositionY();
    float getPositionZ();
    float getScale();
};

