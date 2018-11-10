#ifndef MELODY_H
#define MELODY_H

#include <ArduinoSTL.h>
#include "pitches.h"

class Note {
    private:
        int _note, _duration;

    public:
        Note(int note, int duration);
        int getNote();
        int getDuration();
};

class Melody {
    private:
        std::vector<Note> _notes;
        int _twitter;
        void playNote(Note note);

    public:
        void attach(int pin);
        void addNote(Note note);
        void play();
};

#endif
