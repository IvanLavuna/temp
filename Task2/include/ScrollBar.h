//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_SCROLLBAR_H
#define MEDIAPLAYERAPP_SCROLLBAR_H

#include "ScrollButton.h"

class ScrollBar : public QScrollBar
{
	Q_OBJECT
private:
	/** variables **/
	QScrollArea*	  m_scroll = nullptr;
	QWidget*		  m_scrollWidget = nullptr;
	QVBoxLayout*	  m_scrollLayout = nullptr;
	QVector<ScrollButton*>  m_audioButtons;


private slots:

public:
	explicit ScrollBar(QWidget* parent);

	void setButtons(QVector<ScrollButton>* buttons);
	void addButton(ScrollButton* btn);

public slots:

signals:
};


#endif //MEDIAPLAYERAPP_SCROLLBAR_H
