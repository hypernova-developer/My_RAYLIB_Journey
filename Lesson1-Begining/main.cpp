#include <raylib.h>

int main()
{
    int ballX = 400;
    int ballY = 400;
    Color myBlue = {15, 75, 255, 255};
    
    InitWindow(800, 800, "Eighth Attempt =]");
    SetTargetFPS(60);

    //Game Loop Here <3
    while (WindowShouldClose() == false)
    {
        // 1. Event Gandling
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            ballX += 3;
        }
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        {
            ballX -= 3;
        }
        else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            ballY -= 3;
        }
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            ballY += 3;
        }

        // 2. Updating Positions

        // 3. Drawing Objects
        BeginDrawing();
        ClearBackground(myBlue);
        DrawCircle(ballX, ballY, 20.0, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
