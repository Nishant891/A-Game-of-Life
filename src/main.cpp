#include <raylib.h>
#include "simulation.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int ScreenWidth = 1800;
    const int ScreenHeight = 1000;
    int CellSize = 10;
    int FPS = 16;

    InitWindow(ScreenWidth, ScreenHeight, "Conway's game of life");
    SetTargetFPS(FPS);

    Simulation Simulation(ScreenWidth, ScreenHeight, CellSize);

    /*Simulation.FillPattern({{13, 5, 1},
            {13, 13, 1}, {12, 13, 1}, {13, 14, 1}, 
            {12, 22, 1}, {12, 24, 1}, {14, 23, 1}, 
            {13, 32, 1}, {12, 31, 1}, {12, 33, 1}, {14, 31, 1}, {14, 33, 1},
    });*/

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            /*Vector2 MousePosition = GetMousePosition();
            int MousePositionX = MousePosition.y/CellSize;
            int MousePositionY = MousePosition.x/CellSize;*/
            int PosX = GetTouchX() / CellSize;
            int PosY = GetTouchY() / CellSize;
            // cout<<PosY/CellSize<<","<<PosX/CellSize<<endl;
            Simulation.ToggleCell(PosY, PosX);
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            Simulation.Start();
            SetWindowTitle("Simulation Started.");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            Simulation.Stop();
            SetWindowTitle("Simulation Stopped.");
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
            Simulation.FillRandom();
            SetWindowTitle("Random values filled.");
        }
        else if (IsKeyPressed(KEY_C))
        {
            Simulation.ClearGrid();
            SetWindowTitle("Grid is cleared.");
        }
        else if (IsKeyPressed(KEY_ONE))
        {
            //Glider
            Simulation.FillPlainText(
                ".O.\n"
                "..O\n"
                "OOO\n",
                20,
                20
            );
            SetWindowTitle("Glider is running.");
        }
        else if (IsKeyPressed(KEY_TWO))
        {
            //Glider Period 30
            Simulation.FillPlainText(
                "........................O...........\n"
                "......................O.O...........\n"
                "............OO......OO............OO\n"
                "...........O...O....OO............OO\n"
                "OO........O.....O...OO..............\n"
                "OO........O...O.OO....O.O...........\n"
                "..........O.....O.......O...........\n"
                "...........O...O....................\n"
                "............OO......................\n",
                20,
                20
            );
            SetWindowTitle("Gospel glider gun period 30 is running.");
        }
        else if (IsKeyPressed(KEY_THREE))
        {
            //Glider Period 60
            Simulation.FillPlainText(
                "............................O..........\n"
                "............................O.O........\n"
                "...........OO..................OO......\n"
                ".........O...O.................OO....OO\n"
                "...OO...O.....O................OO....OO\n"
                "...OO..OO.O...O.............O.O........\n"
                "........O.....O.............O..........\n"
                ".........O...O.........................\n"
                "...........OO..........................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                "..........O.O..........................\n"
                ".........O..O...OO.....................\n"
                "OO......OO.....OOO.OO..OO..............\n"
                "OO....OO...O...O...O...O.O.............\n"
                "........OO.....O.O........O............\n"
                ".........O..O..OO......O..O............\n"
                "..........O.O.............O............\n"
                ".......................O.O.......OO....\n"
                ".......................OO........O.O...\n"
                "...................................O...\n"
                "...................................OO..\n",
                20,
                20
            );
            SetWindowTitle("Gospel glider gun period 60 is running.");
        }
        else if (IsKeyPressed(KEY_FOUR))
        {
            //Continous glider
            Simulation.FillPlainText(
                ".O...........................\n"
                "..O..........OO..............\n"
                "OOO.........OOO..............\n"
                "............OO.O.............\n"
                ".....O.......OOO.............\n"
                "...O.O........O..............\n"
                "....OO.......................\n"
                ".............................\n"
                "......................OOOO...\n"
                ".....................OOOOOO..\n"
                "....................OOOOOOOO.\n"
                "............O......OO......OO\n"
                "...OO.....O.O.......OOOOOOOO.\n"
                ".OO.OO.....OO........OOOOOO..\n"
                ".OOOO..........O......OOOO...\n"
                "..OO............O............\n"
                "..............OOO............\n"
                ".............................\n"
                ".............................\n"
                ".............................\n"
                ".....OOOOOOO.................\n"
                "...OOO.OOO.OOO...............\n"
                "..O....OOO....O..............\n"
                "...OOOO.O.OOO.O..............\n"
                ".............O...............\n"
                "..O.OO.O.O.O.................\n"
                "..OO.O.O.O.OO................\n"
                "......O..O.O.................\n"
                ".......OO..O.................\n"
                "...........OO................\n",
                20,
                20
            );
        }
        else if (IsKeyPressed(KEY_FIVE))
        {
            //Glider with eater
            Simulation.FillPlainText(
               "........................O..........................\n"
               "......................O.O..........................\n"
               "............OO......OO............OO...............\n"
               "...........O...O....OO............OO...............\n"
               "OO........O.....O...OO.............................\n"
               "OO........O...O.OO....O.O..........................\n"
               "..........O.....O.......O..........................\n"
               "...........O...O...................................\n"
               "............OO.....................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "..........................................OO.......\n"
               "..........................................O.O......\n"
               "............................................O......\n"
               "............................................OO.....\n"
               "...................................................\n"
               "...................................................\n",
                20,
                20
            );
        }
        Simulation.Update();
        BeginDrawing();
        ClearBackground(GREY);
        Simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}
