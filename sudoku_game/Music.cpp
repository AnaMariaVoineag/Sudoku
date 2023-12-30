#include "Music.h"
#include <iostream>

Music::Music(QObject *parent) : QObject{parent}
{
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setSource(QUrl("qrc:/sounds/DJPlay.mp3"));

}

Music::~Music()
{
    delete mediaPlayer;
}


void Music::playMusic()
{
    if (mediaPlayer) {
        audioOutput->setVolume(50);
        mediaPlayer->setAudioOutput(audioOutput);
        mediaPlayer->play();
    } else {
        std::cout << "Music is not playing." << std::endl;
    }
}

void Music::stopMusic()
{
    if(mediaPlayer)
    {
        mediaPlayer->stop();
    } else {
        std::cout << "No music to stop." << std::endl;
    }
}

