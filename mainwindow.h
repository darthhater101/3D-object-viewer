#pragma once

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QDir>

#include "inputdialog.h"
#include "cube.h"
#include "model.h"
#include "glwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addModelButton_clicked();
    void on_addCubeButton_clicked();
    void on_deleteModelButton_clicked();

private:
    Ui::MainWindow *ui;

    void fillList();

};
