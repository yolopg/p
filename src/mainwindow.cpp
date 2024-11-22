#include "mainwindow.h"
#include "./froms/ui_mainwindow.h"
#include<QFile>
#include"LoadFileQss.h"
#include<QKeyEvent>
#include<QModelIndex>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_ptrmusic(MusicSql::GetInstance()) //获取MusicSql单例
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UI_Design();



    //QListWidgetitem点击更换QStackwidget的下标
    connect(ui->listWidget_online,&QListWidget::itemClicked,
            this,&MainWindow::on_listitem_clicked);
    connect(ui->listWidget_mymusic,&QListWidget::itemClicked,
            this,&MainWindow::on_listitem_clicked);
    //connect(ui->labelMylove,&ImageLabel::label_clicked,this,&MainWindow::on_labelMylove_clicked);
    connect(ui->bnt_stop,&QPushButton::clicked,this,[=](){
    });
    //添加歌曲测试
    connect(ui->bnt_addsong,&QPushButton::clicked,this,&MainWindow::on_addsongs_clicked);

#if 0

#endif

}
void MainWindow::UI_Design()
{
    ui->bnt_stop->setObjectName("bnt_stop");
    ui->bnt_last->setObjectName("bnt_last");
    ui->bnt_next->setObjectName("bnt_next");
    ui->bnt_stop->setFixedSize(30,30);
    ui->bnt_last->setFixedSize(30,30);
    ui->bnt_next->setFixedSize(30,30);
    int width= ui->bnt_stop->width();
    int height=ui->bnt_stop->height();
    QSize size(width,height);
    QIcon icon(":/icon/picture/play.png");
    ui->bnt_stop->setIcon(icon);
    ui->bnt_stop->setIconSize(size);

    icon.addFile(":/icon/picture/last.png");
    ui->bnt_last->setIcon(icon);
    ui->bnt_last->setIconSize(size);
    icon.addFile(":/icon/picture/next.png");
    ui->bnt_next->setIcon(icon);
    ui->bnt_next->setIconSize(size);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Ui_ListWidget(QListWidget *widget)
{
    int count = widget->count();
    if (count == 0) return; // 如果没有项目，直接返回

    int width = widget->width();

    for (int i = 0; i < count; i++) {
        widget->item(i)->setSizeHint(QSize(width,50)); // 设置项目的大小
    }
}

void MainWindow::on_listitem_clicked(QListWidgetItem *item)
{
    if (item) {
        QListWidget* listwidget = qobject_cast<QListWidget*>(sender());
        if (listwidget) {
            int row = listwidget->row(item);

            // 根据 row 设置当前的页面
            ui->stackedWidget->setCurrentIndex(row);

            // 在不同的页面加载不同的数据
            switch (row) {
            case 0:  // 例如，所有歌曲页面
                updateTableViewWithSongs();  // 更新表格数据
                break;
            case 1:  // 例如，喜欢的歌曲页面
                updateTableViewWithFavorites();  // 更新表格数据
                break;
            case 2:  // 例如，某个特定的页面
                updateTableViewWithSpecificSongs();  // 更新表格数据
                break;
            default:
                break;
            }
        }
    }
}

//添加测试
void MainWindow::on_addsongs_clicked()
{
    //test
    SongsInfo info(1,"水星记","郭顶","水星记","3:52","C:/Users/85713/Music/shuixingji.ogg");
    m_ptrmusic->InsertSong(&info);
}

void MainWindow::onTableClicked(const QModelIndex &index)
{
      // 获取数据库模型
      QSqlQueryModel*model=m_ptrmusic->GetModel();
      int row=index.row();
      QStringList list;
      for(int i=0;i<model->columnCount();i++)
      {
         list<<model->index(row,i).data().toString();
      }
      if (list.size() >= 6) {
          SongsInfo song(list[0].toInt(),   // id
                         list[1],             // name
                         list[2],             // artist
                         list[3],             // album
                         list[4],             // duration
                         list[5]);            // filePath
          qDebug()<<list;
          player=new MusicPlayer(this);
          player->addSong(song);
          player->playSong(0);
      }
}



//所有歌曲页面
void MainWindow::updateTableViewWithSongs()
{

    QTableView *tableView = findTableViewInStackedWidget(0);  // 获取对应页面的 QTableView
    if (tableView) {
        m_ptrmusic->displaySongsInTableView(tableView, "SELECT * FROM songs");  // 显示所有歌曲
    }
    connect(tableView,&QTableView::clicked,this,&MainWindow::onTableClicked);

}

//喜欢的歌曲页面
void MainWindow::updateTableViewWithFavorites()
{
    QTableView *tableView = findTableViewInStackedWidget(1);  // 获取对应页面的 QTableView
    if (tableView) {
        m_ptrmusic->displaySongsInTableView(tableView, "SELECT * FROM songs WHERE favorite = 1");  // 显示喜欢的歌曲
    }

}
//其他页面
void MainWindow::updateTableViewWithSpecificSongs()
{

}

QTableView* MainWindow::findTableViewInStackedWidget(int pageIndex)
{
    QWidget *pageWidget = ui->stackedWidget->widget(pageIndex);
    if (pageWidget) {
        return pageWidget->findChild<QTableView*>("tableView");
    }
    return nullptr;
}

//qss的测试F6功能
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_F6)
    {
    QFile fileQss("F:\\Qtstudy\\QtProject\\Music-cmake\\mainwindow.qss");
    if (fileQss.open(QIODevice::ReadOnly))
    {
        QString qss = fileQss.readAll();
        this->setStyleSheet(qss);  // 设置新的样式表
        fileQss.close();
        qDebug() << "QSS file applied!";

        // 强制重绘窗口
        this->repaint();
    }
    else
    {
        qDebug() << "Failed to open QSS file!";
    }
    }
    if(event->key()==Qt::Key_Space)
    {
        player->pause();
    }
    QMainWindow::keyPressEvent(event);
}

