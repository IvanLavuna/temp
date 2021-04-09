//
// Created by ivan on 07.04.21.
//

#include "AudioBar.h"

AudioBar::AudioBar(AudioEngine* engine, QWidget *parent) :
		QWidget(parent), m_engine(engine)
{/// initialising stuff

	/// initialising main layout
	m_mainLayout = new QVBoxLayout(this);

	/// initialising search  edit line
	m_searchLine = new QLineEdit();
	m_searchLine->setWindowIconText("Type to search");
	m_mainLayout->addWidget(m_searchLine);

	/// initialising scroll area stuff
	m_scrollArea   = new QScrollArea;
	m_scrollWidget = new QWidget;
	m_scrollLayout = new QVBoxLayout(m_scrollWidget);
	m_scrollArea->setWidgetResizable(true);
	m_scrollArea->setWidget(m_scrollWidget);
	m_scrollArea->setBackgroundRole(QPalette::Dark);
	m_mainLayout->addWidget(m_scrollArea);

	/// initialising buttons
	for (int i = 0; i < m_engine->mediaCount(); ++i)
		addItem(i);

	/// initialising connections
	connect(m_engine,SIGNAL(currentTrackChanged(int)), this, SLOT(changeCurrentButton(int)));
}

void AudioBar::changeCurrentButton(int pos)
{
	if(!m_activeBtn)
	{
		m_activeBtn = m_audioButtons[pos];
		m_activeBtn->setStyleSheet("background-color: #D3D3D3; border: 2px dotted black");
	}
	else
	{
		m_activeBtn->setStyleSheet("background-color: white");
		m_activeBtn = m_audioButtons[pos];
		m_activeBtn->setStyleSheet("background-color: #D3D3D3; border: 2px dotted black");
	}
}

void AudioBar::addItem(int pos)
{
	const AudioFile* file = m_engine->getAudioFile(pos);
	auto* audioBtn = new IndexedButton(file->getTitle().toStdString().substr(0,16).c_str());
	audioBtn->SetIndex(pos);
	QSizePolicy policy;

	policy.setHorizontalPolicy(QSizePolicy::Policy::Expanding);
	audioBtn->setSizePolicy(policy);
	audioBtn->setToolTip(file->getFilePath());

	connect(audioBtn, SIGNAL(released(int)), m_engine, SLOT(setPlayingTrack(int)));
	connect(audioBtn, SIGNAL(released(int)), this, SLOT(changeCurrentButton(int)));

	m_audioButtons.push_back(audioBtn);
	m_scrollLayout->addWidget(audioBtn);
}






