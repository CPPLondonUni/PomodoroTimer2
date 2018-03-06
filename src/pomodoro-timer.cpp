
#include "pomodoro-timer.h"

#include <QDebug>

using namespace std::chrono_literals;

namespace CppLondonUni {

PomodoroTimer::PomodoroTimer(QObject* parent)
    : QObject(parent)
{
    connect(&timer, &QTimer::timeout, this, &PomodoroTimer::onIntervalTimeout);
}

void PomodoroTimer::start(std::chrono::seconds timeout)
{
    this->remaining = timeout;
    timer.start(1s);
    emit(tick(timeout));
}

void PomodoroTimer::stop()
{
    this->remaining = 0s;
    timer.stop();
}

void PomodoroTimer::onIntervalTimeout()
{
    --remaining;
    if (remaining == 0s) {
        timer.stop();
        emit(completed());
    } else {
        emit(tick(remaining));
    }
}

}