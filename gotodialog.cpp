#include "gotodialog.h"
#include "ui_gotodialog.h"

GoToDialog::GoToDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoToDialog)
{
    ui->setupUi(this);

    ui->txtRowNumber->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]*")));

    setWindowTitle("Go To");
    setAttribute(Qt::WA_DeleteOnClose);

    connect(this, SIGNAL(goToRowCalled(int)), parent, SLOT(goToRowCalled(int)));
}

GoToDialog::~GoToDialog()
{
    delete ui;
}

void GoToDialog::on_btnCancel_clicked()
{
    reject();
}

void GoToDialog::on_btnGoTo_clicked()
{
    auto input = ui->txtRowNumber->text();
    if (input.isEmpty())
    {
        ui->txtRowNumber->setFocus();
        return;
    }
    emit goToRowCalled(input.toInt() - 1);
}

