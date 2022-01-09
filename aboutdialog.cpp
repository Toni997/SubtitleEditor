#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    setWindowTitle("About");
    setWindowIcon(QIcon(":/icons/icons/about.ico"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
