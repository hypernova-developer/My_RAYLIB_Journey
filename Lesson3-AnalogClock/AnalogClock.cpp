#include "AnalogClock.hpp"

Color DARK_GRAY = {45, 45, 45, 255};
Color LIGHT_GRAY = {229, 229, 229, 255};

void AnalogClock::Draw() const
{
    DrawFace();
    DrawHourMarks();
    DrawMinuteHand(25);
}

void AnalogClock::DrawFace() const
{
    DrawCircleV(position, size, DARK_GRAY);
    DrawCircleV(position, size - 30, LIGHT_GRAY);
    DrawCircleV(position, size - 40, RAYWHITE);
}

void AnalogClock::DrawHourMarks() const
{
    float rectWidth = 10;
    float rectHeight = size;

    Rectangle rect = {position.x, position.y, rectWidth, rectHeight};

    for (int i = 0; i < 12; i++)
    {
        DrawRectanglePro(rect, {rectWidth / 2, rectHeight}, i * 30, DARK_GRAY);
    }

    DrawCircleV(position, size - 50, RAYWHITE);
}

void AnalogClock::DrawMinuteHand(int minute) const
{
    float handWidth = 10;
    float handLenght = size * 0.7;

    Rectangle handRect = Rectangle{position.x, position.y, handWidth, handLenght};
    int angle = minute * 6;

    DrawRectanglePro(handRect, {handWidth / 2, handLenght}, angle, DARK_GRAY);
}
