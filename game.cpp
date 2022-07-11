#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

int gridX, gridY;

int positionX = 20, positionY = 20;

short snakeDirection = RIGHT;

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
    }
    else
    {
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }

    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}

void drawSnake()
{
    if (snakeDirection == UP)
        positionY++;
    else if (snakeDirection == DOWN)
        positionY--;
    else if (snakeDirection == RIGHT)
        positionX++;
    else if (snakeDirection == LEFT)
        positionX--;
    glRectd(positionX, positionY, positionX + 1, positionY + 1);
}
