//
// Created by ivan on 07.04.21.
//

#include "MainWindow.h"
MainWindow::MainWindow(QWidget* parent):
		QMainWindow(parent)
{
	this->setFixedSize(WINDOW_SZ_W,WINDOW_SZ_H);
	m_audioWidget = new AudioWindow();
	this->setCentralWidget(m_audioWidget);
}

