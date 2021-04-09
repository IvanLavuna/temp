//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIODATA_H
#define MEDIAPLAYERAPP_AUDIODATA_H

#include "AudioEngine.h"

class AudioData : public QWidget
{ Q_OBJECT

private:
	struct MetaLabel{
		QLabel* general;
		QLabel* specific;
	};

/// variables
	AudioEngine* m_engine = nullptr;

	QGridLayout* m_mainLayout = nullptr;

	/// label map
	QMap<QString, MetaLabel> label;


public slots:
	void displayAudioMetaData(int pos);

public:
	explicit AudioData(AudioEngine* engine, QWidget *parent = nullptr);

signals:
};


#endif //MEDIAPLAYERAPP_AUDIODATA_H
