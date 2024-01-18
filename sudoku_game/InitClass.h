#pragma once

#include <QObject>
#include <QQmlApplicationEngine>

class InitClass : public QObject
{
    Q_OBJECT
public:
    explicit InitClass(QQmlApplicationEngine *engine);

signals:

public slots:
    void howToPlayWindow();
    void newGameWindow();
    void mainMenu();
    void gameWindow(int dificulty);

private:
     QQmlApplicationEngine *engine;

};

