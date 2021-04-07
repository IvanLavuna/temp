//
// Created by ivan on 07.04.21.
//

#include "AudioFile.h"

/// constructors
AudioFile::AudioFile() = default;

AudioFile::AudioFile(QString &sourcePath)
{
	TagLib::FileRef f(sourcePath.toStdString().c_str());
	if(f.isNull())
		throw ERROR_MESSAGE("Failed to open." );

	m_filePath = sourcePath;
	m_artist   = f.tag()->artist().toCString();
	m_title    = f.tag()->title().toCString();
	m_album    = f.tag()->album().toCString();
	m_genre    = f.tag()->genre().toCString();
	m_year     = f.tag()->year();
}

AudioFile::AudioFile(QString &&sourcePath)
{
	TagLib::FileRef f(sourcePath.toStdString().c_str());
	if(f.isNull())
		throw ERROR_MESSAGE("Failed to open." );

	m_filePath = sourcePath;
	m_artist   = f.tag()->artist().toCString();
	m_title    = f.tag()->title().toCString();
	m_album    = f.tag()->album().toCString();
	m_genre    = f.tag()->genre().toCString();
	m_year     = f.tag()->year();
}

/// get
QString AudioFile::getFilePath() const noexcept
{
	return m_filePath;
}

QString AudioFile::getArtist() const noexcept
{
	return m_artist;
}

QString AudioFile::getTitle() const noexcept
{
	return m_title;
}

QString AudioFile::getAlbum() const noexcept
{
	return m_album;
}

QString AudioFile::getGenre() const noexcept
{
	return m_genre;
}

uint AudioFile::getYear() const noexcept
{
	return m_year;
}

/// set
void AudioFile::setFilePath(QString &filePath)
{
	m_filePath = filePath;
}
void AudioFile::setFilePath(QString &&filePath)
{
	m_filePath = filePath;

}

void AudioFile::setArtist(QString &artist)
{
	m_artist = artist;
}

void AudioFile::setArtist(QString &&artist)
{
	m_artist = artist;
}

void AudioFile::setTitle(QString &title)
{
	m_title = title;
}

void AudioFile::setTitle(QString &&title)
{
	m_title = title;
}

void AudioFile::setAlbum(QString &album)
{
	m_album = album;
}

void AudioFile::setAlbum(QString &&album)
{
	m_album = album;
}

void AudioFile::setGenre(QString &genre)
{
	m_genre = genre;
}

void AudioFile::setGenre(QString &&genre)
{
	m_genre = genre;
}

void AudioFile::setYear(uint year)
{
	m_year = year;
}

void AudioFile::setAudio(QString &sourcePath)
{
	TagLib::FileRef f(sourcePath.toStdString().c_str());
	if(f.isNull())
		throw ERROR_MESSAGE("Failed to open." );

	m_filePath = sourcePath;
	m_artist   = f.tag()->artist().toCString();
	m_title    = f.tag()->title().toCString();
	m_album    = f.tag()->album().toCString();
	m_genre    = f.tag()->genre().toCString();
	m_year     = f.tag()->year();
}

void AudioFile::setAudio(QString &&sourcePath)
{
	TagLib::FileRef f(sourcePath.toStdString().c_str());
	if(f.isNull())
		throw ERROR_MESSAGE("Failed to open." );

	m_filePath = sourcePath;
	m_artist   = f.tag()->artist().toCString();
	m_title    = f.tag()->title().toCString();
	m_album    = f.tag()->album().toCString();
	m_genre    = f.tag()->genre().toCString();
	m_year     = f.tag()->year();
}
