//
// Created by ivan on 01.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOWINDOW_H
#define MEDIAPLAYERAPP_AUDIOWINDOW_H

#define WINDOW_SZ_H 600
#define WINDOW_SZ_W 700

/// TODO : rewrite this implementation to be cross-platform
#define TRACKED_PATH "/home/" + qgetenv("USER") + "/Music"
#define UNTRACKED_PATH "/home/" + qgetenv("USER")
#define PLAY_ICON_PATH "../resource/play.png"
#define STOP_ICON_PATH "../resource/stop.png"
#define NEXT_ICON_PATH "../resource/next.png"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)
#define ERROR_MESSAGE(DESC) ("error: " AT "\n" "Description: " DESC "\n")

#include "ScrollButton.h"

class AudioWindow : public QMainWindow
{
	Q_OBJECT
private:
	/// player
	QMediaPlayer*     m_player = nullptr;
	QMediaPlaylist*   m_playList = nullptr;

	/// scroll area
	QScrollArea*	  m_scroll = nullptr;
	QWidget*		  m_scrollWidget = nullptr;
	QVBoxLayout*	  m_scrollLayout = nullptr;
	QVector<ScrollButton*>  m_audioButtons;

	/// slider bar (track progress )
	QSlider*	 m_slider = nullptr;


	/// duration of current playing track
	qint64 		  m_trackDuration;

	/// buttons
	QPushButton*  m_stopTrackBtn;
	QPushButton*  m_nextTrackBtn;
	QPushButton*  m_playTrackBtn;

	/** methods **/
	/** initialisation **/
	void InitWindow();
	void InitPlayer();
	void InitPlaylist();
	void InitScrollBar();
	/** initialises audio files and connects buttons  with
	 * [SetPlayingTrack()] slots **/
	void InitAudioFiles();
	void InitUntrackedAudioFiles();
	void InitAudioProgress();
	void InitAudioButtons();

private slots:
	/// TODO : rewrite it with int parameter
	void SetPlayingTrack();
	void PlayAudio();
	void SetDuration(qint64 duration);
	void SetSliderPosition(qint64 pos);
	void SetPlayer(qint64 pos);
protected:

public:
	explicit AudioWindow(QWidget *parent = nullptr);

signals:

};


#endif //MEDIAPLAYERAPP_AUDIOWINDOW_H
