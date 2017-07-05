#ifndef PARTSSETTINGDIALOG_H
#define PARTSSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class PartsSettingDialog;
}

class PartsSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PartsSettingDialog(QWidget *parent = 0);
    ~PartsSettingDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_set_image_patterns_clicked();

private:
    Ui::PartsSettingDialog *ui;
    QString _file_dialog_path;
};

#endif // PARTSSETTINGDIALOG_H
