#include "musicsql.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QMutexLocker>
#include <QApplication>
#include <QFile>

QMutex MusicSql::m_mutex;  // 初始化静态锁对象
MusicSql* MusicSql::ptrmusicsql = nullptr;  // 初始化静态指针

// 构造函数
MusicSql::MusicSql(QObject *parent) : QObject(parent), songinfo(nullptr)
{
    // 进行数据库初始化
    Init();
}

// 初始化数据库连接
void MusicSql::Init()
{
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << "Available drivers:" << drivers;

    if (!drivers.contains("QSQLITE")) {
        qWarning() << "SQLite driver not available!";
    }

    // 打开数据库连接
    m_db = QSqlDatabase::addDatabase("QSQLITE");  // 使用 SQLite 数据库
    QString path = "C:/Users/85713/DataGripProjects/my_sqlbase/music.db";  // 你可以根据需求更改路径
    m_db.setDatabaseName(path);  // 设置数据库名称
    qDebug() << "Database path: " << path;

    if (!m_db.open()) {
        qWarning() << "Error opening database:" << m_db.lastError();
    } else {
        qDebug() << "Database opened successfully!";
    }

    // 创建数据库表
    createTable();
}

// 创建歌曲信息表
bool MusicSql::createTable()
{
    // 创建表的 SQL 语句
    QString createTableSql = "CREATE TABLE IF NOT EXISTS songs ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "title TEXT, "
                             "artist TEXT, "
                             "duration INTEGER, "
                             "album TEXT, "
                             "filePath TEXT);";

    // 直接执行 SQL 语句
    if (!m_db.exec(createTableSql).isValid()) {
        qWarning() << "Failed to create table:" << m_db.lastError();
        return false;
    }
    return true;
}

// 测试数据库连接
void MusicSql::test()
{
    qDebug() << "Testing database connection";
    SongsInfo info(1,"love","jay","haha","3:50","F://");
    InsertSong(&info);
}

// 添加歌曲
bool MusicSql::InsertSong(SongsInfo* info)
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    QSqlQuery query;
    query.prepare("INSERT INTO songs (title, artist, duration, album, filePath) "
                  "VALUES (:title, :artist, :duration, :album, :filePath)");

    query.bindValue(":title", info->getTitle());
    query.bindValue(":artist", info->getArtist());
    query.bindValue(":duration", info->getDuration());
    query.bindValue(":album", info->getAlbum());
    query.bindValue(":filePath", info->getFilePath());

    if (!query.exec()) {
        qWarning() << "Failed to insert data:" << query.lastError();
    } else {
        qDebug() << "Data inserted successfully!";
    }
    return true;
}

// 删除歌曲
bool MusicSql::DeleteSong(SongsInfo* info)
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    // 拼接删除 SQL 语句
    QString deleteSql = QString("DELETE FROM songs WHERE id = %1;").arg(info->getId());

    // 执行 SQL 语句
    if (!m_db.exec(deleteSql).isValid()) {
        qWarning() << "Delete song failed:" << m_db.lastError();
        return false;
    }
    return true;
}

// 查询所有歌曲
QList<SongsInfo> MusicSql::queryAllSongs()
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    QList<SongsInfo> songsList;

    // 执行查询所有歌曲的 SQL 语句
    if (!m_db.exec("SELECT * FROM songs;").isValid()) {
        qWarning() << "Query failed:" << m_db.lastError();
        return songsList;
    }

    // 遍历结果集
    QSqlQuery query(m_db);
    while (query.next()) {
        SongsInfo song;
        song.setId(query.value(0).toInt());
        song.setTitle(query.value(1).toString());
        song.setArtist(query.value(2).toString());
        song.setDuration(query.value(3).toString());
        song.setAlbum(query.value(4).toString());
        song.setFilePath(query.value(5).toString());

        songsList.append(song);
    }
    return songsList;
}

// 根据歌曲 ID 查询单首歌曲
SongsInfo MusicSql::querySongById(int songId)
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    SongsInfo song;
    // 拼接查询 SQL 语句
    QString selectSql = QString("SELECT * FROM songs WHERE id = %1;").arg(songId);

    // 执行查询 SQL 语句
    QSqlQuery query(m_db);
    if (query.exec(selectSql) && query.next()) {
        song.setId(query.value(0).toInt());
        song.setTitle(query.value(1).toString());
        song.setArtist(query.value(2).toString());
        song.setDuration(query.value(3).toString());
        song.setAlbum(query.value(4).toString());
        song.setFilePath(query.value(5).toString());
    }
    return song;
}

// 更新歌曲信息
bool MusicSql::updateSong(SongsInfo* info)
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    // 拼接更新 SQL 语句
    QString updateSql = QString("UPDATE songs SET title = '%1', artist = '%2', duration = %3, album = '%4', filePath = '%5' "
                                "WHERE id = %6;")
                            .arg(info->getTitle().replace("'", "''"))
                            .arg(info->getArtist().replace("'", "''"))
                            .arg(info->getDuration().toInt())
                            .arg(info->getAlbum().replace("'", "''"))
                            .arg(info->getFilePath().replace("'", "''"))
                            .arg(info->getId());

    // 执行 SQL 语句
    if (!m_db.exec(updateSql).isValid()) {
        qWarning() << "Update song failed:" << m_db.lastError();
        return false;
    }
    return true;
}

// 批量删除歌曲
bool MusicSql::deleteSongsByIds(const QList<int>& songIds)
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    // 拼接批量删除 SQL 语句
    QString deleteSql = "DELETE FROM songs WHERE id = %1;";

    for (int i = 0; i < songIds.size(); ++i) {
        QString sql = deleteSql.arg(songIds[i]);
        if (!m_db.exec(sql).isValid()) {
            qWarning() << "Failed to delete song with id:" << songIds[i];
            return false;
        }
    }
    return true;
}

void MusicSql::displaySongsInTableView(QTableView *tableView, const QString &queryStr)
{
    QMutexLocker locker(&m_mutex);  // 确保线程安全

    // 创建一个 QSqlQueryModel，并执行传入的查询语句
    model = new QSqlQueryModel(this);
    model->setQuery(queryStr, QSqlDatabase::database());  // 执行查询语句

    // 设置模型到 QTableView
    tableView->setModel(model);
}
