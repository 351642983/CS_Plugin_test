#include "dialog.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("System"));	//转换Tr
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));	//转换字符
    QApplication a(argc, argv);
    Dialog *w=new Dialog;
    a.setWindowIcon(QIcon("game.ico"));
    w->show();
    return a.exec();
}
