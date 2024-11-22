#include "musicplayerthread.h"

MusicPlayerThread::MusicPlayerThread(QObject *parent)
    : QThread(parent), isPlaying(false), player(new QMediaPlayer(this)), audioOutput(new QAudioOutput(this))
{
    // 设置音频输出对象
    player->setAudioOutput(audioOutput);

    // 连接播放器的信号到线程内部的槽
    connect(player, &QMediaPlayer::stateChanged, this, &MusicPlayerThread::stateChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &MusicPlayerThread::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MusicPlayerThread::durationChanged);
}

MusicPlayerThread::~MusicPlayerThread()
{
    stopSong();
    delete player;
    delete audioOutput;
}

void MusicPlayerThread::setSong(const QString &filePath)
{
    currentSongPath_ = filePath;
    player->setSource(QUrl::fromLocalFile(filePath));
}

void MusicPlayerThread::stopSong()
{
    if (player->state() == QMediaPlayer::PlayingState) {
        player->stop();
    }
}

void MusicPlayerThread::playSong()
{
    if (!currentSongPath_.isEmpty()) {
        player->play();
        isPlaying = true;
    }
}

void MusicPlayerThread::pauseSong()
{
    if (isPlaying) {
        player->pause();
        isPlaying = false;
    }
}

void MusicPlayerThread::run()
{
    exec();  // 保持线程运行
}
