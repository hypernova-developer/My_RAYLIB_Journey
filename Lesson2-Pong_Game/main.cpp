#include <raylib.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void sleepForMilliSeconds(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int main()
{
    cout << "Initializing the game... " << endl;

    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int targetedFPS = 60;

    InitWindow(screenWidth, screenHeight, "My Pong Game-1 =]");
    SetTargetFPS(targetedFPS);

    // Main Code of the Game
    // It wil continue over and over if the windows shall not close.
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        //Things that will be drewn should stay here until EndDrawing();
        

        EndDrawing();
    }

    CloseWindow();
    sleepForMilliSeconds(200);
    return 0;
}
