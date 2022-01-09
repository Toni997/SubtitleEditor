#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QDebug>
#include "direction.h"

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

signals:
    void findCalled(QString& find, bool shouldMatchCase, bool shouldWrapAround, EDirection direction);

private slots:
    void on_btnFind_clicked();
    void on_btnCancel_clicked();

private:
    Ui::FindDialog *ui;
};

#endif // FINDDIALOG_H
