#include "dialog.h"
#include <QProcess>
#include <QTime>
#include <QCoreApplication>
#include "windows.h"
#include <QMenuBar>

QString infoshow;



Dialog::Dialog(QWidget *parent)
    :QDialog(parent)
{
            g_sunumber=0;
            g_countnum=0;
            label = new QLabel("CS游戏父目录:");
            label->setWhatsThis(QString("设置CS1.6的目录所在的位置或者是游戏插件所在的位置，然后根据这个位置就能够进行整合了"));
            lineEdit = new QLineEdit;
            label->setBuddy(lineEdit);
            textEdit2=new QTextEdit;
            textEdit2->setReadOnly(true);
            caseCheckBox =new QCheckBox("安装为中文目录");
            caseCheckBox->setWhatsThis(QString("设置安装或者整合CS1.6有关的文件为cstrike_chinese那个文件夹，不过在这个文件夹下的插件应该是使用不了的，因为我也从来都没尝试过在这个目录中尝试着使用插件，但是像不是关于插件类型的地图之类的东西都是可以"));
            caseCheckBox1=new QCheckBox("进行覆盖安装");
            caseCheckBox2=new QCheckBox("安装后删除安装成功的文件");
            caseCheckBox3=new QCheckBox("对sma文件不进行编译");
            findButton = new QPushButton("选择");
            //findButton->setDefault(false);
            findButton->setEnabled(true);
            cmd = new QProcess;
            g_startL=false;

            label1 = new QLabel("放置安装文件的文件夹:");
            lineEdit1 = new QLineEdit;
            label1->setBuddy(lineEdit1);
            Button1 = new QPushButton("选择");
            //Button1->setDefault(false);
            Button1->setEnabled(true);

            label2 = new QLabel("amxx.cfg参数的添加:");
            lineEdit2 = new QTextEdit;
            label2->setBuddy(lineEdit2);
            Button2 = new QPushButton("使用默认inc字典");
            //Button2->setDefault(true);
            Button2->setEnabled(true);

            label3 = new QLabel("选择文件:");
            lineEdit3 = new QLineEdit;
            label3->setBuddy(lineEdit3);
            Button3 = new QPushButton("选择");
            //Button3->setDefault(true);
            Button3->setEnabled(true);

            label4 = new QLabel("放置位置选择:");
            lineEdit4 = new QLineEdit;
            label4->setBuddy(lineEdit4);
            Button4 = new QPushButton("选择");
            //Button4->setDefault(true);
            Button4->setEnabled(true);

            label8 = new QLabel("拓展inc字典文件夹：");
            lineEdit5 = new QLineEdit;
            label8->setBuddy(lineEdit5);
            Button6 = new QPushButton("选择");
            //Button4->setDefault(true);
            Button6->setEnabled(true);
            Button7=new QPushButton("开始监听");
            Button7->setEnabled(true);



            Button5 = new QPushButton("执行操作");
            //Button5->setDefault(true);
            Button5->setEnabled(true);

            label5=new QLabel("额外文件的放置：");

            label6=new QLabel(" ");
            QTimer *countTime=new QTimer;
            connect(countTime,SIGNAL(timeout()),this,SLOT(listenning()));
            countTime->start(10000);


            label7 = new QLabel("来自CS插件吧：a351642983--百度贴吧");
            //lineEdit7 = new QLineEdit;
            //label7->setBuddy(lineEdit7);
            //QHBoxLayout *NewBox1=new QHBoxLayout;
            //NewBox1->addWidget(label7);
            //NewBox1->addWidget(lineEdit7);

            //label8 = new QLabel(QString("amxx添加参数:"));
           // lineEdit8 = new QLineEdit;
           // label8->setBuddy(lineEdit8);
            //QHBoxLayout *NewBox2=new QHBoxLayout;
            //NewBox2->addWidget(label8);
            //NewBox2->addWidget(lineEdit8);

            //closeButton = new QPushButton("关闭");
            connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
            connect(lineEdit1, SIGNAL(textChanged(const QString&)), this, SLOT(enableButton1(const QString&)));
            //connect(lineEdit2, SIGNAL(textChanged(const QString&)), this, SLOT(enableButton2(const QString&)));
            connect(lineEdit3, SIGNAL(textChanged(const QString&)), this, SLOT(enableButton3(const QString&)));
            connect(lineEdit4, SIGNAL(textChanged(const QString&)), this, SLOT(enableButton4(const QString&)));
            connect(lineEdit5, SIGNAL(textChanged(const QString&)), this, SLOT(enableButton5(const QString&)));
            connect(Button5, SIGNAL(clicked()),this, SLOT(CompleteButton5()));
            connect(cmd, SIGNAL(readyRead()), this, SLOT(readOutput()));
            connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
            connect(Button1, SIGNAL(clicked()), this, SLOT(findClicked1()));
            connect(Button2, SIGNAL(clicked()), this, SLOT(findClicked2()));
            connect(Button3, SIGNAL(clicked()), this, SLOT(findClicked3()));
            connect(Button4, SIGNAL(clicked()), this, SLOT(findClicked4()));
            connect(Button6, SIGNAL(clicked()), this, SLOT(findClicked6()));
            //connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
            connect(caseCheckBox3, SIGNAL(clicked()),this, SLOT(CheckInclude()));
            connect(Button7,SIGNAL(clicked()),this,SLOT(startListen()));


            QHBoxLayout *topLeftLayout = new QHBoxLayout;
            topLeftLayout->addWidget(label);
            topLeftLayout->addWidget(lineEdit);
            topLeftLayout->addWidget(findButton);

            QHBoxLayout *topLeftLayout1 = new QHBoxLayout;
            topLeftLayout1->addWidget(label1);
            topLeftLayout1->addWidget(lineEdit1);
            topLeftLayout1->addWidget(Button1);

            QHBoxLayout *topLeftLayout2 = new QHBoxLayout;
            topLeftLayout2->addWidget(label2);
             QHBoxLayout *topLeftLayout2_1 = new QHBoxLayout;
            topLeftLayout2_1->addWidget(lineEdit2);
            //topLeftLayout2->addWidget(Button2);

            QHBoxLayout *topLeftLayout3 = new QHBoxLayout;
            topLeftLayout3->addWidget(label3);
            topLeftLayout3->addWidget(lineEdit3);
            topLeftLayout3->addWidget(Button3);

            QHBoxLayout *topLeftLayout4 = new QHBoxLayout;
            topLeftLayout4->addWidget(label4);
            topLeftLayout4->addWidget(lineEdit4);
            topLeftLayout4->addWidget(Button4);

            QHBoxLayout *topLeftLayout6 = new QHBoxLayout;
            topLeftLayout6->addWidget(label8);
            topLeftLayout6->addWidget(lineEdit5);
            topLeftLayout6->addWidget(Button6);

            QHBoxLayout *topLeftLayout5 = new QHBoxLayout;
            topLeftLayout5->addWidget(label5);


            QVBoxLayout *leftLayout = new QVBoxLayout;
            leftLayout->addLayout(topLeftLayout);
            leftLayout->addLayout(topLeftLayout1);
            leftLayout->addLayout(topLeftLayout2);
            leftLayout->addLayout(topLeftLayout2_1);
            leftLayout->addLayout(topLeftLayout5);
            leftLayout->addLayout(topLeftLayout3);
            leftLayout->addLayout(topLeftLayout4);
            leftLayout->addLayout(topLeftLayout6);



            QHBoxLayout *doubleLayout1 = new QHBoxLayout;
            QVBoxLayout *left1=new QVBoxLayout;
            QVBoxLayout *center1=new QVBoxLayout;
            QVBoxLayout *right1=new QVBoxLayout;
            left1->addWidget(label6);
            right1->addWidget(label6);
            center1->addWidget(Button5);

            doubleLayout1->addLayout(left1);
            doubleLayout1->addLayout(center1);
            doubleLayout1->addLayout(right1);


            QVBoxLayout *rightLayout = new QVBoxLayout;

            rightLayout->addStretch();

            QHBoxLayout *mainLayout = new QHBoxLayout;
            mainLayout->addLayout(leftLayout);
            mainLayout->addLayout(rightLayout);
            mainLayout->addWidget(textEdit2);
            QVBoxLayout *mainLayout1 = new QVBoxLayout;
            mainLayout1->addLayout(mainLayout);
            //mainLayout1->addLayout(NewBox1);
            //mainLayout1->addWidget(label8);
            //mainLayout1->addWidget(lineEdit8);
            QHBoxLayout *kidLayout = new QHBoxLayout;
            kidLayout->addWidget(caseCheckBox);
            kidLayout->addWidget(Button2);
            mainLayout1->addLayout(kidLayout);
            mainLayout1->addWidget(caseCheckBox1);
            mainLayout1->addWidget(caseCheckBox2);
            mainLayout1->addWidget(caseCheckBox3);
            mainLayout1->addLayout(doubleLayout1);
            QVBoxLayout *mainLayout2 = new QVBoxLayout;
            mainLayout2->addLayout(mainLayout1);
            mainLayout2->addWidget(label7);
            mainLayout2->addWidget(Button7);

            setLayout(mainLayout2);

            setWindowTitle("CS插件文件整合安装器 V2.1正式版");
            setFixedHeight(sizeHint().height());
            setFixedWidth(sizeHint().width());

            QDir *temp = new QDir;
            QString theaddress="D:/g_rank";
            if(!temp->exists(theaddress))
            {
                if(!temp->mkdir(theaddress))
                {
                       theaddress= "C:/g_rank";
                       temp->mkdir(theaddress);
                }
            }
            delete temp;
            QFile fs;
            fs.setFileName(QString("%1/CS_PluginTest.saver").arg(theaddress));
            if(!fs.exists())
            {
                fs.open(QIODevice::ReadOnly| QIODevice::Text);
                fs.close();
            }

            QTextCodec *code=QTextCodec::codecForName("UTF-8");
            fs.open(QIODevice::ReadOnly);
            QTextStream in(&fs);

            in.setCodec(code);
            QString line =QString(fs.readLine());
            //s1=QString(line.left(line.length()-2));

            lineEdit->setText(line.left(line.length()-2));
            line =QString(fs.readLine());
            lineEdit1->setText(line.left(line.length()-2));
            line =QString(fs.readLine());
            lineEdit5->setText(line);
            fs.close();
            infoshow+="欢迎使用本程序,这是个多功能的CS文件整理的软件\n\n支持:sma,amxx,amx,wad,wav,spr,mdl,bsp...\n\n只要在游戏父目录选择好游戏父目录的文件夹或者AMXX包,再把所有要安装的插件文件都丢到一个文件夹,在放置安装文件的文件夹选取该目录,点击执行,所有文件就能被一键整理和安装到CS父目录或者AMXX包的cstrike或者cstrike_schinese里面(中文目录安装)\n\n注意：所选择的CS必须安装AMXX才能被正常使用,该软件支持对sma的编译。\n--------------------------------------\nCS插件兴趣群：376642936";
            textshow();
}
void Dialog::startListen()
{
    g_startL=!g_startL;
    Button7->setText(g_startL?"结束监听":"开始监听");

}
void Dialog::listenning()
{
    if(g_startL)
    {
        infoshow.clear();
        infoshow+="欢迎使用本程序,这是个多功能的CS文件整理的软件\n\n支持:sma,amxx,amx,wad,wav,spr,mdl,bsp...\n\n只要在游戏父目录选择好游戏父目录的文件夹或者AMXX包,再把所有要安装的插件文件都丢到一个文件夹,在放置安装文件的文件夹选取该目录,点击执行,所有文件就能被一键整理和安装到CS父目录或者AMXX包的cstrike或者cstrike_schinese里面(中文目录安装)\n\n注意：所选择的CS必须安装AMXX才能被正常使用,该软件支持对sma的编译。\n--------------------------------------\nCS插件兴趣群：376642936";
        textshow();
        emit CompleteButton5();
    }
}

Dialog::~Dialog()
{
    QDir *temp = new QDir;
    QString theaddress="D:/g_rank";
    if(!temp->exists(theaddress))
    {
        if(!temp->mkdir(theaddress))
        {
               theaddress= "C:/g_rank";
               temp->mkdir(theaddress);
        }
    }
    delete temp;
    QFile fs;
    fs.setFileName(QString("%1/CS_PluginTest.saver").arg(theaddress));
    QTextCodec *code=QTextCodec::codecForName("UTF-8");
    fs.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream t(&fs);
    t.setCodec(code);
    t<<lineEdit->text()<<"\n"<<lineEdit1->text()<<"\n"<<lineEdit5->text();
    fs.close();
}

void Dialog::findClicked()
{

    QDir *temp = new QDir;
    QString theaddress="D:/g_rank";
    if(!temp->exists(theaddress))
    {
        if(!temp->mkdir(theaddress))
        {
               theaddress= "C:/g_rank";
               temp->mkdir(theaddress);
        }
    }
    delete temp;
    QFile fs;
    fs.setFileName(QString("%1/CS_PluginTest.saver").arg(theaddress));

        QString dir = QFileDialog::getExistingDirectory(this, QString("打开CS文件夹"),
                                                        lineEdit->text(),
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
        if(dir.length() == 0) {
                //QMessageBox::information(NULL, QString("注意"), QString("你没有选择任何文件夹."));
        } else {
                lineEdit->setText(dir);
                QTextCodec *code=QTextCodec::codecForName("UTF-8");
                fs.open(QIODevice::WriteOnly|QIODevice::Text);
                QTextStream t(&fs);
                t.setCodec(code);
                t<<lineEdit->text()<<"\n"<<lineEdit1->text()<<"\n"<<lineEdit5->text();
                fs.close();
        }


}
void Dialog::findClicked1()
{
    QDir *temp = new QDir;
    QString theaddress="D:/g_rank";
    if(!temp->exists(theaddress))
    {
        if(!temp->mkdir(theaddress))
        {
               theaddress= "C:/g_rank";
               temp->mkdir(theaddress);
        }
    }
    delete temp;
    QFile fs;
    fs.setFileName(QString("%1/CS_PluginTest.saver").arg(theaddress));
    QString path1;
    path1= QFileDialog::getExistingDirectory(this, QString("请选择存放有要进行整理文件的文件夹"),
                                             lineEdit1->text(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
       if(path1.length() == 0) {
              //实现弹窗的功能QMessageBox::information(NULL, QString("注意"), QString("你没有选择任何文件夹."));
       }
       else {
              lineEdit1->setText(path1);
              infoshow+="你选择了"+path1+"作为存放有要进行整理文件的文件夹";
              textshow();
              QTextCodec *code=QTextCodec::codecForName("UTF-8");
              fs.open(QIODevice::WriteOnly|QIODevice::Text);
              QTextStream t(&fs);
              t.setCodec(code);
              t<<lineEdit->text()<<"\n"<<lineEdit1->text()<<"\n"<<lineEdit5->text();
              fs.close();
      }

}
void Dialog::findClicked2()
{
//    QFileInfo fileinfo;
//    fileinfo=QFileInfo(lineEdit2->textFormat());
//    QString path = QFileDialog::getOpenFileName(this, QString("选择地图文件"), (lineEdit2->text().isEmpty())?"/":fileinfo.absolutePath(), QString("CS地图文件(*.bsp)"));
//    if(path.length() == 0) {
            //QMessageBox::information(NULL, QString("注意"), QString("你没有选择任何文件."));
 //   } else {
 //           lineEdit2->setText(path);
 //   }
    lineEdit5->setText("");
    QDir *temp = new QDir;
    QString theaddress="D:/g_rank";
    if(!temp->exists(theaddress))
    {
        if(!temp->mkdir(theaddress))
        {
               theaddress= "C:/g_rank";
               temp->mkdir(theaddress);
        }
    }
    delete temp;
    QFile fs;
    fs.setFileName(QString("%1/CS_PluginTest.saver").arg(theaddress));
    infoshow+="你将使用默认的inc字典对sma文件进行编译";
    textshow();
    QTextCodec *code=QTextCodec::codecForName("UTF-8");
    fs.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream t(&fs);
    t.setCodec(code);
    t<<lineEdit->text()<<"\n"<<lineEdit1->text()<<"\n"<<lineEdit5->text();
    fs.close();

}
void Dialog::findClicked3()
{
    QFileInfo fileinfo;
    fileinfo=QFileInfo(lineEdit3->text());
    QString path = QFileDialog::getOpenFileName(this, QString("选择文件"), (lineEdit3->text().isEmpty())?lineEdit->text():fileinfo.absolutePath(), QString("所有文件()"));
    if(path.length() == 0) {
            //QMessageBox::information(NULL, QString("注意"), QString("你没有选择任何文件."));
    } else {
        lineEdit3->setText(path);
        infoshow+="你选择了"+path+"作为额外文件";
        textshow();

    }

}
void Dialog::findClicked4()
{
    QString dir = QFileDialog::getExistingDirectory(this, QString("放置文件夹选择"),
                                                    lineEdit->text(),
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);
    if(dir.length() == 0) {
            //QMessageBox::information(NULL, QString("注意"), QString("你没有选择任何文件夹."));
    } else {
            lineEdit4->setText(dir);
            infoshow+="你选择了"+dir+"作为你想放置额外文件的目录";
            textshow();

    }
}
void Dialog::findClicked6()
{
    QString dir = QFileDialog::getExistingDirectory(this, QString("inc字典文件夹选择"),
                                                    lineEdit->text(),
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);
    if(dir.length() == 0) {
            //QMessageBox::information(NULL, QString("注意"), QString("你没有选择任何文件夹."));
    } else {
            lineEdit5->setText(dir);
            infoshow+="你选择了"+dir+"作为你想放置inc字典的目录";
            textshow();
            QDir *temp = new QDir;
            QString theaddress="D:/g_rank";
            if(!temp->exists(theaddress))
            {
                if(!temp->mkdir(theaddress))
                {
                       theaddress= "C:/g_rank";
                       temp->mkdir(theaddress);
                }
            }
            delete temp;
            QFile fs;
            fs.setFileName(QString("%1/CS_PluginTest.saver").arg(theaddress));
            QTextCodec *code=QTextCodec::codecForName("UTF-8");
            fs.open(QIODevice::WriteOnly|QIODevice::Text);
            QTextStream t(&fs);
            t.setCodec(code);
            t<<lineEdit->text()<<"\n"<<lineEdit1->text()<<"\n"<<lineEdit5->text();
            fs.close();

    }
}
void Dialog::textshow()
{
    infoshow+="\n\n";
    textEdit2->setText(infoshow);
    QTextCursor cursor =textEdit2->textCursor();
    cursor.movePosition(QTextCursor::End);
    textEdit2->setTextCursor(cursor);

}
void Dialog::enableFindButton(const QString &text)
{
      findButton->setDefault(!text.isEmpty());
}

void Dialog::enableButton1(const QString &text)
{
      Button1->setDefault(!text.isEmpty());
}

//void Dialog::enableButton2(const QString &text)
//{
//       Button2->setDefault(!text.isEmpty());
//}


void Dialog::enableButton3(const QString &text)
{
       Button3->setDefault(!text.isEmpty());
}

void Dialog::enableButton4(const QString &text)
{
      Button4->setDefault(!text.isEmpty());
}
void Dialog::enableButton5(const QString &text)
{
      Button6->setDefault(!text.isEmpty());
}
void Dialog::readOutput()
{
    QString done=cmd->readAll();
    if(done.contains("Done."))
    {
        g_done=true;
    }
    else
    {
        g_success=false;
    }
    infoshow+=done;
    textshow();

}
void Dialog::CheckInclude()
{
    if(caseCheckBox3->isChecked())
    {

        lineEdit5->setDisabled(true);
        Button6->setDisabled(true);

    }
    else
    {
        lineEdit5->setDisabled(false);
        Button6->setDisabled(false);

    }
}

void Dialog::CompleteButton5()
{
    if(lineEdit->text().length()==0)
    {
        QMessageBox::information(NULL, QString("注意"), QString("请选择一个CS目录来执行操作."));
        infoshow+="操作错误：没有选择想要进行整理的文件目录";
        textshow();
    }
    else{
        QString cstrike=caseCheckBox->isChecked()?QString("/cstrike_schinese/"):QString("/cstrike/");
        if(lineEdit1->text().length()==0&&lineEdit2->toPlainText().length()==0&& lineEdit3->text().length()==0)
        {
            QMessageBox::information(NULL, QString("注意"), QString("请在上述选择一个动作来执行操作."));
            infoshow+="操作错误：没有选择执行动作";
            textshow();
            return;
        }
        else if(lineEdit3->text().length()!=0&&lineEdit4->text().length()==0)
        {
            QMessageBox::information(NULL, QString("注意"), QString("请选择对应的文件放置目录来执行操作."));
            infoshow+="操作错误：没有选择想要进行整理的额外文件的放置目录";
            textshow();
            return;
        }
        if(lineEdit1->text().length()!=0)
        {
            lineEdit->setDisabled(true);
            lineEdit1->setDisabled(true);
            lineEdit2->setDisabled(true);
            lineEdit3->setDisabled(true);
            lineEdit4->setDisabled(true);
            lineEdit5->setDisabled(true);
            findButton->setDisabled(true);
            Button1->setDisabled(true);
            Button2->setDisabled(true);
            Button3->setDisabled(true);
            Button4->setDisabled(true);
            Button5->setDisabled(true);
            Button6->setDisabled(true);
            caseCheckBox->setDisabled(true);
            caseCheckBox1->setDisabled(true);
            caseCheckBox2->setDisabled(true);
            caseCheckBox3->setDisabled(true);
            //Button7->setDisabled(false);

            QDir *dir=new QDir(lineEdit1->text());
            QStringList filter;
            filter<<"*.amxx"<<"*.amx"<<"*.mdl"<<"*.spr"<<"*.wad"<<"*.bsp"<<"*.wav"<<"*.sma";
            dir->setNameFilters(filter);
            QList<QFileInfo> *fileinfo=new QList<QFileInfo>(dir->entryInfoList(filter));

            int countnum=fileinfo->count();
            g_countnum=countnum;
            g_sunumber=0;
            infoshow+=QString("对文件的安装信息进行扫描如下：\n总计:%1").arg(countnum)+"个文件需进行整理\n整理进行中...";
            textshow();

            for(int i=0;i<countnum;i++)
            {
                if(countnum==0)
                    break;
                QTime dieTime = QTime::currentTime().addMSecs(50);
                while( QTime::currentTime() < dieTime )
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

                g_success=true;
                g_done=false;

                QFile f(lineEdit->text()+QString("/cstrike/addons/amxmodx/configs/plugins.ini"));
                if(fileinfo->at(i).suffix()=="amxx"||fileinfo->at(i).suffix()=="amx")
                {

                    bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+QString("/cstrike/addons/amxmodx/plugins/")+fileinfo->at(i).fileName());
                    if(!check||caseCheckBox1->isChecked())
                    {
                        infoshow+="amx类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                        textshow();
                        QFile(lineEdit->text()+QString("/cstrike/addons/amxmodx/plugins/")+fileinfo->at(i).fileName()).remove();
                        QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+QString("/cstrike/addons/amxmodx/plugins/")+fileinfo->at(i).fileName());
                        infoshow+="amx类文件:"+fileinfo->at(i).fileName()+"安装成功";
                        textshow();

                    }
                    else if(check)
                    {
                        infoshow+="amx类文件:"+fileinfo->at(i).fileName()+"安装成功";
                        textshow();
                    }
            //?
                      bool g_datajudge;
                      g_datajudge=false;

                        f.open(QIODevice::ReadOnly);
               //         QTextStream t(&f);
                        QString line;
                        line=f.readLine();
                        while(!line.contains(fileinfo->at(i).fileName()))
                        {
                            if(!f.atEnd())
                            {
                                line=f.readLine();
                                line=line.replace(".amxx"," ");
                                char*  ch;

                                QByteArray ba =line.toLatin1();
                                ch=ba.data();
                                line = QString(QLatin1String(strtok(ch," ")));
                                if(line==fileinfo->at(i).baseName())
                                {
                                    g_datajudge=true;
                                    break;
                                }
                            }
                            else break;
                        };
                        f.close();

                        if(!g_datajudge)
                        {
                            f.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
                            QTextStream t(&f);
                            t<<"\n"<<fileinfo->at(i).fileName();
                            infoshow+="amx类文件:对"+fileinfo->at(i).fileName()+"进行写入plugins.ini文档";
                            textshow();
                            f.close();

                        }
                        else
                        {
                            infoshow+="文件名"+fileinfo->at(i).fileName()+"已存在plugins.ini文档中";
                            textshow();
                        }
                        if(caseCheckBox2->isChecked())
                        {
                            infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                            textshow();
                            QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                        }


                }
                if(fileinfo->at(i).suffix()=="sma")
                {
                    if(!caseCheckBox3->isChecked())
                    {
                            infoshow+="sma类文件:"+fileinfo->at(i).fileName()+"编译中...";
                            textshow();
                            QString Empty="";
                            QString run=QString("amxxpc \""+fileinfo->at(i).absoluteFilePath()+"\""+" -o\""+lineEdit->text()+QString("/cstrike/addons/amxmodx/plugins/")+fileinfo->at(i).baseName()+".amxx\""+((lineEdit5->text().length()==0)?(Empty):(Empty+" -i\""+lineEdit5->text()+"\"")));
                            cmd->start(run);
                            infoshow+=run;
                            textshow();
                            cmd->waitForFinished(99999);
                            QTime dieTime = QTime::currentTime().addMSecs(100);
                            while( QTime::currentTime() < dieTime )
                                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                            textshow();


                     }

                        bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+QString("/cstrike/addons/amxmodx/scripting/")+fileinfo->at(i).fileName());
                        if(!check||caseCheckBox1->isChecked())
                        {
                            infoshow+="sma类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                            textshow();
                            QFile(lineEdit->text()+QString("/cstrike/addons/amxmodx/scripting/")+fileinfo->at(i).fileName()).remove();
                            QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+QString("/cstrike/addons/amxmodx/scripting/")+fileinfo->at(i).fileName());
                            infoshow+="sma类文件:"+fileinfo->at(i).fileName()+"位置放置成功";
                            textshow();
                        }
                        else if(check)
                        {
                            infoshow+="sma类文件:"+fileinfo->at(i).fileName()+"位置放置成功";
                            textshow();
                        }


                        if(!caseCheckBox3->isChecked())
                        {
                            if(g_done)
                            {
                                bool g_datajudge;
                                g_datajudge=false;
                                f.open(QIODevice::ReadOnly);
                  //              QTextStream t(&f);
                                QString line;
                                line=f.readLine();
                                while(!line.contains(fileinfo->at(i).fileName()))
                                {
                                    if(!f.atEnd())
                                    {
                                        line=f.readLine();
                                        line=line.replace(".amxx"," ");
                                        char*  ch;
                                        QByteArray ba =line.toLatin1();
                                        ch=ba.data();
                                        line = QString(QLatin1String(strtok(ch," ")));
                                        //QMessageBox::question(this,"xx",line);
                                        if(line==fileinfo->at(i).baseName())
                                        {
                                            g_datajudge=true;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        break;
                                    }
                                };
                                f.close();

                                if(!g_datajudge)
                                {
                                    f.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
                                    QTextStream t(&f);
                                    t<<"\n"<<fileinfo->at(i).baseName()<<".amxx";
                                    infoshow+="sma类文件:对"+fileinfo->at(i).fileName()+"进行写入plugins.ini文档";
                                    textshow();
                                    f.close();
                                }
                                else
                                {
                                    infoshow+="文件名"+fileinfo->at(i).fileName()+"已存在plugins.ini文档中";
                                    textshow();
                                }
                                g_done=false;

                            }
                            else
                            {
                                infoshow+="sma类文件："+fileinfo->at(i).fileName()+"文件编译失败 原因：源代码错误";
                                textshow();
                               
                                g_success=false;
                            }

                            if(caseCheckBox2->isChecked()&&g_success)
                            {
                                if(g_success)
                                {
                                    infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                                    textshow();
                                    QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                                }
                                else
                                {
                                    infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                                    textshow();
                                }
                            }

                        }


                }
                QFile ss(lineEdit->text()+QString("/cstrike/addons/amxmodx/configs/maps.ini"));
                if(fileinfo->at(i).suffix()=="bsp")
                {



                    QDir *temp = new QDir;
                    bool exist = temp->exists(lineEdit->text()+cstrike+QString("maps"));
                    if(exist)
                    {
                        infoshow+="进行检测：父目录中maps文件夹存在,无需创建";
                        textshow();
                    }
                    else
                    {
                        infoshow+="进行检测：父目录中maps文件夹不存在，创建中...";
                        textshow();
                        bool ok = temp->mkdir(lineEdit->text()+cstrike+QString("maps"));
                        if( ok )
                        {
                            infoshow+="maps文件夹存创建成功";
                            textshow();
                        }
                        else
                        {
                            infoshow+="maps文件夹创建失败\n原因:父目录中不存在文件夹"+cstrike;
                            textshow();
                            g_success=false;
                        }
                    }

                    bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+QString(cstrike+"maps/")+fileinfo->at(i).fileName());
                    if(!check||caseCheckBox1->isChecked())
                    {
                        infoshow+="bsp类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                        textshow();
                        QFile(lineEdit->text()+QString(cstrike+"maps/")+fileinfo->at(i).fileName()).remove();
                        QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+QString(cstrike+"maps/")+fileinfo->at(i).fileName());
                        infoshow+="bsp类文件:"+fileinfo->at(i).fileName()+"安装成功";
                        textshow();
                    }
                    else if(check)
                    {
                        infoshow+="bsp类文件:"+fileinfo->at(i).fileName()+"安装成功";
                        textshow();
                    }



                    bool g_datajudge;
                    g_datajudge=false;
                    QString m_line;
                    ss.open(QIODevice::ReadOnly);
                    QTextStream t(&ss);
                    m_line=ss.readLine();
                    while(!m_line.contains(fileinfo->at(i).fileName()))
                    {
                        if(!ss.atEnd())
                        {
                            m_line=ss.readLine();
                            if(m_line==fileinfo->at(i).baseName())
                            {
                                g_datajudge=true;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }

                    }
                    ss.close();
                    if(!g_datajudge)
                    {
                        ss.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
                        QTextStream t(&ss);
                        m_line=ss.readLine();
                        t<<"\n"<<fileinfo->at(i).baseName();
                        ss.close();
                        infoshow+="bsp类文件:对"+fileinfo->at(i).fileName()+"进行写入maps.ini文档";
                        textshow();


                    }
                    else
                    {
                        infoshow+=fileinfo->at(i).fileName()+"提示：名字已存在maps.ini文档";
                        textshow();
                    }

                    if(caseCheckBox2->isChecked())
                    {
                        if(g_success)
                        {
                            infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                            textshow();
                            QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                        }
                        else
                        {
                            infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                            textshow();
                        }
                    }
                }
                if(fileinfo->at(i).suffix()=="mdl")
                {
                    QMessageBox::StandardButton rb =QMessageBox::question(NULL, QString("提醒"), QString("文件")+fileinfo->at(i).fileName()+QString("是否为人物模型"), QMessageBox::Yes |
                                                                          QMessageBox::No, QMessageBox::Yes);
                    if(rb == QMessageBox::Yes)
                    {
                        infoshow+="mdl类文件:"+fileinfo->at(i).fileName()+"为人物模型,下面进行安装整理";
                        textshow();

                        QDir *temp2 = new QDir;
                        bool exist2 = temp2->exists(lineEdit->text()+cstrike+QString("models/"));
                        if(exist2)
                        {
                            infoshow+="进行检测：父目录中models文件夹存在,无需创建";
                            textshow();
                        }
                        else
                        {
                            infoshow+="进行检测：父目录中models文件夹不存在，创建中...";
                            textshow();
                            bool ok = temp2->mkdir(lineEdit->text()+cstrike+QString("models/"));
                            if( ok )
                            {
                                infoshow+="models文件夹存创建成功";
                                textshow();

                            }
                            else
                            {
                                infoshow+="models文件夹创建失败\n原因:父目录中不存在文件夹"+cstrike;
                                textshow();
                                g_success=false;
                            }
                        }
                        QDir *temp1 = new QDir;
                        bool exist1 = temp1->exists(lineEdit->text()+cstrike+QString("models/player"));
                        if(exist1)
                        {
                            infoshow+="进行检测：父目录中models子目录player文件夹存在,无需创建";
                            textshow();

                        }
                        else
                        {
                            infoshow+="进行检测：父目录中models子目录player文件夹不存在，创建中...";
                            textshow();
                            bool ok = temp1->mkdir(lineEdit->text()+cstrike+QString("models/player"));
                            if( ok )
                            {
                                infoshow+="player文件夹存创建成功";
                                textshow();

                            }
                            else
                            {
                                infoshow+="player文件夹创建失败\n原因:父目录中不存在文件夹"+cstrike+"/models";
                                textshow();
                                g_success=false;
                            }
                        }
                        QDir *temp = new QDir;
                        bool exist = temp->exists(lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName());
                        if(exist)
                        {
                            infoshow+="进行检测：父目录中models子目录player文件夹中"+fileinfo->at(i).baseName()+"文件夹存在,无需创建";
                            textshow();

                        }
                        else
                        {
                            bool ok1 = temp->mkdir(lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName());
                            if( ok1 )
                            {
                                infoshow+=fileinfo->at(i).baseName()+"文件夹存创建成功";
                                textshow();

                            }
                            else
                            {
                                infoshow+=fileinfo->at(i).baseName()+"文件夹创建失败\n原因:父目录中不存在文件夹cstrike/models/player";
                                textshow();
                                g_success=false;
                            }
                        }




                     bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName()+"/"+fileinfo->at(i).fileName());
                            if(!check||caseCheckBox1->isChecked())
                            {
                                infoshow+="mdl类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                                textshow();

                                QFile(lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName()+"/"+fileinfo->at(i).fileName()).remove();
                                QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName()+"/"+fileinfo->at(i).fileName());
                                if(g_success)
                                    infoshow+="mdl类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                else infoshow+="文件安装失败"+fileinfo->at(i).fileName()+"";
                                textshow();
                            }
                            else if(check)
                            {
                                infoshow+="mdl类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                textshow();
                            }

                            if(caseCheckBox2->isChecked())
                            {
                                if(g_success)
                                {
                                    infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                                    textshow();
                                    QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                                }
                                else
                                {
                                    infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                                    textshow();
                                }
                            }
                      }
                    else
                    {
                        infoshow+="mdl类文件:"+fileinfo->at(i).fileName()+"为非人物模型,下面进行安装整理";
                        textshow();
                        bool isOK;
                        QString text1 = QInputDialog::getText(NULL, QString("非人物模型的输入"),
                                                             QString("请在文本框内输入")+fileinfo->at(i).fileName()+QString("在models所要放置的位置"),
                                                                           QLineEdit::Normal,
                                                                                                     "",
                                                                           &isOK);

                        if(isOK) {
                                infoshow+="输入检测：您输入要安装"+fileinfo->at(i).fileName()+"的位置为"+"models/"+text1;
                                textshow();
                                QDir *temp2 = new QDir;
                                bool exist2 = temp2->exists(lineEdit->text()+cstrike+QString("models/"));
                                if(exist2)
                                {
                                    infoshow+="进行检测：父目录中models文件夹存在,无需创建";
                                    textshow();

                                }
                                else
                                {
                                    infoshow+="进行检测：父目录中models文件夹不存在，创建中...";
                                    textshow();
                                    bool ok = temp2->mkdir(lineEdit->text()+cstrike+QString("models/"));
                                    if( ok )
                                    {
                                        infoshow+="models文件夹存创建成功";
                                        textshow();

                                    }
                                    else
                                    {
                                        infoshow+="models文件夹创建失败\n原因:父目录中不存在文件夹"+cstrike;
                                        textshow();
                                        g_success=false;
                                    }
                                }
                                QDir *temp = new QDir;
                                bool exist = temp->exists(lineEdit->text()+cstrike+QString("models/")+((text1.length()==0)?(""):(text1+("/"))));
                                if(exist)
                                {
                                    infoshow+="进行检测：父目录中models子目录"+text1+"文件夹存在,无需创建";
                                    textshow();


                                }
                                else
                                {
                                    infoshow+="进行检测：父目录中models子目录"+text1+"文件夹不存在,创建中...";
                                    textshow();
                                    bool ok = temp->mkdir(lineEdit->text()+cstrike+QString("models/")+((text1.length()==0)?(""):(text1+("/"))));
                                    if( ok )
                                    {
                                        infoshow+=text1+"文件夹存创建成功";
                                        textshow();

                                    }
                                    else
                                    {
                                        infoshow+=text1+"文件夹创建失败\n原因:不明";
                                        textshow();
                                        g_success=false;
                                    }
                                }



                                 bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("models/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName());
                                 if(!check||caseCheckBox1->isChecked())
                                 {
                                     infoshow+="mdl类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                                     textshow();

                                     QFile(lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName()+"/"+fileinfo->at(i).fileName()).remove();
                                     QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("models/player/")+fileinfo->at(i).baseName()+"/"+fileinfo->at(i).fileName());
                                     if(g_success)
                                        infoshow+="mdl类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                     else infoshow+="文件安装失败"+fileinfo->at(i).fileName();
                                     textshow();
                                 }
                                 else if(check)
                                 {
                                     infoshow+="mdl类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                     textshow();
                                 }

                                 if(caseCheckBox2->isChecked())
                                 {
                                     if(g_success)
                                     {
                                         infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                                         textshow();
                                         QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                                     }
                                     else
                                     {
                                         infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                                         textshow();
                                     }
                                 }

                        }

                    }
                }
                if(fileinfo->at(i).suffix()=="spr")
                {

                        bool isOK;
                        QString text1 = QInputDialog::getText(NULL, QString("spr文件位置的输入"),
                                                             QString("请在文本框内输入")+fileinfo->at(i).fileName()+QString("在sprites所要放置的位置"),
                                                                           QLineEdit::Normal,
                                                                           "",
                                                                           &isOK);
                        if(isOK) {
                            infoshow+="输入检测：您输入要安装"+fileinfo->at(i).fileName()+"的位置为"+"sprites/"+text1;
                            textshow();
                            QDir *temp2 = new QDir;
                            bool exist2 = temp2->exists(lineEdit->text()+cstrike+QString("sprites/"));
                            if(exist2)
                            {
                                infoshow+="进行检测：父目录中sprites文件夹存在,无需创建";
                                textshow();
                            }
                            else
                            {
                                infoshow+="进行检测：父目录中sprites文件夹不存在，创建中...";
                                textshow();
                                bool ok = temp2->mkdir(lineEdit->text()+cstrike+QString("sprites/"));
                                if( ok )
                                {
                                    infoshow+="sprites文件夹存创建成功";
                                    textshow();
                                }
                                else
                                {
                                    infoshow+="sprites文件夹创建失败\n原因:父目录中不存在文件夹"+cstrike;
                                    textshow();
                                }
                            }
                            QDir *temp = new QDir;
                            bool exist = temp->exists(lineEdit->text()+cstrike+QString("sprites/")+((text1.length()==0)?(""):(text1)));
                            if(exist)
                            {
                                infoshow+="进行检测：父目录中sprites子目录"+text1+"文件夹存在,无需创建";
                                textshow();

                            }
                            else
                            {
                                infoshow+="进行检测：父目录中sprites子目录"+text1+"文件夹不存在,创建中...";
                                textshow();
                                bool ok = temp->mkdir(lineEdit->text()+cstrike+QString("sprites/")+((text1.length()==0)?(""):(text1)));
                                if( ok )
                                {
                                    infoshow+=text1+"文件夹存创建成功";
                                    textshow();
                                }
                                else
                                {
                                    infoshow+=text1+"文件夹创建失败\n原因:不明";
                                    textshow();
                                    g_success=false;
                                }
                            }

                            bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("sprites/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName());
                            if(!check||caseCheckBox1->isChecked())
                            {
                                infoshow+="spr类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                                textshow();

                                QFile(lineEdit->text()+cstrike+QString("sprites/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName()).remove();
                                QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("sprites/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName());
                                infoshow+="spr类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                textshow();
                            }
                            else if(check)
                            {
                                infoshow+="spr类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                textshow();
                            }

                            if(caseCheckBox2->isChecked())
                            {
                                if(g_success)
                                {
                                    infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                                    textshow();
                                    QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                                }
                                else
                                {
                                    infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                                    textshow();
                                }
                            }
                        }


                }
                if(fileinfo->at(i).suffix()=="wav")
                {

                        bool isOK;
                        QString text1 = QInputDialog::getText(NULL, QString("wav文件位置的输入"),
                                                             QString("请在文本框内输入")+fileinfo->at(i).fileName()+QString("在sound所要放置的位置"),
                                                                           QLineEdit::Normal,
                                                                           "",
                                                                           &isOK);
                        if(isOK) {
                            infoshow+="输入检测：您输入要安装"+fileinfo->at(i).fileName()+"的位置为"+"sound/"+text1;
                            textshow();
                            QDir *temp2 = new QDir;
                            bool exist2 = temp2->exists(lineEdit->text()+cstrike+QString("sound/"));
                            if(exist2)
                            {
                                infoshow+="进行检测：父目录中sound文件夹存在,无需创建";
                                textshow();
                            }
                            else
                            {
                                infoshow+="进行检测：父目录中sound文件夹不存在，创建中...";
                                textshow();
                                bool ok = temp2->mkdir(lineEdit->text()+cstrike+QString("sound/"));
                                if( ok )
                                {
                                    infoshow+="sound文件夹存创建成功";
                                    textshow();

                                }
                                else
                                {
                                    infoshow+="sound文件夹创建失败\n原因:父目录中不存在文件夹"+cstrike;
                                    textshow();
                                    g_success=false;
                                }
                            }
                            QDir *temp = new QDir;
                            bool exist = temp->exists(lineEdit->text()+cstrike+QString("sound/")+((text1.length()==0)?(""):(text1)));
                            if(exist)
                            {
                                infoshow+="进行检测：父目录中sound子目录"+text1+"文件夹存在,无需创建";
                                textshow();
                            }
                            else
                            {
                                infoshow+="进行检测：父目录中sound子目录"+text1+"文件夹不存在,创建中...";
                                textshow();
                                bool ok = temp->mkdir(lineEdit->text()+cstrike+QString("sound/")+((text1.length()==0)?(""):(text1)));
                                if( ok )
                                {
                                    infoshow+=text1+"文件夹存创建成功";
                                    textshow();

                                }
                                else
                                {
                                    infoshow+=text1+"文件夹创建失败\n原因:不明";
                                    textshow();
                                    g_success=false;
                                }
                            }

                            bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("sound/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName());
                            if(!check||caseCheckBox1->isChecked())
                            {
                                infoshow+="wav类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                                textshow();

                                QFile(lineEdit->text()+cstrike+QString("sound/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName()).remove();
                                QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike+QString("sound/")+((text1.length()==0)?(""):(text1+("/")))+fileinfo->at(i).fileName());
                                infoshow+="wav类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                textshow();
                            }
                            else if(check)
                            {
                                infoshow+="wav类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                textshow();
                            }

                            if(caseCheckBox2->isChecked())
                            {
                                if(g_success)
                                {
                                    infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                                    textshow();
                                    QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                                }
                                else
                                {
                                    infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                                    textshow();
                                }
                            }
                        }


                }
                if(fileinfo->at(i).suffix()=="wad")
                {

                            bool check=QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike);
                            if(!check||caseCheckBox1->isChecked())
                            {
                                infoshow+="wad类文件:对"+fileinfo->at(i).fileName()+"进行覆盖安装";
                                textshow();

                                QFile(lineEdit->text()+cstrike+fileinfo->at(i).fileName()).remove();
                                QFile::copy(lineEdit1->text()+"/"+fileinfo->at(i).fileName() ,lineEdit->text()+cstrike);
                                infoshow+="wav类文件:"+fileinfo->at(i).fileName()+"安装成功";
                                textshow();
                            }
                            else if(check)
                            {
                                infoshow+="wad类文件:"+fileinfo->at(i).fileName()+"安装失败\n原因:父目录不存在"+cstrike;
                                 textshow();
                                 g_success=false;
                            }

                            if(caseCheckBox2->isChecked())
                            {
                                if(g_success)
                                {
                                    infoshow+="正对"+fileinfo->at(i).fileName()+"进行删除操作";
                                    textshow();
                                    QFile(lineEdit1->text()+"/"+fileinfo->at(i).fileName()).remove();
                                }
                                else
                                {
                                    infoshow+="文件安装失败，"+fileinfo->at(i).fileName()+"无法进行删除操作";
                                    textshow();
                                }
                            }

                }
                if(g_success&&g_countnum!=0)
                {
                    g_sunumber+=1;
                }
            };
        }
        if(lineEdit2->toPlainText().length()!=0)
        {
             QFile ww(lineEdit->text()+QString("/cstrike/addons/amxmodx/configs/amxx.cfg"));
             ww.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
             QTextStream t(&ww);
             t<<"\n"<<lineEdit2->toPlainText();
             infoshow+="写入amxx.cfg文件中..\n写入完成";
             textshow();
             ww.close();
             lineEdit2->clear();
        }
        if(lineEdit3->text().length()!=0)
        {
            if(lineEdit4->text().length()!=0)
            {
                QFileInfo fileinfo;
                fileinfo=QFileInfo(lineEdit3->text());
                bool check=QFile::copy(lineEdit3->text() ,lineEdit4->text()+QString("/")+fileinfo.fileName());
                if(!check||caseCheckBox1->isChecked())
                {
                    infoshow+="额外文件:对"+fileinfo.fileName()+"进行覆盖安装";
                    textshow();

                    QFile(lineEdit4->text()+"/"+fileinfo.fileName()).remove();
                    QFile::copy(lineEdit3->text() ,lineEdit4->text()+QString("/")+fileinfo.fileName());
                    infoshow+="额外文件:"+fileinfo.fileName()+"安装成功";
                    textshow();
                }
                else if(check)
                {
                    infoshow+="额外文件:"+fileinfo.fileName()+"安装成功";
                    textshow();
                }

                if(caseCheckBox2->isChecked())
                {
                    infoshow+="正对"+fileinfo.fileName()+"进行删除操作";
                    textshow();
                    QFile(lineEdit3->text()).remove();
                }

            }
            else
            {
                infoshow+="额外文件放置目录:您并没有进行选择";
                textshow();
            }
        }
        infoshow+=QString("总处理文件%1个：成功%2个 失败%3个\n--------------------------------------").arg(g_countnum).arg(g_sunumber).arg(g_countnum-g_sunumber);
        infoshow+="操作成功！请到游戏父目录查看是否已经安装完全,感谢你的使用。\n--------------------------------------";
        textshow();
        if(!g_startL)
            QMessageBox::information(NULL, QString("提醒"), QString("操作成功."));
        lineEdit->setDisabled(false);
        lineEdit1->setDisabled(false);
        lineEdit2->setDisabled(false);
        lineEdit3->setDisabled(false);
        lineEdit4->setDisabled(false);
        if(caseCheckBox3->isChecked())
        {

            lineEdit5->setDisabled(true);
            Button6->setDisabled(true);

        }
        else
        {
            lineEdit5->setDisabled(false);
            Button6->setDisabled(false);

        }
        findButton->setDisabled(false);
        Button1->setDisabled(false);
        Button2->setDisabled(false);
        Button3->setDisabled(false);
        Button4->setDisabled(false);
        Button5->setDisabled(false);
        caseCheckBox->setDisabled(false);
        caseCheckBox1->setDisabled(false);
        caseCheckBox2->setDisabled(false);
        caseCheckBox3->setDisabled(false);
        //Button7->setDisabled(true);
    }
    return;
}


/*
void MainWindow::on_pushButton_2_clicked()
{
    QDir *temp = new QDir;
    bool exist = temp->exists("D://temp");
    if(exist)
        QMessageBox::warning(this,QString("创建文件夹"),QString("文件夹已经存在！"));
    else
    {
        bool ok = temp->mkdir("D://temp");
        if( ok )
            QMessageBox::warning(this,QString("创建文件夹"),QString("文件夹创建成功！"));
    }
}
*/
