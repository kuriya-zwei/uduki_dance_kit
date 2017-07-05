#include "partssettingdialog.h"
#include "ui_partssettingdialog.h"
#include <QFileDialog>
#include <QMessageBox>

PartsSettingDialog::PartsSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PartsSettingDialog)
{
    ui->setupUi(this);

    _file_dialog_path = QCoreApplication::applicationDirPath();
}

PartsSettingDialog::~PartsSettingDialog()
{
    delete ui;
}

void PartsSettingDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->buttonBox->buttonRole(button) == QDialogButtonBox::ApplyRole)
    {

    }
    else if (ui->buttonBox->buttonRole(button) == QDialogButtonBox::AcceptRole )
    {

    }
    else if (ui->buttonBox->buttonRole(button) == QDialogButtonBox::RejectRole)
    {
        return;
    }


}

void PartsSettingDialog::on_pushButton_set_image_patterns_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), _file_dialog_path,
        tr("Image Files (*.png *.jpg *.bmp *.gif *.sr *.ras *.jpeg *.jpe *.tiff *.tif)"));

    //If IMREAD_COLOR set, always convert image to the 3 channel BGR color image.
    cv::Mat src_img = cv::imread( fileName.toStdString(),IMREAD_COLOR);

    //読み込みに失敗していないかチェック
    if (src_img.data == NULL)
    {
        //読み込みに失敗
        QMessageBox mb("Load Failed!",
                      tr("Missing file, Improper permissions, Unsupported or Invalid format"),
                      QMessageBox::Warning,
                      QMessageBox::Ok | QMessageBox::Default,
                      QMessageBox::NoButton,
                      QMessageBox::NoButton);
        mb.exec();
        return;
    }

    cv::Mat converted_img;
    cv::cvtColor(src_img, converted_img, cv::RGB2BGR); //RGBの順番を入れ替え
    QImage qimg(converted_img.data, converted_img.cols, converted_img.rows, QImage::Format_RGB888);
    //QPainter::drawImage(const QPoint & point, const QImage & image);

}
