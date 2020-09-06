#ifndef SDIALOG_H
#define SDIALOG_H

#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QTreeView>
#include <QListView>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QTextCodec>
#include <QDir>
#include <QInputDialog>
#include <QTextEdit>
#include <QTimer>
#include <QProcess>






class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();


signals:
        //void findNext(const QString &str, Qt::CaseSensitivity cs);
        //void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
        void findClicked();
        void findClicked1();
        void findClicked2();
        void findClicked3();
        void findClicked4();
        void findClicked6();
        void enableFindButton(const QString &text);
        void enableButton1(const QString &text);
        //void enableButton2(const QString &text);
        void enableButton3(const QString &text);
        void enableButton4(const QString &text);
        void enableButton5(const QString &text);
        void CompleteButton5();
        void readOutput();
        void CheckInclude();
        void startListen();
        void listenning();

private:
        QProcess* cmd;
        QLabel *label;
        QLabel *label1;
        QLabel *label2;
        QLabel *label3;
        QLabel *label4;
        QLabel *label5;
        QLabel *label6;
        QLabel *label7;
        QLabel *label8;
        //QLabel *label9;
        QLineEdit *lineEdit;
        QLineEdit *lineEdit1;
        QTextEdit *lineEdit2;
        QLineEdit *lineEdit3;
        QLineEdit *lineEdit4;
        QTextEdit *textEdit2;
        QLineEdit *lineEdit5;
        //QLineEdit *lineEdit6;
        //QLineEdit *lineEdit7;
        //QLineEdit *lineEdit8;
        //QLineEdit *lineEdit9;
        QCheckBox *caseCheckBox;
        QCheckBox *caseCheckBox1;
        QCheckBox *caseCheckBox2;
        QCheckBox *caseCheckBox3;
        QPushButton *findButton;
        //QPushButton *closeButton;
        QPushButton *Button1;
        QPushButton *Button2;
        QPushButton *Button3;
        QPushButton *Button4;
        QPushButton *Button5;
        QPushButton *Button6;
        QPushButton *Button7;
        bool g_done;
        bool g_success;
        int g_sunumber;
        int g_countnum;
        bool g_startL;
        //QString s1;
        //QString path1;


        //QFile fs;
        void textshow();

};

#endif // DIALOG_H
