#ifndef GOTODIALOG_H
#define GOTODIALOG_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class GoToDialog;
}

class GoToDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToDialog(QWidget *parent = nullptr);
    ~GoToDialog();

signals:
    void goToRowCalled(int rowNumber);

private slots:
    void on_btnCancel_clicked();

    void on_btnGoTo_clicked();

private:
    Ui::GoToDialog *ui;
};

#endif // GOTODIALOG_H
