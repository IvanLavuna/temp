//
// Created by ivan on 01.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOWINDOW_H
#define MEDIAPLAYERAPP_AUDIOWINDOW_H

#include "AudioWidget.h"


class AudioWindow : public QMainWindow
{
	Q_OBJECT
private:
	AudioWidget * m_audioWidget = nullptr;

private slots:

protected:

public:
	explicit AudioWindow(QWidget *parent = nullptr);

signals:

};


#endif //MEDIAPLAYERAPP_AUDIOWINDOW_H
