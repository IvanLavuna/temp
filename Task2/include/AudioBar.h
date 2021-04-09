//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOBAR_H
#define MEDIAPLAYERAPP_AUDIOBAR_H

#include "AudioEngine.h"

/**
 * Class for displaying and managing buttons each one of which
 * represents an audio file( track )
 * **/
class AudioBar : public QWidget
{
Q_OBJECT
private:
	/// variables
	AudioEngine*           m_engine = nullptr;

	/// this widget layout
	QVBoxLayout* 		   m_mainLayout = nullptr;

	/// search edit line for searching audio
	QLineEdit*   		   m_searchLine = nullptr;

	/// scroll area stuff: area, widget and layout
	QWidget*		       m_scrollWidget = nullptr;
	QScrollArea*		   m_scrollArea   = nullptr;
	QVBoxLayout*	       m_scrollLayout = nullptr;

	/// buttons to be inside scroll area
	QVector<IndexedButton*>  m_audioButtons;
	IndexedButton*	 		 m_activeBtn = nullptr;

public slots:
	void changeCurrentButton(int);
	void addItem(int pos);
//	void removeItem(int pos);

public:
	explicit AudioBar(AudioEngine* engine, QWidget *parent = nullptr);

signals:

};


#endif //MEDIAPLAYERAPP_AUDIOBAR_H
