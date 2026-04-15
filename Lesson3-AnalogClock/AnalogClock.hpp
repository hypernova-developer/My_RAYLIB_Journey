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

    int size;
    Vector2 position;

};
