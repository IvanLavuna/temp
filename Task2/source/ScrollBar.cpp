//
// Created by ivan on 07.04.21.
//

#include "ScrollBar.h"

ScrollBar::ScrollBar(QWidget* parent)
{
	m_scrollWidget  = new QWidget;
	m_scrollLayout  = new QVBoxLayout(m_scrollWidget);
	m_scroll = new QScrollArea(parent);
	m_scroll->setBackgroundRole(QPalette::Dark);
	m_scroll->setGeometry(0,150,WINDOW_SZ_W / 4,WINDOW_SZ_H - 150);
	m_scroll->setWidgetResizable(true);
}
