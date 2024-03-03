#pragma once

#include <QObject>
#include <QMediaPlayer>
#include "qaudiooutput.h"

class Music : public QObject
{
    Q_OBJECT
public:
    explicit Music(QObject *parent = nullptr);
    ~Music();

signals:

public slots:
    void playMusic();
    void stopMusic();

private:
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;

};
