
#ifndef CPP_LONDON_UNI_POMODORO_H
#define CPP_LONDON_UNI_POMODORO_H

#include <QWidget>
#include <memory>

#include "pomodoro-timer.h"
#include "ui_pomodoro.h"

namespace CppLondonUni {

class Pomodoro : public QWidget {

    Q_OBJECT

public:
    explicit Pomodoro(QWidget* parent = nullptr);

private slots:
    // N.B. This slot is activated when the user clicks the "start" button in the UI
    void on_btnControl_clicked();

    void onTimerTick(std::chrono::seconds timeRemaining);
    void onTimerCompleted();

private:
    void formatTime(std::chrono::seconds remaining);

    std::unique_ptr<Ui::Pomodoro> ui;
    PomodoroTimer timer;
};


}

#endif
