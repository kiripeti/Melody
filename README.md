# Melody

This is a small and straightforward library to play melodies through a buzzer on Arduino.

The starting point to this library was [ToneMelody](https://www.arduino.cc/en/Tutorial/toneMelody), I used the codes from there. Just made it a bit easier to use.

# Install

I uses the the `ArduinoSTL` library, so before use you need to install it.

# Usage

The libary comes with the `Note` and `Melody` class and some constants to make it easier to compose.

## NOTE

`Note` is helper class to define the notes and their length in the melody.

It has one contructor which accept two `int`s, one for the frequency and one for their length (1/4, 1/8, etc.)

```c++
Note note(NOTE_C4, 4);
```

    The 4 up there is for the 1/4 length

## Melody

It has only a default constructor, and has three methods:
1. `void attach(int)`: Attach the pin with the buzzer on it.
2. `void addNote(Note)`: Add a Note to the end of your melody.
3. `void play()`: Play your melody.

# Example

The example below does exactly the same as the code in [TomeMelody](https://www.arduino.cc/en/Tutorial/toneMelody)

```c++
#include <melody.h>

const int twitter = 5;
Melody melody;

void setup() {
    melody.attach(twitter);

    melody.addNote(Note(NOTE_C4,    4));
    melody.addNote(Note(NOTE_G3,    8));
    melody.addNote(Note(NOTE_G3,    8));
    melody.addNote(Note(NOTE_A3,    4));
    melody.addNote(Note(NOTE_G3,    4));
    melody.addNote(Note(NOTE_PAUSE, 4));
    melody.addNote(Note(NOTE_B3,    4));
    melody.addNote(Note(NOTE_C4,    4));

    melody.play();
}

void loop() {
  // no need to repeat the melody.
}
```
