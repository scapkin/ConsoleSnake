#include <iostream>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;

int playerX, playerY, fruitX, fruitY, score;

enum PlayerDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

PlayerDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    playerX = width / 2;
    playerY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (j == 0)
                cout << "#";
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < width+2; i++)
        cout << "#";
}

void Input()
{
}

void Logic()
{
}

int main()
{
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        //Sleep(10);
    }
    return 0;
}
