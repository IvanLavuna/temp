//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOENGINE_H
#define MEDIAPLAYERAPP_AUDIOENGINE_H

#include "AudioFile.h"
#include "IndexedButton.h"

/// Who must clean memory after this class is an open question
class AudioEngine : public QObject
{	Q_OBJECT

private:
	/** variables **/
	QVector<AudioFile*>  m_audioFiles;
	QMediaPlaylist*      m_playlist   = nullptr;
	QMediaPlayer* 	     m_player     = nullptr;

	/** methods **/
	/** initialisation **/
	void initSignals();
public:
	/** Constructors / destructor **/
	AudioEngine();
	~AudioEngine() = default;

public slots:
	/// fills audioFiles and playlist
	void generatePlaylist(QString&& path);
	void generatePlaylist(QString& path);

	/// set
	void setLoopPlayBackMode();
	void setRandomPlayBackMode();
	void setSequentialPlayBackMode();
	void setPlayingTrack(int index);
	void setMuted(bool muted);
	void setPlayBackRate(qreal rate);
	void setPosition(qint64 pos);
	void setVolume(int volume);

	/// core
	/** clears playlist and audioFiles **/
	void clearPlayList();
	void play();
	void stop();
	void pause();
	void next();
	void previous();

	void addAudio(QMediaContent&&);
	void addAudio(QMediaContent&);
	void removeAudio(int pos);

	// TODO : fix this unlogical slot-method
	/// This slot can only be called by signals!
	void setCheatingPlayingTrack();
signals:
	void currentTrackChanged(int index);
	void durationChanged(qint64 duration);
	void mutedChanged(bool muted);
	void playbackRateChanged(qreal rate);
	/** position - means in audio bytes array **/
	void positionChanged(qint64 pos);
	void volumeChanged(int volume);
 	void audioChanged(int, int);
 	void audioRemoved(int, int);
	void audioInserted(int, int);

public:
	/// get
	qint64  duration() const noexcept;
	qreal   playbackRate() const noexcept;
	qint64  position() const noexcept;
	int     volume() const noexcept;
	const AudioFile * getAudioFile(int pos) const;
	QVector<AudioFile* > getAudioFiles() const;
};


#endif //MEDIAPLAYERAPP_AUDIOENGINE_H
