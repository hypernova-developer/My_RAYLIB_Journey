#include "AnalogClock.hpp"

Color DARK_GRAY = {45, 45, 45, 255};
Color LIGHT_GRAY = {229, 229, 229, 255};

void AnalogClock::Draw() const
{
    DrawFace();
    DrawHourMarks();
    DrawMinuteHand(30);
    DrawHourHand(3, 30);
    DrawSecondHand(0);
    DrawCircleV(position, 15, DARK_GRAY);
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
    int angle = minute * 6;

    DrawHand(handWidth, handLenght, angle, DARK_GRAY, 0);
}

void AnalogClock::DrawHand(float handWidth, float handLenght, int angle, Color color, int offset) const
{
    Rectangle handRect = Rectangle{position.x, position.y, handWidth, handLenght};
    DrawRectanglePro(handRect, {handWidth / 2, handLenght - offset}, angle, color);
}

void AnalogClock::DrawHourHand(int hour, int minute) const
{
    float handWidth = 15;
    float handLenght = size * 0.6;
    int angle = 30 * hour + (minute / 60.0) * 30;

    DrawHand(handWidth, handLenght, angle, DARK_GRAY, 0);
}

void AnalogClock::DrawSecondHand(int second) const
{
    float handWidth = 5;
    float handLenght = size * 1.05;
    int angle = second * 6;

    DrawHand(handWidth, handLenght, angle, RED, 55);
}
