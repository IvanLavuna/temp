//
// Created by ivan on 01.04.21.
//

#ifndef MEDIAPLAYERAPP_PCH_H
#define MEDIAPLAYERAPP_PCH_H

/// Qt
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QAction>
#include <QScrollArea>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDirIterator>
#include <QDebug>
#include <QThread>
#include <QDataStream>
#include <QProgressBar>
#include <QAudioProbe>
#include <QStatusBar>
#include <QSlider>
#include <QScrollBar>

/// taglib
#include <taglib/tag.h>
#include <taglib/fileref.h>

#define WINDOW_SZ_H 600
#define WINDOW_SZ_W 700

/// TODO : rewrite this implementation to be cross-platform
#define TRACKED_PATH "/home/" + qgetenv("USER") + "/Music"
#define UNTRACKED_PATH "/home/" + qgetenv("USER")
#define PLAY_ICON_PATH "../resource/play.png"
#define STOP_ICON_PATH "../resource/stop.png"
#define NEXT_ICON_PATH "../resource/next.png"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)
#define ERROR_MESSAGE(DESC) ("error: " AT "\n" "Description: " DESC "\n")

#endif //MEDIAPLAYERAPP_PCH_H
