//
// Created by ivan on 01.04.21.
//

#include "AudioWindow.h"

AudioWindow::AudioWindow(QWidget* parent):
	QMainWindow(parent)
{
	this->InitWindow();
	this->InitPlayer();
	this->InitPlaylist();
	this->InitScrollBar();
	this->InitAudioFiles();
}

void AudioWindow::InitWindow()
{
	this->setFixedSize(WINDOW_SZ_W, WINDOW_SZ_H);
}

void AudioWindow::InitPlayer()
{
	m_player = new QMediaPlayer;
}

void AudioWindow::InitPlaylist()
{
	m_playList = new QMediaPlaylist(m_player);
}

void AudioWindow::InitScrollBar()
{
	m_scrollWidget  = new QWidget;
	m_scrollLayout  = new QVBoxLayout(m_scrollWidget);
	m_scroll = new QScrollArea(this);
	m_scroll->setBackgroundRole(QPalette::Dark);
	m_scroll->setGeometry(0,150,WINDOW_SZ_W / 4,WINDOW_SZ_H - 150);
}

void AudioWindow::InitAudioFiles()
{
	m_playList->setParent(m_player);
	m_player->setPlaylist(m_playList);
	QDirIterator it(TRACKED_PATH, QStringList() << "*.mp3", QDir::Files, QDirIterator::Subdirectories);
	int index = 0;
	while (it.hasNext())
	{
		m_playList->addMedia(QUrl::fromLocalFile(it.next()));
		auto* btn = new ScrollButton(it.fileName());
		btn->SetIndex(index++);
		m_audioButtons.push_back(btn);
		m_audioButtons.back()->setFixedSize(WINDOW_SZ_W / 4 - 35,20);
		m_scrollLayout->addWidget(m_audioButtons.back());
		connect(btn,SIGNAL(released()),this,SLOT(SetPlayingTrack()));
	}
	m_scroll->setWidget(m_scrollWidget);
}

void AudioWindow::SetPlayingTrack()
{
	auto* button = qobject_cast<ScrollButton*>(sender());
	if (button)
	{
		m_playList->setCurrentIndex(button->GetIndex());
		PlayAudio();
	}
	else
	{
		qDebug() << ERROR_MESSAGE("qobject_cast failed.");
	}
}

void AudioWindow::PlayAudio()
{
	m_player->play();
}



