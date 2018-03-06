
#include "pomodoro.h"

#include <sstream>
#include <iomanip>

namespace CppLondonUni {

Pomodoro::Pomodoro(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Pomodoro)
{
    ui->setupUi(this);

    soundEffect.setSource(QUrl::fromLocalFile("Annoying_Alarm_Clock.wav"));

    connect(&timer, &PomodoroTimer::tick, this, &Pomodoro::onTimerTick);
    connect(&timer, &PomodoroTimer::completed, this, &Pomodoro::onTimerCompleted);
    connect(&timer, &PomodoroTimer::completed, &soundEffect, &QSoundEffect::play);
    connect(ui->btnControl, &QPushButton::clicked, &soundEffect, &QSoundEffect::stop);
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