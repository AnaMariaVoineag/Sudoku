#include "Timer.h"

Timer::Timer(QObject *parent)
    : QObject{parent},
    m_timeDisplay(QString()),
    seconds (0),
    minutes (0)
{
    timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, &QTimer::timeout, this, &Timer::timeTick);
    timer->start();
}

Timer::~Timer()
{
    timer->deleteLater();
}

QString Timer::timeDisplay()
{
    return m_timeDisplay;
}

void Timer::setTimeDisplay(QString display)
{
    if(m_timeDisplay != display)
    {
        m_timeDisplay = display;
        emit timeDisplayChanged();
    }
}

void Timer::timeTick()
{
    seconds++;
    if(seconds >= 60)
    {
        seconds = 0;
        minutes++;
    }

    QString newText;
    if(minutes < 10)
    {
        newText.append("0");
    }
    newText.append(QString::number(minutes));

    newText.append(":");

    if(seconds < 10)
    {
        newText.append("0");
    }
    newText.append(QString::number(seconds));

    setTimeDisplay(newText);
}