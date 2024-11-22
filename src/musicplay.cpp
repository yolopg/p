#include"musicplay.h"

MusicPlayer::MusicPlayer(QObject *parent)
    : QObject(parent), currentSongIndex(-1), playerThread(new MusicPlayerThread(this))
{
    // 连接信号与槽
    connect(playerThread, &MusicPlayerThread::stateChanged, this, &MusicPlayer::onStateChanged);
    connect(playerThread, &MusicPlayerThread::positionChanged, this, &MusicPlayer::onPositionChanged);
    connect(playerThread, &MusicPlayerThread::durationChanged, this, &MusicPlayer::onDurationChanged);

    connect(this, &MusicPlayer::onPlayRequest, playerThread, &MusicPlayerThread::playSong);
    connect(this, &MusicPlayer::onPauseRequest, playerThread, &MusicPlayerThread::pauseSong);
    connect(this, &MusicPlayer::onStopRequest, playerThread, &MusicPlayerThread::stopSong);
}

MusicPlayer::~MusicPlayer()
{
    delete playerThread;
}

void MusicPlayer::setSongList(const QList<SongsInfo>& songs)
{
    songList = songs;
    emit songListChanged();
}

void MusicPlayer::addSong(const SongsInfo& song)
{
    songList.append(song);
    emit songListChanged();
}

void MusicPlayer::removeSong(int index)
{
    if (index >= 0 && index < songList.size()) {
        songList.removeAt(index);
        emit songListChanged();
    }
}

void MusicPlayer::playSong(int index)
{
    if (index >= 0 && index < songList.size()) {
        currentSongIndex = index;
        currentSongPath_ = songList[index].getFilePath();  // 假设 `SongsInfo` 类有 `path` 字段
        playerThread->setSong(currentSongPath_);
        emit onPauseRequest();  // 发出播放请求
    }
}

void MusicPlayer::play()
{
    if (currentSongIndex >= 0) {
        emit onPlayRequest();  // 发出播放请求
    }
}

void MusicPlayer::pause()
{
    emit onPauseRequest();  // 发出暂停请求
}

void MusicPlayer::previousTrack()
{
    if (currentSongIndex > 0) {
        currentSongIndex--;
        playSong(currentSongIndex);
    }
}

void MusicPlayer::nextTrack()
{
    if (currentSongIndex < songList.size() - 1) {
        currentSongIndex++;
        playSong(currentSongIndex);
    }
}

QString MusicPlayer::currentSongPath() const
{
    return currentSongPath_;
}

QMediaPlayer::PlaybackState MusicPlayer::playbackState() const
{
    // 获取当前播放状态
    //return playerThread->player->state();
}

QList<SongsInfo> MusicPlayer::getSongList() const
{
    return songList;
}

void MusicPlayer::onStateChanged(QMediaPlayer::PlaybackState state)
{
    emit stateChanged(state);
}

void MusicPlayer::onPositionChanged(qint64 position)
{
    emit positionChanged(position);
}

void MusicPlayer::onDurationChanged(qint64 duration)
{
    emit durationChanged(duration);
}
