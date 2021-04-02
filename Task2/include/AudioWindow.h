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
	QMediaPlayer*     m_player;
	QMediaPlaylist*   m_playList;

	/// scroll area
	QScrollArea*	  m_scroll;
	QWidget*		  m_scrollWidget;
	QVBoxLayout*	  m_scrollLayout;
	QVector<ScrollButton*>  m_audioButtons;

	/** methods **/
	void InitWindow();
	void InitPlayer();
	void InitPlaylist();
	void InitScrollBar();
	void InitAudioFiles();
	void InitUntrackedAudioFiles();
private slots:
	void SetPlayingTrack();
	void PlayAudio();

protected:

public:
	explicit AudioWindow(QWidget *parent = nullptr);
signals:

};


#endif //MEDIAPLAYERAPP_AUDIOWINDOW_H
