//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOWINDOW_H
#define MEDIAPLAYERAPP_AUDIOWINDOW_H



#include "AudioBar.h"
#include "AudioManager.h"
#include "AudioData.h"

class AudioWindow : public QWidget
{	Q_OBJECT

private:
/// variables
	AudioEngine* 	m_engine = nullptr;

	AudioBar*  m_audioBar = nullptr;
	AudioManager* m_audioManager = nullptr;
	AudioData* m_audioData = nullptr;

/// initialisation
	void initEngine();
	void initAudioBar();
	void initAudioManager();
	void initAudioData();

private slots:

public:
	/// constructors / destructor
	explicit AudioWindow(QWidget* parent = nullptr);
	~AudioWindow() override;
signals:

};


#endif //MEDIAPLAYERAPP_AUDIOWINDOW_H
