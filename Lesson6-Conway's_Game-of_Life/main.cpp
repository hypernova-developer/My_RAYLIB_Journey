#include <iostream>
// Type the rules of the game into a text file with that over there. (With <fstream>)
#include <string>
#include <chrono>
#include <thread>
#include <raylib.h>
#include "simulation.hpp"
#include "simulation.cpp"

using namespace std;

Color GREY = {29, 29, 29, 255};

void SleepForMilliSeconds(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void RunProgram()
{
    cout << "Initializing the program... " << endl;
    SleepForMilliSeconds(2000);
    
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(12);
    Simulation simulation {WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();

        EndDrawing();
    }

    CloseWindow();
}

int main()
{
    RunProgram();
    SleepForMilliSeconds(500);
    return 0;
}
