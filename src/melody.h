#include <ArduinoSTL.h>
#include "pitches.h"

class Note {
    private:
        int _note, _duration;

    public:
        Note(int note, int duration) {
            _note = note;
            _duration = duration;
        }

        getNote() {
            return _note;
        }

        getDuration() {
            return _duration;
        }
};

class Melody {
    private:
        std::vector<Note> _notes;
        int _twitter;

        void playNote(Note note) {
            int noteDuration = 1000 / note.getDuration();
            tone(_twitter, note.getNote(), noteDuration);

            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);

            noTone(_twitter);
        }

    public:
        void attach(int pin) {
            _twitter = pin;
        }

        void addNote(Note note) {
            _notes.push_back(note);
        }

        void play() {
            if (_twitter == 0) {
                return;
            }

            for (Note note : _notes) {
                playNote(note);
            }
        }
};
