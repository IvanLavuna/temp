//
// Created by ivan on 02.04.21.
//

#ifndef MEDIAPLAYERAPP_INDEXEDBUTTON_H
#define MEDIAPLAYERAPP_INDEXEDBUTTON_H


class IndexedButton : public QPushButton
{
	Q_OBJECT
private:
	int m_index;

	void initSignals() const;
private slots:
	void emitReleasedSignal();

public slots:

public:
	explicit IndexedButton(int index, QWidget* parent = nullptr);

	explicit IndexedButton(QWidget* parent = nullptr);
	explicit IndexedButton(const QString & text, QWidget * parent = nullptr);
	IndexedButton(const QIcon& icon, const QString& text, QWidget* parent = nullptr);

	void SetIndex(int index);
	int GetIndex() const;

signals:
	void released(int);

};


#endif //MEDIAPLAYERAPP_INDEXEDBUTTON_H
