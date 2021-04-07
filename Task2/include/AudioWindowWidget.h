//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOWINDOWWIDGET_H
#define MEDIAPLAYERAPP_AUDIOWINDOWWIDGET_H


#include "ScrollButton.h"


class AudioWindowWidget : public QWidget
{
Q_OBJECT
private:
	struct MetaLabel{
		QLabel* general;
		QLabel* specific;
	};

	/// player
	QMediaPlayer*     m_player = nullptr;
	QMediaPlaylist*   m_playList = nullptr;

	/// scroll area
	QScrollArea*	  m_scroll = nullptr;
	QWidget*		  m_scrollWidget = nullptr;
	QVBoxLayout*	  m_scrollLayout = nullptr;
	QVector<ScrollButton*>  m_audioButtons;

	/// slider bar (track progress )
	QSlider*	  m_slider = nullptr;

	/// buttons
	QPushButton*  m_curAudioBtn = nullptr;

	QPushButton*  m_stopTrackBtn = nullptr;
	QPushButton*  m_nextTrackBtn = nullptr;
	QPushButton*  m_playTrackBtn = nullptr;

	/// button - button meta data map
	QMap<QPushButton*, TagLib::FileRef*> m_btnInfoMap;

	/// audio meta labels map
	QMap<QString, MetaLabel> m_audioDataLabel;


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
	void InitAudioDataLabels();

	/** core **/
	void DisplayAudioMetaData();
	void ChangeCurrentBtn(QPushButton* newBtn);
private slots:
	/// TODO : rewrite it with int parameter
	void SetPlayingTrack();
	void SetPlayingTrack(int pos);
	void PlayAudio();
	void SetDuration(qint64 duration);
	void SetSliderPosition(qint64 pos);
	void SetPlayer(qint64 pos);
protected:

public:
	explicit AudioWindowWidget(QWidget *parent = nullptr);

signals:

};


#endif //MEDIAPLAYERAPP_AUDIOWINDOWWIDGET_H
