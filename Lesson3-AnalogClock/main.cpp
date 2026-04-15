// Libraries

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <ctime>
#include <raylib.h>

// Setting the namespace

using namespace std;

// Not to type the sleep funstion always

void SleepForMilliSeconds(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int main()
{
    cout << "Initializing the system and the clock... " << endl;
    SleepForMilliSeconds(350);

    // Setting the window variables
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_WIDTH = 600;

    // Creating the window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hy-Clock");
    SetTargetFPS(15);

    // Main Loop

    while (WindowShouldClose() == false)
    {
        // 1. Event Handling

        // 2. Updating

        // 3. Drawing

        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
}
