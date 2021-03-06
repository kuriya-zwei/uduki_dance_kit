﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "udkparts.h"
#include "udkglobaldata.h"
#include "partssettingdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_addParts_clicked();

private:
    Ui::MainWindow *ui;
    Ui::PartsSettingDialog *parts_dialog;
};

#endif // MAINWINDOW_H
