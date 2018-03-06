
#include "pomodoro.h"

#include <sstream>
#include <iomanip>

#include <QSound>

namespace CppLondonUni {

Pomodoro::Pomodoro(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Pomodoro)
{
    ui->setupUi(this);

    connect(&timer, &PomodoroTimer::tick, this, &Pomodoro::onTimerTick);
    connect(&timer, &PomodoroTimer::completed, this, &Pomodoro::onTimerCompleted);
}

void Pomodoro::on_btnControl_clicked()
{
    const auto seconds = std::chrono::seconds{ui->timeout->text().toUInt()};
    timer.start(seconds);
}

void Pomodoro::onTimerTick(std::chrono::seconds timeRemaining)
{
    formatTime(timeRemaining);
}

void Pomodoro::onTimerCompleted()
{
    formatTime(std::chrono::seconds{0});
    QSound::play("Annoying_Alarm_Clock.wav");
}

void Pomodoro::formatTime(std::chrono::seconds remaining)
{
    auto secs = remaining.count();
    const auto mins = secs / 60;
    secs = secs % 60;

    std::ostringstream ss;
    ss << mins << ':' << std::setw(2) << std::setfill('0') << secs;

    ui->curTime->setText(ss.str().c_str());
}


}