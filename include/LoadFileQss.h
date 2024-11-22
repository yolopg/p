#ifndef LOADFILEQSS_H
#define LOADFILEQSS_H
#include<QString>
#include<QFile>
#include <QApplication>
class LoadFileQss
{
public:
    static void setStyle(const QString&fileName)
    {
        QFile fileQss(fileName);
        fileQss.open(QFile::ReadOnly);
        qApp->setStyleSheet(fileQss.readAll());
        fileQss.close();
    }
};
#endif // LOADFILEQSS_H
