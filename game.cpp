#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "game.h"

extern int fps;
int snake_length = 5;

int gridX, gridY;

bool food = true;
int foodX, foodY;

int positionX[60] = {20, 20, 20, 20, 20}, positionY[60] = {20, 19, 18, 17, 16};

short snakeDirection = RIGHT;

extern int score;

extern bool gameOver;

void drawUnit(int, int);

void initGrid(int x, int y)
{
    gridX = x;
    gridY = y;
}

void drawGrid()
{
    for (int x = 0; x < gridX; x++)
        for (int y = 0; y < gridY; y++)
            drawUnit(x, y);
}

void drawUnit(int x, int y)
{

    if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
    {
        glLineWidth(3.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x, y + 1);
        glEnd();
    }
//    else
//    {
//        glLineWidth(1.0);
//        glColor3f(1.0, 1.0, 1.0);
//    }


}

void drawFood()
{
    if (food)
        random(foodX, foodY);
    food = false;
    glColor3f(1.0, 0.0, 0.0);
    glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void drawSnake()
{
    for (int i = snake_length - 1; i > 0; i--)
    {
        positionX[i] = positionX[i - 1];
        positionY[i] = positionY[i - 1];
    }
    if (snakeDirection == UP)
        positionY[0]++;
    else if (snakeDirection == DOWN)
        positionY[0]--;
    else if (snakeDirection == RIGHT)
        positionX[0]++;
    else if (snakeDirection == LEFT)
        positionX[0]--;
    for (int i = 0; i < snake_length; i++)
    {
        if (i == 0)
            glColor3f(0.0, 1.0, 0.0);
        else
            glColor3f(0.0, 0.0, 1.0);
        glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
    }


    if (positionX[0] == 0 || positionX[0] == gridX - 1 || positionY[0] == 0 || positionY[0] == gridY - 1)
        gameOver = true;
    for (int i = 1; i < snake_length; i++)
        if (positionX[0] == positionX[i] && positionY[0] == positionY[i])
            gameOver = true;
    if (positionX[0] == foodX & positionY[0] == foodY)
    {
        score ++;
        snake_length++;
        if (snake_length > 60)
            snake_length = MAX;
        food = true;
        fps++;
    }

}

void random(int &x, int &y)
{
    int maximumValueX = gridX - 2;
    int maximumValueY = gridY - 2;
    int miniumValue = 1;
    srand(time(NULL));
    x = miniumValue + rand() % (maximumValueX - miniumValue);
    y = miniumValue + rand() % (maximumValueY - miniumValue);
}
