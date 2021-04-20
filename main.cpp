#include "mainwindow.h"
#include <QApplication>
#include <QMutex>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QMutex mutex;
void MessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString log_type;
    mutex.lock();
    switch (type) {
    case QtDebugMsg:
        log_type="[Debug] : ";
        break;
    case QtInfoMsg:
        log_type="[Info] : ";
        break;
    case QtWarningMsg:
        log_type="[Warning] : ";
        break;
    case QtCriticalMsg:
        log_type="[Critical] : ";
        break;
    case QtFatalMsg:
        log_type="[Fatal] : ";
        break;
    }
    QDateTime dateTime(QDateTime::currentDateTime());

    QString timeStr(dateTime.toString("dd-MM-yyyy HH:mm:ss:zzz"));
    QString contextString(QString("(%1, %2)").arg(context.file).arg(context.line));
    QFile out_file("logfile");
    out_file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream stream(&out_file);
    stream << log_type << " " << timeStr << " " << contextString << ": " << msg << endl;
    out_file.flush();
    out_file.close();
    mutex.unlock();
}
int main(int argc, char *argv[])
{
    qInstallMessageHandler(MessageHandler);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
