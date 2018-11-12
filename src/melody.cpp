#include <melody.h>
#include <Arduino.h>

Note::Note(int note, int duration) {
    _note = note;
    _duration = duration;
}

int Note::getNote() {
    return _note;
}

int Note::getDuration() {
    return _duration;
}

void Melody::playNote(Note note) {
    int noteDuration = 1000 / note.getDuration();
    tone(_twitter, note.getNote(), noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(_twitter);
}

void Melody::attach(int pin) {
    _twitter = pin;
}

void Melody::addNote(Note note) {
    _notes.push_back(note);
}

void Melody::play() {
    if (_twitter == 0) {
        return;
    }

    for (Note note : _notes) {
        playNote(note);
    }
}
