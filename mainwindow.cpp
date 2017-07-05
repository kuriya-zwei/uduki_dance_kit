#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    parts_dialog(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_addParts_clicked()
{

    //新しいパーツの作成
    std::shared_ptr<udkParts> parts(new udkParts);
    g_parts_vec.push_back(parts);

    //レイヤーを追加
    udkTimeLineLayer* newlayer = g_time_line.addLayer();

    //このパーツを追加したレイヤーに追加
    newlayer->addNewItem(parts);

    //パーツ設定画面の表示
    if (parts_dialog == 0)
    {
        parts_dialog = new Ui::PartsSettingDialog;
    }

    parts_dialog->show();
}
