//
// Created by ivan on 07.04.21.
//

#include "AudioBarWidget.h"

AudioBarWidget::AudioBarWidget(AudioEngine* engine, QWidget *parent) :
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
	m_mainLayout->addWidget(m_scrollArea);

	/// initialising buttons
	/// TODO : ended coding here
	const QVector<AudioFile*> files = m_engine->getAudioFiles();
	int index = 0;
	for (auto & file: files)
	{
		auto* audioBtn = new IndexedButton(file->getTitle());
		audioBtn->SetIndex(index++);
		connect(audioBtn, SIGNAL(released()), m_engine, SLOT(setCheatingPlayingTrack()));
		m_audioButtons.push_back(audioBtn);
		m_scrollLayout->addWidget(audioBtn);
	}
	m_engine->play();
}
