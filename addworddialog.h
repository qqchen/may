#ifndef ADDWORDDIALOG_H
#define ADDWORDDIALOG_H

#include <QDialog>

namespace Ui {
class AddWordDialog;
}

class AddWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddWordDialog(QWidget *parent = 0);
    ~AddWordDialog();

public slots:
    void AddWord();

signals:
    void SignalAddWord(QString& en, QString& chinese);

private:
    Ui::AddWordDialog *ui;
};

#endif // ADDWORDDIALOG_H
