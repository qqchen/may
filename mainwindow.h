#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <QLineEdit>
#include <QLabel>
#include <qstring.h>
#include "may/db.h"
#include "addworddialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void ShowText();
    void ClearWords();
    void ShowAddEnglishWord();
    void AddEnglishWord(QString& en, QString& chinese);

private:
    void InitWords(int wordNum, std::vector<std::string>& words);
    void CreateWordLayout(int wordNum, std::vector<std::string> &words);

private:
    Ui::MainWindow *ui;
    AddWordDialog *m_addWordDialog;
    std::vector<QLineEdit*> leWords;
    std::vector<QLabel*> lbWords;
    int wordNum;
    may::DB* m_db;
};

#endif // MAINWINDOW_H
