//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_MAINWINDOW_H
#define MEDIAPLAYERAPP_MAINWINDOW_H


#include "AudioWindowWidget.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	AudioWindowWidget * m_audioWidget = nullptr;

private slots:

protected:

public:
	explicit MainWindow(QWidget *parent = nullptr);

signals:

};



#endif //MEDIAPLAYERAPP_MAINWINDOW_H
