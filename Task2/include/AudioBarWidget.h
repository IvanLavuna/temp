//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOBARWIDGET_H
#define MEDIAPLAYERAPP_AUDIOBARWIDGET_H

#include "AudioEngine.h"

/**
 * Class for displaying and managing buttons each one of which
 * represents an audio file( track )
 * **/
 /// TODO: Rename to AudioBar
class AudioBarWidget : public QWidget
{
Q_OBJECT
private:
	/// variables
	AudioEngine*           m_engine;

	/// this window layout
	QVBoxLayout* 		   m_mainLayout;

	/// search edit line for searching audio
	QLineEdit*   		   m_searchLine = nullptr;

	/// scroll area stuff: area, widget and layout
	QWidget*		       m_scrollWidget = nullptr;
	QScrollArea*		   m_scrollArea   = nullptr;
	QVBoxLayout*	       m_scrollLayout = nullptr;

	/// buttons to be inside scroll area
	QVector<IndexedButton*>  m_audioButtons;

private slots:

protected:

public:
	explicit AudioBarWidget(AudioEngine* engine, QWidget *parent = nullptr);

signals:
};


#endif //MEDIAPLAYERAPP_AUDIOBARWIDGET_H
