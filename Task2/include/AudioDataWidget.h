//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIODATAWIDGET_H
#define MEDIAPLAYERAPP_AUDIODATAWIDGET_H

#include "AudioEngine.h"

class AudioDataWidget : public QWidget, public AudioEngine
{
Q_OBJECT
private:


private slots:

protected:

public:
	explicit AudioDataWidget(QWidget *parent = nullptr);

signals:
};


#endif //MEDIAPLAYERAPP_AUDIODATAWIDGET_H
