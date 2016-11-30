I'm working on part 1:CHARACTER OBSERVER(not MAP OBSERVER, I misnamed the project).

The test case tests whether or not the character observer is notified by the character.

At first pause, level of the character is set which triggers the notifier to notify the 
character observer throught the setlevel function.

At second pause it tests the notification during hp modification.

At third pause, it tests the notifier again during a level up(some stats will change).

Classes created/modified:

Character.h/character.cpp
Subject.h/Subject.cpp
Observer.h/Observer.cpp
characterObserver.h/characterObserver.cpp
CharacterTest.cpp