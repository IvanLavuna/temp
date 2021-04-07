//
// Created by ivan on 07.04.21.
//

#ifndef MEDIAPLAYERAPP_AUDIOFILE_H
#define MEDIAPLAYERAPP_AUDIOFILE_H


typedef unsigned int uint;

class AudioFile	: public QObject
{
Q_OBJECT
private:
	QString  m_filePath{};
	QString  m_artist{};
	QString  m_title{};
	QString  m_album{};
	QString  m_genre{};
	uint     m_year{};
private slots:

protected:

public:
	/// constructors / destructor
	AudioFile();
	explicit AudioFile(QString& sourcePath);
	explicit AudioFile(QString&& sourcePath);
	~AudioFile() override = default;

	/// get
	QString getFilePath() const noexcept;
	QString getArtist()   const noexcept;
	QString getTitle()    const noexcept;
	QString getAlbum()    const noexcept;
	QString getGenre()    const noexcept;
	uint    getYear()     const noexcept;

	/// set
	void setFilePath(QString& filePath);
	void setFilePath(QString&& filePath);

	void setArtist(QString& artist);
	void setArtist(QString&& artist);

	void setTitle(QString& title);
	void setTitle(QString&& title);

	void setAlbum(QString& album);
	void setAlbum(QString&& album);

	void setGenre(QString& genre);
	void setGenre(QString&& genre);

	void setYear(uint year);

	void setAudio(QString& sourcePath);
	void setAudio(QString&& sourcePath);

signals:
};


#endif //MEDIAPLAYERAPP_AUDIOFILE_H
