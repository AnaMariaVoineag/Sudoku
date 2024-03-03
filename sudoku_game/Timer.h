#pragma once
#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString timeDisplay READ timeDisplay WRITE setTimeDisplay NOTIFY timeDisplayChanged)

public:
    explicit Timer(QObject *parent = nullptr);
    ~Timer();
    QString timeDisplay();

public slots:
    void setTimeDisplay(QString display);
    void timeTick();

signals:
    void timeDisplayChanged();

private:
    QString m_timeDisplay;
    QTimer *timer;

    int seconds;
    int minutes;

};
