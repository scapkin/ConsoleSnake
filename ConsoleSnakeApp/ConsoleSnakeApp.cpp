#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;

int playerX, playerY;
int  fruitX, fruitY;
int score;

enum PlayerDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
PlayerDirection dir;
int tailX[100], tailY[100];
int nTail;


void Setup()
{
    gameOver = false;
    dir = STOP;
    playerX = width / 2;
    playerY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    cout << "       Score:" << score << endl;
    for (int i = 0; i < width+2; i++)
        cout << "-";
    cout << endl;
 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "*";
            if (i == playerY && j == playerX)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "G";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == width - 1)
                cout << "*";
        }
        cout << endl;
    }
 
    for (int i = 0; i < width+2; i++)
        cout << "-";
    cout << endl;
    
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 75:
            dir = LEFT;
            break;
        case 77:
            dir = RIGHT;
            break;
        case 72:
            dir = UP;
            break;
        case 80:
            dir = DOWN;
            break;
        case ' ':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = playerX;
    tailY[0] = playerY;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        playerX--;
        break;
    case RIGHT:
        playerX++;
        break;
    case UP:
        playerY--;
        break;
    case DOWN:
        playerY++;
        break;
    default:
        break;
    }
    
    if (playerX >= width) playerX = 0; else if (playerX < 0) playerX = width - 1;
    if (playerY >= height) playerY = 0; else if (playerY < 0) playerY = height - 1;
 
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == playerX && tailY[i] == playerY)
            gameOver = true;
 
    if (playerX == fruitX && playerY == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(50); //sleep(10);
    }
    return 0;
}

