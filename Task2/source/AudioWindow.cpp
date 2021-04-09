//
// Created by ivan on 07.04.21.
//


#include "AudioWindow.h"

/// constructor / destructor
AudioWindow::AudioWindow(QWidget* parent):
	QWidget(parent)
{
	initEngine();
	initAudioBar();
	initAudioManager();
	initAudioData();

}

AudioWindow::~AudioWindow()
{
	delete m_engine;
}

/// initialisation
void AudioWindow::initEngine()
{
	m_engine = new AudioEngine();
	m_engine->generatePlaylist(TRACKED_PATH);
}

void AudioWindow::initAudioBar()
{
	m_audioBar = new AudioBar(m_engine, this);
	m_audioBar->setGeometry(0,75,WINDOW_SZ_W / 3,WINDOW_SZ_H - 50);

}

void AudioWindow::initAudioManager()
{
	m_audioManager = new AudioManager(m_engine,this);
	m_audioManager->setGeometry(WINDOW_SZ_W / 3 + 20,WINDOW_SZ_H - 150,350,80);
}

void AudioWindow::initAudioData()
{
	m_audioData = new AudioData(m_engine, this);
	m_audioData->setGeometry(WINDOW_SZ_W / 3 + 20,WINDOW_SZ_H / 3,375,180);
}




