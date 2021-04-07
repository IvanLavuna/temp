//
// Created by ivan on 07.04.21.
//

#include "MainWindow.h"
MainWindow::MainWindow(QWidget* parent):
		QMainWindow(parent)
{
	m_audioWidget = new AudioWindowWidget();
	this->setCentralWidget(m_audioWidget);
}

