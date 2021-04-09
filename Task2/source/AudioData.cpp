//
// Created by ivan on 07.04.21.
//

#include "AudioData.h"

AudioData::AudioData(AudioEngine *engine, QWidget *parent) :
		QWidget(parent), m_engine(engine)
{
	/// init main layout
	m_mainLayout = new QGridLayout(this);
	
	/// init labels
	label["title"].general = new QLabel("title: ");
	label["title"].specific = new QLabel("...");
	label["title"].specific->setMaximumHeight(30);
	label["title"].specific->setStyleSheet("border: 2px dotted gray");
	m_mainLayout->addWidget(label["title"].general,0,0, 1 , 1);
	m_mainLayout->addWidget(label["title"].specific,0,1,1, 1);

	// genre
	label["genre"].general = new QLabel("genre: ");
	label["genre"].specific = new QLabel("...");
	label["genre"].specific->setMaximumHeight(30);
	label["genre"].specific->setStyleSheet("border: 2px dotted gray");
	m_mainLayout->addWidget(label["genre"].general,1,0, 1 , 1);
	m_mainLayout->addWidget(label["genre"].specific,1,1,1, 1);

	// album
	label["album"].general = new QLabel("album: ");
	label["album"].specific = new QLabel("...");
	label["album"].specific->setMaximumHeight(30);
	label["album"].specific->setStyleSheet("border: 2px dotted gray");
	m_mainLayout->addWidget(label["album"].general,2,0, 1 , 1);
	m_mainLayout->addWidget(label["album"].specific,2,1,1, 1);

	/// connection
	/** Not totally sure who must care about that : this class, or class
	    that will use this **/
	connect(m_engine,SIGNAL(currentTrackChanged(int)),this, SLOT(displayAudioMetaData(int)));
}

void AudioData::displayAudioMetaData(int pos)
{
	const AudioFile* file = m_engine->getAudioFile(pos);
	// title
	if(file->getTitle().isEmpty())
		label["title"].specific->setText("...");
	else
		label["title"].specific->setText(file->getTitle());

	// genre
	if(file->getGenre().isEmpty())
		label["genre"].specific->setText("...");
	else
		label["genre"].specific->setText(file->getGenre());

	// album
	if(file->getAlbum().isEmpty())
		label["album"].specific->setText("...");
	else
		label["album"].specific->setText(file->getAlbum());
}
