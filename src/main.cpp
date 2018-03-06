
#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>

#include "pomodoro.h"

int main(int argc, char** argv)
{
    QApplication app{argc, argv};

    CppLondonUni::Pomodoro w{};
    w.setGeometry(QStyle::alignedRect(Qt::LeftToRight,
                                      Qt::AlignCenter, w.size(), app.desktop()->availableGeometry()));
    w.show();

    return app.exec();
}