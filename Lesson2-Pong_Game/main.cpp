#include <raylib.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Ball
{
public:
    float x;
    float y;
    int speedX;
    int speedY;
    int radius;

    void Draw()
    {
        // Drawing the Ball as a Circle...
        DrawCircle(x, y, radius, WHITE);
    }

    void Update()
    {
        x += speedX;
        y += speedY;

        // What if they touch to the edge? These: 
        
        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speedY *= -1;
        }
        if (x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speedX *= -1;
        }
    }
};

Ball ball;

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

    InitWindow(screenWidth, screenHeight, "My Pong Game-5 =]");
    SetTargetFPS(targetedFPS);

    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    // Main Code of the Game
    // It wil continue over and over if the windows shall not close.
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Updating the Elements
        ball.Update();

        // Things that will be drewn should stay here until EndDrawing();
        ball.Draw();

        // Drawing the Paddles as Rectangles...
        ClearBackground(BLACK);
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE);
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE);
        
        // Drawing the Central Line as a Line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);


        EndDrawing();
    }

    CloseWindow();
    sleepForMilliSeconds(200);
    return 0;
}
