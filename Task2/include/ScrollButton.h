//
// Created by ivan on 02.04.21.
//

#ifndef MEDIAPLAYERAPP_SCROLLBUTTON_H
#define MEDIAPLAYERAPP_SCROLLBUTTON_H


class ScrollButton : public QPushButton
{
	Q_OBJECT
private:
	// characterises unique song
	int m_index;
private slots:

protected:

public:
	explicit ScrollButton(QWidget* parent = nullptr);
	explicit ScrollButton(const QString & text, QWidget * parent = nullptr);
	ScrollButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr);

	void SetIndex(int index);
	int GetIndex() const;

signals:


};


#endif //MEDIAPLAYERAPP_SCROLLBUTTON_H
