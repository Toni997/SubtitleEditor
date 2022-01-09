#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    setWindowTitle("Find");
    setAttribute(Qt::WA_DeleteOnClose);

    connect(this, SIGNAL(findCalled(QString&,bool,bool,EDirection)), parent, SLOT(findCalled(QString&,bool,bool,EDirection)));
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_btnFind_clicked()
{
    auto find = ui->txtFind->text();
    if(find.isEmpty()) return;

    bool shouldMatchCase = ui->chkMatchCase->isChecked();
    bool shouldWrapAround = ui->chkWrapAround->isChecked();
    EDirection direction = ui->rdDirectionDown->isChecked() ? EDirection::Down : EDirection::Up;

    emit findCalled(find, shouldMatchCase, shouldWrapAround, direction);
}

void FindDialog::on_btnCancel_clicked()
{
    reject();
}

