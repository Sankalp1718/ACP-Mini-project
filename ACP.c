#include <stdio.h>

#define ROWS 20
#define COLS 40

char pic[ROWS][COLS];

void clearPicture()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            pic[i][j] = '_';
        }
    }
}

void displayPicture()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", pic[i][j]);
        }
        printf("\n");
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2)
    {
        for(i = x1; i <= x2; i++)
        {
            pic[y1][i] = '*';
        }
    }
    else if(x1 == x2)
    {
        for(i = y1; i <= y2; i++)
        {
            pic[i][x1] = '*';
        }
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i;

    for(i = x; i < x + width; i++)
    {
        pic[y][i] = '*';
        pic[y + height - 1][i] = '*';
    }

    for(i = y; i < y + height; i++)
    {
        pic[i][x] = '*';
        pic[i][x + width - 1] = '*';
    }
}

void drawTriangle(int x, int y, int h)
{
    int i;

    for(i = 0; i < h; i++)
    {
        pic[y + i][x - i] = '*';
        pic[y + i][x + i] = '*';
    }

    for(i = x - h + 1; i <= x + h - 1; i++)
    {
        pic[y + h - 1][i] = '*';
    }
}

void drawCircle(int xc, int yc, int r)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int dx = x - xc;
            int dy = y - yc;
            int d = dx * dx + dy * dy;

            if(d >= r * r - r && d <= r * r + r)
            {
                pic[y][x] = '*';
            }
        }
    }
}

void deletePicture()
{
    clearPicture();
}

int main()
{
    clearPicture();

    drawLine(2, 2, 15, 2);
    drawRectangle(20, 2, 10, 6);
    drawTriangle(10, 10, 5);
    drawCircle(30, 14, 4);

    printf("Picture:\n");
    displayPicture();

    printf("\nAfter deleting picture:\n");
    deletePicture();
    displayPicture();

    return 0;
}
