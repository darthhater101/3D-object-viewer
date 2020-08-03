#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillList()
{
    auto objectList = ui->openGLWidget->getCurrentScene();
    ui->objectsList->clear();
    for(auto iter : objectList)
    {
        ListItem *item = new ListItem();
        item->setId(iter.getId());
        item->setText(iter.getName());
        ui->objectsList->addItem(item);
    }
}

void MainWindow::on_addModelButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose .obj file", QDir::homePath(), "Obj file (*.obj)");

    InputDialog* inputDialog = new InputDialog(this);

    if (inputDialog->exec() == QDialog::Accepted)
    {
        float x = inputDialog->getPositionX();
        float y = inputDialog->getPositionY();
        float z = inputDialog->getPositionZ();
        float scale = inputDialog->getScale();
        ui->openGLWidget->makeCurrent();
        ui->openGLWidget->addObject(Model(QVector3D(x, y, z), scale, fileName,
                               "C:/Users/razer/Documents/Modeller3D/shaders/basic"));
        fillList();
    }
    delete inputDialog;
}

void MainWindow::on_addCubeButton_clicked()
{
    InputDialog* inputDialog = new InputDialog(this);

    if (inputDialog->exec() == QDialog::Accepted)
    {
        float x = inputDialog->getPositionX();
        float y = inputDialog->getPositionY();
        float z = inputDialog->getPositionZ();
        float scale = inputDialog->getScale();
        ui->openGLWidget->makeCurrent();
        ui->openGLWidget->addObject(Cube(QVector3D(x, y, z), scale));
        fillList();
    }
    delete inputDialog;
}

void MainWindow::on_deleteModelButton_clicked()
{
    auto item = ui->objectsList->currentItem();
    if(!item) return;
    ui->openGLWidget->makeCurrent();
    ui->openGLWidget->deleteObject(dynamic_cast<ListItem*>(item)->getId());
    fillList();
}
