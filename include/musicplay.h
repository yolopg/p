#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QList>
#include "songsinfo.h"
#include "musicplayerthread.h"

class MusicPlayer : public QObject
{
    Q_OBJECT

public:
    explicit MusicPlayer(QObject *parent = nullptr);
    ~MusicPlayer();

    void setSongList(const QList<SongsInfo>& songs);
    void addSong(const SongsInfo& song);
    void removeSong(int index);

    void playSong(int index);
    void play();
    void pause();
    void previousTrack();
    void nextTrack();

    QString currentSongPath() const;
    QMediaPlayer::PlaybackState playbackState() const;
    QList<SongsInfo> getSongList() const;

signals:
    void stateChanged(QMediaPlayer::PlaybackState state);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void songListChanged();

private slots:
    void onStateChanged(QMediaPlayer::PlaybackState state);
    void onPositionChanged(qint64 position);
    void onDurationChanged(qint64 duration);
    void onPlayRequest();
    void onPauseRequest();
    void onStopRequest();

private:
    MusicPlayerThread *playerThread;  // 音乐播放线程
    QList<SongsInfo> songList;  // 歌曲列表
    int currentSongIndex;  // 当前播放歌曲的索引
    QString currentSongPath_;  // 当前播放歌曲的路径
};

#endif // MUSICPLAYER_H
