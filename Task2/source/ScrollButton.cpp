//
// Created by ivan on 02.04.21.
//

#include "ScrollButton.h"

ScrollButton::ScrollButton(QWidget *parent) :
	QPushButton(parent), m_index(0)
{

}

ScrollButton::ScrollButton(const QString &text, QWidget *parent) :
	QPushButton(text, parent), m_index(0)
{

}

ScrollButton::ScrollButton(const QIcon& icon, const QString &text, QWidget *parent) :
	QPushButton(icon, text, parent), m_index(0)
{

}



void ScrollButton::SetIndex(int index)
{
	m_index = index;
}

int ScrollButton::GetIndex() const
{
	return m_index;
}



