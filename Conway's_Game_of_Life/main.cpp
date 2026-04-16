#include <iostream>
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

int main()
{
    cout << "Initializing the program... " << endl;
    SleepForMilliSeconds(300);
    
    const int WINDOW_WIDTH = 1200;      // 1200 x 800 <= 750 x 750 Also I can use 1920 x 1080 at fullscreen window
    const int WINDOW_HEIGHT = 800;
    const int CELL_SIZE = 4;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation {WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    while (WindowShouldClose() == false)
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();

            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;

            simulation.ToggleCell(row, column);
        }
        
        if (IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Conway's Game of Life is running...");
        }

        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Conway's Game of Life has stopped.");
        }

        else if (IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }

        else if (IsKeyPressed(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }

        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }

        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }
        
        simulation.Update();
        
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();

        EndDrawing();
    }

    CloseWindow();

    SleepForMilliSeconds(300);
    return 0;
}
