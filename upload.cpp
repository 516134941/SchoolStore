#include "upload.h"
#include "ui_upload.h"
#include <QFileDialog>

UpLoad::UpLoad(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::UpLoad)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    loadSize = 4*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    tcpClient = new QTcpSocket(this);
    setWindowTitle("申请开店");
    //当连接服务器成功时，发出connected()信号，我们开始传送文件
    connect(tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));

    //当有数据发送成功时，我们更新进度条
    connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,
            SLOT(updateClientProgress(qint64)));

    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(displayError(QAbstractSocket::SocketError)));

    //开始使”发送“按钮不可用
    ui->sendButton->setEnabled(false);
}

UpLoad::~UpLoad()
{
    delete ui;
}
void UpLoad::openFile()   //打开文件
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        ui->sendButton->setEnabled(true);
        ui->clientStatusLabel->setText(tr("打开文件 %1 成功！")
                                       .arg(fileName));
    }
}

void UpLoad::send()   //连接到服务器，执行发送
{
    ui->sendButton->setEnabled(false);
    bytesWritten = 0;
    //初始化已发送字节为0
    ui->clientStatusLabel->setText(tr("连接中..."));
    tcpClient->connectToHost("127.0.0.1",
                             6666);//连接
}

void UpLoad::startTransfer()  //实现文件大小等信息的发送
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file error!";
        return;
    }

    //文件总大小
    totalBytes = localFile->size();

    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);

    //依次写入总大小信息空间，文件名大小信息空间，文件名
    sendOut << qint64(0) << qint64(0) << currentFileName;

    //这里的总大小是文件名大小等信息和实际文件大小的总和
    totalBytes += outBlock.size();

    sendOut.device()->seek(0);
    //返回outBolock的开始，用实际的大小信息代替两个qint64(0)空间
    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));

    //发送完头数据后剩余数据的大小
    bytesToWrite = totalBytes - tcpClient->write(outBlock);

    ui->clientStatusLabel->setText(tr("已连接"));
    outBlock.resize(0);
}

//更新进度条，实现文件的传送
void UpLoad::updateClientProgress(qint64 numBytes)
{
    //已经发送数据的大小
    bytesWritten += (int)numBytes;

    if(bytesToWrite > 0) //如果已经发送了数据
    {
        //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
        //就发送剩余数据的大小
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));

        //发送完一次数据后还剩余数据的大小
        bytesToWrite -= (int)tcpClient->write(outBlock);

        //清空发送缓冲区
        outBlock.resize(0);

    } else {
        localFile->close(); //如果没有发送任何数据，则关闭文件
    }

    //更新进度条
    ui->clientProgressBar->setMaximum(totalBytes);
    ui->clientProgressBar->setValue(bytesWritten);

    if(bytesWritten == totalBytes) //发送完毕
    {
        ui->clientStatusLabel->setText(tr("传送文件 %1 成功").arg(fileName));
        localFile->close();
        tcpClient->close();
    }
}

void UpLoad::displayError(QAbstractSocket::SocketError) //显示错误
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();
    ui->clientProgressBar->reset();
    ui->clientStatusLabel->setText(tr("客户端就绪"));
    ui->sendButton->setEnabled(true);
}


void UpLoad::on_openButton_clicked() //打开按钮
{
    openFile();
}

void UpLoad::on_sendButton_clicked() //发送按钮
{
    send();
}
