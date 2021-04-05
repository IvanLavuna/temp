//
// Created by ivan on 01.04.21.
//

#include "AudioWindow.h"

AudioWindow::AudioWindow(QWidget* parent):
	QMainWindow(parent), m_trackDuration(0)
{
	this->InitWindow();
	this->InitPlayer();
	this->InitPlaylist();
	this->InitScrollBar();
	this->InitAudioFiles();

	/// TODO : this functions must be run in separate thread
//	this->InitUntrackedAudioFiles();

	this->InitAudioProgress();
	this->InitAudioButtons();
}

void AudioWindow::InitWindow()
{
	this->setFixedSize(WINDOW_SZ_W, WINDOW_SZ_H);
}

void AudioWindow::InitPlayer()
{
	m_player = new QMediaPlayer;
	connect(m_player, &QMediaPlayer::durationChanged,this,&AudioWindow::SetDuration);
}

void AudioWindow::InitPlaylist()
{
	m_playList = new QMediaPlaylist(m_player);
	m_playList->setPlaybackMode(QMediaPlaylist::Loop);
}

void AudioWindow::InitScrollBar()
{
	m_scrollWidget  = new QWidget;
	m_scrollLayout  = new QVBoxLayout(m_scrollWidget);
	m_scroll = new QScrollArea(this);
	m_scroll->setBackgroundRole(QPalette::Dark);
	m_scroll->setGeometry(0,150,WINDOW_SZ_W / 4,WINDOW_SZ_H - 150);
	m_scroll->setWidgetResizable(true);
}

void AudioWindow::InitAudioFiles()
{
	m_playList->setParent(m_player);
	m_player->setPlaylist(m_playList);
	QDirIterator it(TRACKED_PATH, QStringList() << "*.mp3" << "*.m4a", QDir::Files, QDirIterator::Subdirectories);
	int index = 0;
	while (it.hasNext())
	{
		m_playList->addMedia(QUrl::fromLocalFile(it.next()));
		auto* btn = new ScrollButton(it.fileName());
		btn->SetIndex(index++);
		m_audioButtons.push_back(btn);
		m_audioButtons.back()->setFixedSize(WINDOW_SZ_W / 4 - 35,23);
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

void AudioWindow::InitUntrackedAudioFiles()
{
	QDirIterator it(UNTRACKED_PATH, QStringList() << "*.mp3" << "*.m4a", QDir::Files, QDirIterator::Subdirectories);
	int index = m_audioButtons.back()->GetIndex() + 1;
	while (it.hasNext())
	{
		m_playList->addMedia(QUrl::fromLocalFile(it.next()));
		auto* btn = new ScrollButton(it.fileName());
		btn->SetIndex(index++);
		m_audioButtons.push_back(btn);
		m_audioButtons.back()->setFixedSize(WINDOW_SZ_W / 4 - 35,23);
		m_scrollLayout->addWidget(m_audioButtons.back());
		connect(btn,SIGNAL(released()),this,SLOT(SetPlayingTrack()));
	}
}

void AudioWindow::InitAudioProgress()
{
	m_slider = new QSlider(Qt::Horizontal,this);
	m_slider->setGeometry(WINDOW_SZ_W / 4 + 10, WINDOW_SZ_H - 200, 500,20);
	connect(m_player, &QMediaPlayer::positionChanged, this, &AudioWindow::SetSliderPosition);
	connect(m_slider, &QSlider::sliderMoved, this, &AudioWindow::SetPlayer);
}

void AudioWindow::SetDuration(qint64 duration)
{
	m_trackDuration = duration;
	m_slider->setRange(0, duration);
}

void AudioWindow::SetSliderPosition(qint64 pos)
{
	m_slider->setValue(pos);
}

void AudioWindow::InitAudioButtons()
{
	m_playTrackBtn = new QPushButton(this);
	m_playTrackBtn->setGeometry(WINDOW_SZ_W / 4 + 50,WINDOW_SZ_H - 150,30,30);
	m_playTrackBtn->setIcon(QIcon(PLAY_ICON_PATH));
	m_playTrackBtn->setToolTip("play");
	connect(m_playTrackBtn, &QPushButton::released, m_player, &QMediaPlayer::play);


	m_stopTrackBtn = new QPushButton(this);
	m_stopTrackBtn->setGeometry(WINDOW_SZ_W / 4 + 100,WINDOW_SZ_H - 150,30,30);
	m_stopTrackBtn->setIcon(QIcon(STOP_ICON_PATH));
	m_stopTrackBtn->setToolTip("stop");

	connect(m_stopTrackBtn, &QPushButton::released, m_player, &QMediaPlayer::pause);


	m_nextTrackBtn = new QPushButton(this);
	m_nextTrackBtn->setGeometry(WINDOW_SZ_W / 4 + 150,WINDOW_SZ_H - 150,30,30);
	m_nextTrackBtn->setIcon(QIcon(NEXT_ICON_PATH));
	m_nextTrackBtn->setToolTip("next");
	connect(m_nextTrackBtn,&QPushButton::released, m_playList,&QMediaPlaylist::next);
}

void AudioWindow::SetPlayer(qint64 pos)
{
	m_player->setPosition(pos);
}








