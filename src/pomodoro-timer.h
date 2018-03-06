
#ifndef CPP_LONDON_UNI_POMODORO_TIMER_H
#define CPP_LONDON_UNI_POMODORO_TIMER_H

#include <QTimer>
#include <chrono>

namespace CppLondonUni {

class PomodoroTimer : public QObject {

    Q_OBJECT

public:
    /// Creates a new PomodoroTimer with the given parent
    explicit PomodoroTimer(QObject* parent = nullptr);

public slots:
    /// Starts (or re-starts) the timer with the given timeout
    void start(std::chrono::seconds timeout);

    /// Stops the timer immediately.
    /// Note that the `completed` signal will NOT be emitted.
    void stop();

signals:
    /// This signal is emitted once per second when the timer is active.
    void tick(std::chrono::seconds timeRemaining);

    /// This signal is emitted when the time remaining reaches zero
    void completed();

private slots:
    void onIntervalTimeout();

private:
    QTimer timer;
    std::chrono::seconds remaining{};
};



}

#endif
