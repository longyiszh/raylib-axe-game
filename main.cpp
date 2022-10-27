#include "raylib.h"

int main()
{
    // Window dimension
    int width = 800;
    int height = 600;
    InitWindow(width, height, "Raylib Axe Game");

    // Circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};

    // Circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // Axe coordinates
    int axe_x{width / 2};
    int axe_y{0};
    int axe_size{50};
    int axe_speed{10};

    // Axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_size};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_size};

    // States
    bool collision_with_axe = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // update edges
        l_circle_x = circle_x - circle_radius;
        r_circle_x = circle_x + circle_radius;
        u_circle_y = circle_y - circle_radius;
        b_circle_y = circle_y + circle_radius;
        l_axe_x = axe_x;
        r_axe_x = axe_x + axe_size;
        u_axe_y = axe_y;
        b_axe_y = axe_y + axe_size;

        // detect collision
        collision_with_axe =
            r_circle_x >= l_axe_x &&
            u_circle_y <= b_axe_y &&
            l_circle_x <= r_axe_x &&
            b_circle_y >= u_axe_y;

        if (collision_with_axe)
        {
            DrawText("Game Over!", 200, 200, 60, RED);
        }
        else
        {
            // Begin game logic
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_size, axe_size, RED);

            // Move axe
            axe_y += axe_speed;

            if (axe_y < 0 || axe_y > (height - axe_size))
            {
                axe_speed *= -1;
            }

            if (IsKeyDown(KEY_A) && l_circle_x > 0)
            {
                circle_x -= 10;
            }

            if (IsKeyDown(KEY_D) && r_circle_x < width)
            {
                circle_x += 10;
            }

            // End game logic
        }

        EndDrawing();
    }
}