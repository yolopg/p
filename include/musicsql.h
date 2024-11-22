#ifndef MUSICSQL_H
#define MUSICSQL_H

#include "songsinfo.h"
#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QTableView>
#include <QMutex>
#include <QMutexLocker>
#include <QSqlError>
#include <QStandardItemModel>
#include<QSqlQueryModel>
class MusicSql : public QObject
{
    Q_OBJECT

public:
    static MusicSql* ptrmusicsql;  // 单例对象指针

    // 获取单例对象
    static MusicSql* GetInstance()
    {
        QMutexLocker locker(&m_mutex);  // 使用 QMutexLocker 自动锁定和解锁
        if (nullptr == ptrmusicsql) {
            ptrmusicsql = new MusicSql;
        }
        return ptrmusicsql;
    }

    // 初始化数据库
    void Init();

    // 测试数据库连接
    void test();

public:
    // 添加歌曲
    bool InsertSong(SongsInfo* info);

    // 删除歌曲
    bool DeleteSong(SongsInfo* info);

    // 显示所有歌曲
    void displaySongsInTableView(QTableView* tableView,const QString &queryStr);

    // 查询所有歌曲
    QList<SongsInfo> queryAllSongs();

    // 根据歌曲ID查询单首歌曲
    SongsInfo querySongById(int songId);

    // 更新歌曲信息
    bool updateSong(SongsInfo* info);

    // 批量删除歌曲
    bool deleteSongsByIds(const QList<int>& songIds);

    //获取数据查询模型
    QSqlQueryModel* GetModel()
    {
        return model;
    }
private:
    // 构造函数私有，防止外部创建对象
    explicit MusicSql(QObject *parent = nullptr);

    // 创建数据库表
    bool createTable();

    // 数据库对象
    QSqlDatabase m_db;

    // 查询对象
    QSqlQuery m_query;

    // 存储歌曲信息
    SongsInfo *songinfo;

    //创建一个数据模型
    QSqlQueryModel *model;//

    // 线程安全锁对象
    static QMutex m_mutex;  // 用于保护数据库操作
};

#endif // MUSICSQL_H
