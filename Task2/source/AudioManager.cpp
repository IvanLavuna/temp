//
// Created by ivan on 07.04.21.
//

#include "AudioManager.h"

AudioManager::AudioManager(AudioEngine *engine, QWidget *parent) :
		QWidget(parent), m_engine(engine)
{
	/// init layout
	m_mainLayout = new QVBoxLayout(this);

	/// init slider
	m_slider = new QSlider(Qt::Horizontal);
	m_slider->setRange(0,10000);
	m_mainLayout->addWidget(m_slider);

	connect(m_engine, SIGNAL(positionChanged(qint64)), this, SLOT(setSliderValue(qint64)));
	connect(m_slider, SIGNAL(sliderMoved(int)),this, SLOT(setTrackPosition(int)));

	/// init buttons layout
	m_buttonsWidget = new QWidget;
	m_buttonsLayout = new QHBoxLayout(m_buttonsWidget);
	m_mainLayout->addWidget(m_buttonsWidget);

	/// init buttons
	m_playBtn = new QPushButton;
	m_playBtn->setIcon(QIcon(PLAY_ICON_PATH));
	m_playBtn->setToolTip("play");
	m_playBtn->setFixedSize(30,30);
	m_buttonsLayout->addWidget(m_playBtn);
	connect(m_playBtn, &QPushButton::released, m_engine, &AudioEngine::play);


	m_pauseBtn = new QPushButton;
	m_pauseBtn->setIcon(QIcon(STOP_ICON_PATH));
	m_pauseBtn->setToolTip("stop");
	m_pauseBtn->setFixedSize(30,30);
	m_buttonsLayout->addWidget(m_pauseBtn);
	connect(m_pauseBtn, &QPushButton::released, m_engine, &AudioEngine::pause);


	m_nextBtn = new QPushButton;
	m_nextBtn->setIcon(QIcon(NEXT_ICON_PATH));
	m_nextBtn->setToolTip("next");
	m_nextBtn->setFixedSize(30,30);
	m_buttonsLayout->addWidget(m_nextBtn);
	connect(m_nextBtn, &QPushButton::released, m_engine, &AudioEngine::next);

}

void AudioManager::setSliderValue(qint64 pos)
{
	m_slider->setValue((int)((long double)pos / (long double)m_engine->duration() * m_slider->maximum() ));
}

void AudioManager::setTrackPosition(int pos)
{
	m_engine->setPosition(pos * m_engine->duration() / m_slider->maximum());
}



