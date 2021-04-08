//
// Created by ivan on 07.04.21.
//

#include "AudioEngine.h"

/// constructors / destructors
AudioEngine::AudioEngine()
{
	m_player = new QMediaPlayer;
	m_playlist = new QMediaPlaylist(m_player);
	m_player->setPlaylist(m_playlist);
	m_audioFiles = QVector<AudioFile*>();

	initSignals();

}

/// initialisation
void AudioEngine::initSignals()
{
	/// playlist signals
	connect(m_playlist, SIGNAL(currentIndexChanged(int)), this, SIGNAL(currentTrackChanged(int)));
	connect(m_playlist, SIGNAL(mediaChanged(int,int)),this, SIGNAL(audioChanged(int,int)));
	connect(m_playlist, SIGNAL(mediaInserted(int,int)),this, SIGNAL(audioInserted(int,int)));
	connect(m_playlist, SIGNAL(mediaRemoved(int,int)),this, SIGNAL(audioRemoved(int,int)));

/** possible connections to be extended
	connect(m_playlist, SIGNAL(currentMediaChanged(const QMediaContent &)), this, SIGNAL());
	connect(m_playlist, SIGNAL(loadFailed()), this,  SIGNAL());
	connect(m_playlist, SIGNAL(loaded()),this,SIGNAL());
	connect(m_playlist, SIGNAL(mediaAboutToBeInserted(int, int)),this, SIGNAL());
	connect(m_playlist, SIGNAL(mediaAboutToBeRemoved(int, int)),this, SIGNAL());
	connect(m_playlist, SIGNAL(playbackModeChanged(QMediaPlaylist::PlaybackMode)),this, SIGNAL());
**/

	/// player signals
	connect(m_player, SIGNAL(durationChanged(qint64)),this, SIGNAL(durationChanged(qint64)));
	connect(m_player, SIGNAL(mutedChanged(bool)),this, SIGNAL(mutedChanged(bool)));
	connect(m_player, SIGNAL(playbackRateChanged(qreal)),this, SIGNAL(playbackRateChanged(qreal)));
	connect(m_player, SIGNAL(positionChanged(qint64)),this, SIGNAL(positionChanged(qint64)));
	connect(m_player, SIGNAL(volumeChanged(int)),this, SIGNAL(volumeChanged(int)));

/** possible connections to be extended
	connect(m_player, SIGNAL(audioAvailableChanged(bool available)),this,SIGNAL());
	connect(m_player, SIGNAL(audioRoleChanged(QAudio::Role role)),this,SIGNAL());
	connect(m_player, SIGNAL(bufferStatusChanged(int percentFilled)),this,SIGNAL());
	connect(m_player, SIGNAL(currentMediaChanged(const QMediaContent &media)),this,SIGNAL());
	connect(m_player, SIGNAL(customAudioRoleChanged(const QString &role)),this,SIGNAL());
	connect(m_player, SIGNAL(error(QMediaPlayer::Error error)),this,SIGNAL());
	connect(m_player, SIGNAL(mediaChanged(const QMediaContent &media)),this,SIGNAL());
	connect(m_player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus status)),this,SIGNAL());
	connect(m_player, SIGNAL(seekableChanged(bool seekable)),this,SIGNAL());
	connect(m_player, SIGNAL(stateChanged(QMediaPlayer::State state)),this,SIGNAL());
	connect(m_player, SIGNAL(videoAvailableChanged(bool videoAvailable)),this,SIGNAL());
**/

}

/// public slots
void AudioEngine::setLoopPlayBackMode()
{
	m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
}

void AudioEngine::setRandomPlayBackMode()
{
	m_playlist->setPlaybackMode(QMediaPlaylist::Random);
}

void AudioEngine::setSequentialPlayBackMode()
{
	m_playlist->setPlaybackMode(QMediaPlaylist::Sequential);
}

void AudioEngine::generatePlaylist(QString &&path)
{
	QDirIterator it(TRACKED_PATH,QStringList() << "*.mp3" << "*.m4a", QDir::Files, QDirIterator::Subdirectories);
	for( ; it.hasNext(); )
	{
		m_audioFiles.push_back(new AudioFile(it.next()));
		m_playlist->addMedia(QUrl::fromLocalFile(m_audioFiles.back()->getFilePath()));
		qInfo() << m_audioFiles.back()->getFilePath() << '\n';
	}
}

void AudioEngine::generatePlaylist(QString &path)
{
	QDirIterator it(TRACKED_PATH,QStringList() << "*.mp3" << "*.m4a", QDir::Files, QDirIterator::Subdirectories);
	for( ; it.hasNext(); it.next())
	{
		m_playlist->addMedia(QUrl::fromLocalFile(it.filePath()));
		m_audioFiles.push_back(new AudioFile(it.filePath()));
	}
}

void AudioEngine::clearPlayList()
{
	m_audioFiles.clear();
	m_player->stop();
	m_playlist->clear();
}

void AudioEngine::play()
{
	m_player->play();
}

void AudioEngine::stop()
{
	m_player->stop();
}

void AudioEngine::next()
{
	m_playlist->next();
}

void AudioEngine::pause()
{
	m_player->pause();
}

void AudioEngine::previous()
{
	m_playlist->previous();
}

/// set
void AudioEngine::setPlayingTrack(int index)
{
	if(index < m_playlist->mediaCount())
	{
		m_playlist->setCurrentIndex(index);
		/// there are no needs to emit this signal, because I call m_playlist->setCurrentIndex(index);
		/// that is connected to desired signal
//		emit currentTrackChanged(index);
	}
	else
	{
		qDebug() << ERROR_MESSAGE("Index out of range.");
	}

}

void AudioEngine::setMuted(bool muted)
{
	m_player->setMuted(muted);
}

void AudioEngine::setPlayBackRate(qreal rate)
{
	m_player->setPlaybackRate(rate);
}

void AudioEngine::setPosition(qint64 pos)
{
	m_player->setPosition(pos);
}

void AudioEngine::setVolume(int volume)
{
	m_player->setVolume(volume);
}

/// get
qint64 AudioEngine::duration() const noexcept
{
	return m_player->duration();
}

qreal AudioEngine::playbackRate() const noexcept
{
	return m_player->playbackRate();
}

qint64 AudioEngine::position() const noexcept
{
	return m_player->position();
}

int AudioEngine::volume() const noexcept
{
	return m_player->volume();
}

void AudioEngine::addAudio(QMediaContent&& mediaContent)
{
	m_playlist->addMedia(mediaContent);
}

void AudioEngine::addAudio(QMediaContent & mediaContent)
{
	m_playlist->addMedia(mediaContent);
}

void AudioEngine::removeAudio(int pos)
{
	m_playlist->removeMedia(pos);
}

const AudioFile *AudioEngine::getAudioFile(int pos) const
{
	if(pos > -1 && pos < m_audioFiles.size())
	{
		return m_audioFiles[pos];
	}
	else
	{
		qDebug() << ERROR_MESSAGE("Index out of range.");
		return nullptr;
	}
}

QVector<AudioFile *> AudioEngine::getAudioFiles() const
{
	return m_audioFiles;
}

void AudioEngine::setCheatingPlayingTrack()
{
	auto* btn = qobject_cast<IndexedButton*>(sender());
	if(btn)
	{
		m_playlist->setCurrentIndex(btn->GetIndex());
	}
	else
	{
		qDebug() << ERROR_MESSAGE("qobject_cast failed.");
	}
}


