//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOBARWIDGET_H
#define MEDIAPLAYERAPP_AUDIOBARWIDGET_H

#include "AudioEngine.h"

class AudioBarWidget : public QWidget, public AudioEngine
{
Q_OBJECT
private:


private slots:

protected:

public:
	explicit AudioBarWidget(QWidget *parent = nullptr);

signals:
};


#endif //MEDIAPLAYERAPP_AUDIOBARWIDGET_H
