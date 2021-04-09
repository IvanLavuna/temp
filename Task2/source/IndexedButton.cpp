//
// Created by ivan on 02.04.21.
//

#include "IndexedButton.h"

IndexedButton::IndexedButton(QWidget *parent) :
	QPushButton(parent), m_index(0)
{
	initSignals();
}

IndexedButton::IndexedButton(const QString &text, QWidget *parent) :
	QPushButton(text, parent), m_index(0)
{
	initSignals();
}

IndexedButton::IndexedButton(const QIcon& icon, const QString &text, QWidget *parent) :
	QPushButton(icon, text, parent), m_index(0)
{
	initSignals();
}

IndexedButton::IndexedButton(int index, QWidget *parent) :
		QPushButton(parent), m_index(index)
{
	initSignals();
}

void IndexedButton::initSignals() const
{
	connect(this, SIGNAL(released()), this, SLOT(emitReleasedSignal()) );
}

void IndexedButton::SetIndex(int index)
{
	m_index = index;
}

int IndexedButton::GetIndex() const
{
	return m_index;
}

void IndexedButton::emitReleasedSignal()
{
	emit released(m_index);
}





