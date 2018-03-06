# Pomodoro Timer Workshop 2

## Introduction ##

This branch contains a cut-down and simplified version of the Pomodoro
app we used in the first workshop. Unfortunately, the app doesn't work!

You will use the knowledge of Qt that you gained last week to fix the app, and then
add a sound effect which will play when the timer reaches zero.

## Task 1 ##

The implementation of the `Pomodoro` class is in `pomodoro.cpp`. The UI has been
created for you, but its methods are left largely unimplemented.

The file `pomodoro-timer.h` contains the interface for `PomodoroTimer`.
This is a `QObject` which defines signals which can be used with the
Qt event system.

Your first task is to study the interface of `PomodoroTimer` and decide how it
can be used in the implementation of `Pomodoro`.  Then use the
`QObject::connect()` function to connect the timer signals to the Pomodoro
implementation to get the app back to a working state.

## Task 2 ##

Now that the app is working again, we want to play a sound when the timer completes.
Using your knowledge of the Qt Multimedia subsystem from last week, use an
appropriate function to play the file "Annoying_Alarm_Clock.wav" when the timer
reaches zero.

## Task 3 ##

If you didn't already do so in the previous task, see if you can use signal
connections to get the sound to play automatically when the timer reaches zero.

Now we want to stop the sound if the user clicks "start" a second time. Again,
see if you can use a signal connection to do this automatically.


## Task 4 ##

This is an extension task for those who found the above a bit too easy.

Add a "Stop" button which stops the timer. Note that for this you will need to
edit the `pomodoro.ui` file using QtDesigner or QtCreator (or do some XML
editing if you prefer).


## Task 5 ##

Finally, add a "Pause" button which pauses the timer. Again, this will require
editing the UI file. When the user clicks pause, the text of the pause button
should change to "Resume". When the user clicks a second time, the text should
change back to "Pause", and the timer should be restarted.










