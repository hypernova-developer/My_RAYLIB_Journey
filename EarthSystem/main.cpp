#include <iostream>
#include <chrono>
#include <thread>
#include <raylib.h>

using namespace std;

Color deepSpaceBlack = {5, 5, 15, 255};     // It look as good as expected as a background color to be honest. 

void SleepForMilliSeconds(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int main()
{
    cout << "Initializing the system... " << endl;      // Checking algorithm if the program works: 
    SleepForMilliSeconds(250);

    // Variables about creating the window
    const int WINDOW_WIDTH = 1920;
    const int WINDOW_HEIGHT = 1080;
    const int FPS = 60;

    // Something about the window: 
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Earth System");
    ToggleFullscreen();
    SetTargetFPS(FPS);

    // The main loop that will be repeating over and over until we press ESC or the X button in the corner of the window: 
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(deepSpaceBlack);


        EndDrawing();
    }

    CloseWindow();
}
