
#include "pomodoro.h"

#include <sstream>
#include <iomanip>

namespace CppLondonUni {

Pomodoro::Pomodoro(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Pomodoro)
{
    ui->setupUi(this);
}

void Pomodoro::on_btnControl_clicked()
{
    const auto seconds = std::chrono::seconds{ui->timeout->text().toUInt()};
}

void Pomodoro::onTimerTick(std::chrono::seconds timeRemaining)
{
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