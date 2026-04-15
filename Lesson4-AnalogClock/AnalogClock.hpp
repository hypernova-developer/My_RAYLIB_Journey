#pragma once
#include <raylib.h>

class AnalogClock
{
public:
    AnalogClock(int size, Vector2 position) :size(size), position(position) {};
    void Draw() const;

private:
    void DrawFace() const;
    void DrawHourMarks() const;
    void DrawMinuteHand(int minute) const;
    void DrawHand(float handWidth, float handLenght, int angle, Color color, int offset) const;
    void DrawHourHand(int hour, int minute) const;
    void DrawSecondHand(int second) const;

    int size;
    Vector2 position;

};
