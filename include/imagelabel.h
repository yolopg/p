#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QObject>

class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    ImageLabel(QWidget*parent=nullptr):
        QLabel(parent),m_isImage1(true) // 默认显示第一张图片
    {

    }
public:
    void setPixmap(const QString&imagePath);
    void setImagePath(const QString&imagpath1,const QString&imagepath2);
    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void label_clicked();
private:
    QString m_pixmap1_path;
    QString m_pixmap2_path;
    bool m_isImage1;  // 用于标识当前显示的图片
    // QWidget interface
};

#endif // IMAGELABEL_H
