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

class Paddle
{
protected:
    void LimitMovement()
    {
        if (y <= 0)
        {
            y = 0;
        }
        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x;
    float y;
    float width;
    float height;
    int speed;

    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
        LimitMovement();
    }
};

class CpuPaddle: public Paddle
{
public:
    void Update(int ball_y)
    {
        if (y + height / 2 > ball_y)
        {
            y = y - speed;
        }
        if (y + height / 2 <= ball_y)
        {
            y = y + speed;
        }
        LimitMovement();
    }
};

Ball ball;
Paddle player;
CpuPaddle cpu;

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

    InitWindow(screenWidth, screenHeight, "My Pong Game-7 =]");
    SetTargetFPS(targetedFPS);

    // Initializing the Ball...

    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    // Initializing the Player Paddle...
    
    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 6;

    // Initializing the CPU Paddle

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screenHeight / 2 - cpu.height / 2;
    cpu.speed = 6;

    // Main Code of the Game
    // It wil continue over and over if the windows shall not close.
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Updating the Elements
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        // Things that will be drewn should stay here until EndDrawing();
        ball.Draw();
        cpu.Draw();

        // Drawing the Paddles as Rectangles...
        ClearBackground(BLACK);
        player.Draw();
        
        // Drawing the Central Line as a Line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);


        EndDrawing();
    }

    CloseWindow();
    sleepForMilliSeconds(200);
    return 0;
}
