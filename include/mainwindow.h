#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"musicsql.h"
#include <QMainWindow>
#include<QListWidget>
#include<QPushButton>
#include<QMediaPlayer>
#include"musicplay.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
public:
    void Ui_ListWidget(QListWidget*widget);
    void updateTableViewWithSongs();  // 更新表格数据
    void updateTableViewWithFavorites();
    void  updateTableViewWithSpecificSongs();
    QTableView* findTableViewInStackedWidget(int page);
private:
    Ui::MainWindow *ui;
    MusicSql*m_ptrmusic;
    MusicPlayer*player;
private:
    void UI_Design();
    void loadSongList();//加载歌曲列表
private slots:
    void  on_listitem_clicked(QListWidgetItem*item);
    void on_addsongs_clicked();
    void onTableClicked(const QModelIndex &index);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
