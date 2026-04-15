#include <iostream>
#include <chrono>
#include <thread>
#include <raylib.h>
#include "AnalogClock.hpp"
#include "AnalogClock.cpp"

// Setting up the colors
Color LIGHT_BLUE = {225, 239, 240, 255};

using namespace std;

void SleepForMilliSeconds(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int main()
{
    cout << "Initializing the system and the clock... " << endl;
    SleepForMilliSeconds(350);

    // Setting the window's variables
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_WIDTH = 600;

    // Creating the window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hy-Clock");
    SetTargetFPS(15);

    AnalogClock clock {250, {300, 300}};

    // Main Loop
    while (WindowShouldClose() == false)
    {
        // 1. Event Handling

        // 2. Updating

        // 3. Drawing

        BeginDrawing();
        ClearBackground(LIGHT_BLUE);
        clock.Draw();

        EndDrawing();
    }

    CloseWindow();
}
