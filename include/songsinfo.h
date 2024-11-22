#ifndef SONGSINFO_H
#define SONGSINFO_H

#include <QString>

class SongsInfo
{
public:
    // 默认构造函数
    SongsInfo(int id = -1, const QString& title = "", const QString& artist = "",
              const QString& album = "", const QString& duration = "", const QString& filePath = "");

    // 获取和设置歌曲 ID
    int getId() const;
    void setId(int id);

    // 获取和设置歌曲标题
    QString getTitle() const;
    void setTitle(const QString& title);

    // 获取和设置歌手
    QString getArtist() const;
    void setArtist(const QString& artist);

    // 获取和设置专辑
    QString getAlbum() const;
    void setAlbum(const QString& album);

    // 获取和设置时长
    QString getDuration() const;
    void setDuration(const QString& duration);

    // 获取和设置歌曲文件路径
    QString getFilePath() const;
    void setFilePath(const QString& filePath);

    // 打印歌曲信息
    void printSongInfo() const;

private:
    int m_id;           // 歌曲 ID
    QString m_title;    // 歌曲标题
    QString m_artist;   // 歌手
    QString m_album;    // 专辑
    QString m_duration; // 时长
    QString m_filePath; // 歌曲文件路径
};

#endif // SONGSINFO_H
