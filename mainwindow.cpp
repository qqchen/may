#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <assert.h>
#include <QLayout>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_addWordDialog = new AddWordDialog(this);
    wordNum = 13;
    std::vector<std::string> words;
    InitWords(wordNum, words);
    CreateWordLayout(wordNum, words);
    connect(ui->btClearWord, SIGNAL(clicked(bool)), this, SLOT(ClearWords()));
    connect(ui->btAddWord, SIGNAL(pressed()), this, SLOT(ShowAddEnglishWord()));
    connect(m_addWordDialog, SIGNAL(SignalAddWord(QString&, QString&)), this, SLOT(AddEnglishWord(QString&,QString&)));
    m_db = new may::JsonDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowText()
{
    //ui->lbText->setText("Hello world");
}

void MainWindow::ClearWords()
{
    for (size_t i = 0; i < leWords.size(); ++i)
    {
        leWords[i]->clear();
    }

}

void MainWindow::ShowAddEnglishWord()
{
    m_addWordDialog->show();
}

void MainWindow::AddEnglishWord(QString &en, QString &chinese)
{
    m_db->AddWord(en.toStdString(), chinese.toStdString());
    m_db->Save(std::string("test.json"));

}




///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::InitWords(int wordNum, std::vector<std::string> &words)
{
    std::string text("may");
    for (size_t i = 0; i < wordNum; ++i)
    {
        words.push_back(text);
    }
}

void MainWindow::CreateWordLayout(int wordNum, std::vector<std::string> &words)
{
    assert(wordNum > 0 && wordNum == words.size());
    QGridLayout* gridLayout = new QGridLayout(ui->wgWord);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->setHorizontalSpacing(10);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    QFont textFont("Times", 20);
    int row = 0, col = 0;
    for (size_t i = 0; i < wordNum; ++i)
    {
        col = 0;
        QLabel* label = new QLabel(ui->wgWord);
        QString text(words[i].c_str());
        label->setObjectName(text);
        label->setText(text+QString(":"));
        label->setMinimumSize(QSize(80, 0));
        label->setFont(textFont);
        label->setAlignment(Qt::AlignRight);
        gridLayout->addWidget(label, row, col++, 1, 1);

        QLineEdit* leWord0 = new QLineEdit(ui->wgWord);
        //leWord0->setObjectName(QStringLiteral("leWord0"));
        leWord0->setMinimumSize(QSize(133, 25));
        gridLayout->addWidget(leWord0, row, col++, 1, 1);
        lbWords.push_back(label);
        leWords.push_back(leWord0);

        i++;
        if(i >= wordNum)
            break;

        QLabel* labelRight = new QLabel(ui->wgWord);
        QString text1(words[i].c_str());
        labelRight->setObjectName(text1);
        labelRight->setText(text1+QString(":"));
        labelRight->setMinimumSize(QSize(80, 0));
        labelRight->setFont(textFont);
        labelRight->setAlignment(Qt::AlignRight);
        gridLayout->addWidget(labelRight, row, col++, 1, 1);

        QLineEdit* leWordRight = new QLineEdit(ui->wgWord);
        //leWord0->setObjectName(QStringLiteral("leWord0"));
        leWordRight->setMinimumSize(QSize(133, 25));
        gridLayout->addWidget(leWordRight, row, col++, 1, 1);
        lbWords.push_back(labelRight);
        leWords.push_back(leWordRight);
        row++;


    }


}
