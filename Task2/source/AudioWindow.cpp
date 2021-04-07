//
// Created by ivan on 01.04.21.
//

#include "AudioWindow.h"

AudioWindow::AudioWindow(QWidget* parent):
	QMainWindow(parent)
{
	m_audioWidget = new AudioWidget();
	this->setCentralWidget(m_audioWidget);
}




