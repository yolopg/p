#ifndef MUSICPLAYERTHREAD_H
#define MUSICPLAYERTHREAD_H

#include <QThread>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QString>

class MusicPlayerThread : public QThread
{
    Q_OBJECT

public:
    explicit MusicPlayerThread(QObject *parent = nullptr);
    ~MusicPlayerThread();

    void setSong(const QString &filePath);  // 设置要播放的歌曲路径
    void stopSong();  // 停止歌曲
    void playSong();  // 播放歌曲
    void pauseSong(); // 暂停歌曲

signals:
    void stateChanged(QMediaPlayer::PlaybackState state);  // 播放状态变化
    void positionChanged(qint64 position);  // 播放进度变化
    void durationChanged(qint64 duration);  // 播放时长变化

    void playRequested();  // 播放请求
    void pauseRequested(); // 暂停请求
    void stopRequested();  // 停止请求

protected:
    void run() override;

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString currentSongPath_;
    bool isPlaying;  // 判断当前是否在播放
};

#endif // MUSICPLAYERTHREAD_H
