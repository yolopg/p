#include "songsinfo.h"
#include <QDebug>

// 构造函数
SongsInfo::SongsInfo(int id, const QString& title, const QString& artist,
                     const QString& album, const QString& duration, const QString& filePath)
    : m_id(id), m_title(title), m_artist(artist), m_album(album),
    m_duration(duration), m_filePath(filePath)
{
    // 如果 id 为 -1，表示数据库会自动处理 id
    if (m_id == -1) {
        m_id = 0;  // 默认设置为 0 或其他合适值，表示该字段由数据库自动生成
    }
}

// 获取歌曲 ID
int SongsInfo::getId() const {
    return m_id;
}

void SongsInfo::setId(int id) {
    m_id = id;
}

// 获取歌曲标题
QString SongsInfo::getTitle() const {
    return m_title;
}

void SongsInfo::setTitle(const QString& title) {
    m_title = title;
}

// 获取歌手
QString SongsInfo::getArtist() const {
    return m_artist;
}

void SongsInfo::setArtist(const QString& artist) {
    m_artist = artist;
}

// 获取专辑
QString SongsInfo::getAlbum() const {
    return m_album;
}

void SongsInfo::setAlbum(const QString& album) {
    m_album = album;
}

// 获取时长
QString SongsInfo::getDuration() const {
    return m_duration;
}

void SongsInfo::setDuration(const QString& duration) {
    m_duration = duration;
}

// 获取歌曲文件路径
QString SongsInfo::getFilePath() const {
    return m_filePath;
}

void SongsInfo::setFilePath(const QString& filePath) {
    m_filePath = filePath;
}

// 打印歌曲信息
void SongsInfo::printSongInfo() const {
    qDebug() << "ID: " << m_id;
    qDebug() << "Title: " << m_title;
    qDebug() << "Artist: " << m_artist;
    qDebug() << "Album: " << m_album;
    qDebug() << "Duration: " << m_duration;
    qDebug() << "File Path: " << m_filePath;
}
