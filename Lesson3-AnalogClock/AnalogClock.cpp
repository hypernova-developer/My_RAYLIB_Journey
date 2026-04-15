#include "AnalogClock.hpp"

Color DARK_GRAY = {45, 45, 45, 255};
Color LIGHT_GRAY = {229, 229, 229, 255};

void AnalogClock::Draw() const
{
    DrawFace();
    DrawHourMarks();
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
    DrawRectanglePro(rect, {rectWidth / 2, rectHeight}, 0, DARK_GRAY);
    DrawCircleV(position, 5, RED);
}
