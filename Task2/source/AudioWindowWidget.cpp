//
// Created by ivan on 07.04.21.
//


#include "AudioWindowWidget.h"


AudioWindowWidget::AudioWindowWidget(QWidget* parent):
		QWidget(parent)
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
	this->InitAudioDataLabels();
}

/// Initialisation
void AudioWindowWidget::InitWindow()
{
	this->setFixedSize(WINDOW_SZ_W, WINDOW_SZ_H);
}

void AudioWindowWidget::InitPlayer()
{
	m_player = new QMediaPlayer;
	connect(m_player, &QMediaPlayer::durationChanged,this, &AudioWindowWidget::SetDuration);
}

void AudioWindowWidget::InitPlaylist()
{
	m_playList = new QMediaPlaylist(m_player);
	m_playList->setPlaybackMode(QMediaPlaylist::Loop);
	connect(m_playList, SIGNAL(currentIndexChanged(int)), this, SLOT(SetPlayingTrack(int)));
}

void AudioWindowWidget::InitScrollBar()
{
	m_scrollWidget  = new QWidget;
	m_scrollLayout  = new QVBoxLayout(m_scrollWidget);
	m_scroll = new QScrollArea(this);
	m_scroll->setBackgroundRole(QPalette::Dark);
	m_scroll->setGeometry(0,150,WINDOW_SZ_W / 4,WINDOW_SZ_H - 150);
	m_scroll->setWidgetResizable(true);
}

void AudioWindowWidget::InitAudioFiles()
{
	m_playList->setParent(m_player);
	m_player->setPlaylist(m_playList);
	QDirIterator it(TRACKED_PATH, QStringList() << "*.mp3" << "*.m4a", QDir::Files, QDirIterator::Subdirectories);
	int index = 0;
	while (it.hasNext())
	{
		// adding audio to playlist
		m_playList->addMedia(QUrl::fromLocalFile(it.next()));
		// audio meta information
		auto* audioInfo = new TagLib::FileRef(it.filePath().toStdString().c_str());
		ScrollButton *btn;

		if(!audioInfo->tag()->title().isEmpty())
		{
			/// TODO : fix encoding of some characters to be proper on the screen
			btn = new ScrollButton(audioInfo->tag()->title().substr(0,16).toCString());
		}
		else
		{
			btn = new ScrollButton(it.fileName().toStdString().substr(0,16).c_str());
		}

		// mapping audioBtn to audioInfo
		m_btnInfoMap[btn] = audioInfo;

		btn->SetIndex(index++);

		m_audioButtons.push_back(btn);
		m_audioButtons.back()->setFixedSize(WINDOW_SZ_W / 4 - 35,23);
		m_scrollLayout->addWidget(m_audioButtons.back());
		connect(btn,SIGNAL(released()),this,SLOT(SetPlayingTrack()));
	}
	m_scroll->setWidget(m_scrollWidget);

}

void AudioWindowWidget::InitUntrackedAudioFiles()
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

void AudioWindowWidget::InitAudioButtons()
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

void AudioWindowWidget::InitAudioDataLabels()
{
	// title
	m_audioDataLabel["title"].general = new QLabel("title: ", this);
	m_audioDataLabel["title"].general->setGeometry(200,200,50,25);
	m_audioDataLabel["title"].specific = new QLabel("...", this);
	m_audioDataLabel["title"].specific->setGeometry(260, 200,350,25);
	m_audioDataLabel["title"].specific->setStyleSheet("border: 2px dotted gray");

	// genre
	m_audioDataLabel["genre"].general = new QLabel("genre: ", this);
	m_audioDataLabel["genre"].general->setGeometry(200,240,50,25);
	m_audioDataLabel["genre"].specific = new QLabel("...", this);
	m_audioDataLabel["genre"].specific->setGeometry(260, 240,350,25);
	m_audioDataLabel["genre"].specific->setStyleSheet("border: 2px dotted gray");

	// album
	m_audioDataLabel["album"].general = new QLabel("album: ", this);
	m_audioDataLabel["album"].general->setGeometry(200,280,50,25);
	m_audioDataLabel["album"].specific = new QLabel("...", this);
	m_audioDataLabel["album"].specific->setGeometry(260, 280,350,25);
	m_audioDataLabel["album"].specific->setStyleSheet("border: 2px dotted gray");
}

void AudioWindowWidget::InitAudioProgress()
{
	m_slider = new QSlider(Qt::Horizontal,this);
	m_slider->setGeometry(WINDOW_SZ_W / 4 + 10, WINDOW_SZ_H - 200, 500,20);
	connect(m_player, &QMediaPlayer::positionChanged, this, &AudioWindowWidget::SetSliderPosition);
	connect(m_slider, &QSlider::sliderMoved, this, &AudioWindowWidget::SetPlayer);
}

/// slots
void AudioWindowWidget::SetPlayingTrack()
{
	auto* button = qobject_cast<ScrollButton*>(sender());
	if (button)
	{
		m_playList->setCurrentIndex(button->GetIndex());
		PlayAudio();
		ChangeCurrentBtn(button);
		DisplayAudioMetaData();
	}
	else
	{
		qDebug() << ERROR_MESSAGE("qobject_cast failed.");
	}
}

void AudioWindowWidget::PlayAudio()
{
	m_player->play();
}

void AudioWindowWidget::SetDuration(qint64 duration)
{
	m_slider->setRange(0, duration);
}

void AudioWindowWidget::SetSliderPosition(qint64 pos)
{
	m_slider->setValue(pos);
}

void AudioWindowWidget::SetPlayer(qint64 pos)
{
	m_player->setPosition(pos);
}

void AudioWindowWidget::SetPlayingTrack(int pos)
{
	auto* button = m_audioButtons[pos];
	if (button)
	{
		m_playList->setCurrentIndex(button->GetIndex());
		PlayAudio();
		ChangeCurrentBtn(button);
		DisplayAudioMetaData();
	}
	else
	{
		qDebug() << ERROR_MESSAGE("qobject_cast failed.");
	}
}

/// core
void AudioWindowWidget::DisplayAudioMetaData()
{
	// title
	if(!m_btnInfoMap[m_curAudioBtn]->tag()->title().isEmpty())
		m_audioDataLabel["title"].specific->setText(m_btnInfoMap[m_curAudioBtn]->tag()->title().toCString());
	else
		m_audioDataLabel["title"].specific->setText("...");

	// genre
	if(!m_btnInfoMap[m_curAudioBtn]->tag()->genre().isEmpty())
		m_audioDataLabel["genre"].specific->setText(m_btnInfoMap[m_curAudioBtn]->tag()->genre().toCString());
	else
		m_audioDataLabel["genre"].specific->setText("...");

	// album
	if(!m_btnInfoMap[m_curAudioBtn]->tag()->album().isEmpty())
		m_audioDataLabel["album"].specific->setText(m_btnInfoMap[m_curAudioBtn]->tag()->album().toCString());
	else
		m_audioDataLabel["album"].specific->setText("...");

}

void AudioWindowWidget::ChangeCurrentBtn(QPushButton* newBtn)
{
	if(!m_curAudioBtn)
	{
		m_curAudioBtn = newBtn;
		m_curAudioBtn->setStyleSheet("background-color: #D3D3D3; border: 2px solid black");
	}
	else
	{
		m_curAudioBtn->setStyleSheet("background-color: white");
		m_curAudioBtn = newBtn;
		m_curAudioBtn->setStyleSheet("background-color: #D3D3D3; border: 2px solid black");
	}
}




