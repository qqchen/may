#include "addworddialog.h"
#include "ui_addworddialog.h"

AddWordDialog::AddWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWordDialog)
{
    ui->setupUi(this);
    ui->leEngWord->setText(QString(""));
    ui->leChiMeaning->setText(QString(""));
    connect(this, SIGNAL(accepted()), this, SLOT(AddWord()));
}

AddWordDialog::~AddWordDialog()
{
    delete ui;
}

void AddWordDialog::AddWord()
{
    emit(SignalAddWord(ui->leEngWord->text(), ui->leChiMeaning->text()));
}
