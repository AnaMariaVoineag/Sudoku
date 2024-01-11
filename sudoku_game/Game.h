#pragma once

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "InitClass.h"

class Game : public QGuiApplication
{
    Q_OBJECT

signals:


public slots:
    Game(int argc, char *argv[]);
    ~Game();
    int run();


private:
    QQmlApplicationEngine *engine;
    InitClass objectClass;

};
