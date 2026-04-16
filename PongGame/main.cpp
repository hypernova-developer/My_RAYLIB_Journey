#include <raylib.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};


int player_score = 0;
int cpu_score = 0;

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
        DrawCircle(x, y, radius, Yellow);
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
        if (x + radius >= GetScreenWidth()) // CPU Wins
        {
            cpu_score++;
            ResetBall();
        }
        
        if (x - radius <= 0) // Player Wins
        {
            player_score++;
            ResetBall();
        }
    }

    void ResetBall()
    {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speedX *= speed_choices[GetRandomValue(0,1)];
        speedY *= speed_choices[GetRandomValue(0,1)];
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
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
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

    InitWindow(screenWidth, screenHeight, "Hy-Pong");
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

        // Checking for Collision
        
        if (CheckCollisionCircleRec(Vector2 {ball.x, ball.y}, ball.radius, Rectangle {player.x, player.y, player.width, player.height}))
        {
            ball.speedX *= -1;
        }
        if (CheckCollisionCircleRec(Vector2 {ball.x, ball.y}, ball.radius, Rectangle {cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speedX*= -1;
        }

        // Drawing the Paddles as Rectangles...
        ClearBackground(Dark_Green);
        DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
        DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        ball.Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", cpu_score), screenWidth / 4 -20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * screenWidth / 4 -20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    sleepForMilliSeconds(200);
    return 0;
}
