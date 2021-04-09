//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOMANAGER_H
#define MEDIAPLAYERAPP_AUDIOMANAGER_H

#include "AudioEngine.h"

class AudioManager : public QWidget
{
Q_OBJECT
private:
	AudioEngine* m_engine   = nullptr;

	/// this widget layout
	QVBoxLayout* m_mainLayout   = nullptr;

	/// slider
	QSlider*     m_slider   = nullptr;

	/// buttons
	QHBoxLayout* m_buttonsLayout = nullptr;
	QWidget* 	 m_buttonsWidget = nullptr;
	QPushButton* m_pauseBtn      = nullptr;
	QPushButton* m_nextBtn  = nullptr;
	QPushButton* m_playBtn  = nullptr;

private slots:
	void setSliderValue(qint64);
	void setTrackPosition(int);

public slots:

public:
	explicit AudioManager(AudioEngine* engine, QWidget* parent = nullptr);

signals:

};


#endif //MEDIAPLAYERAPP_AUDIOMANAGER_H
