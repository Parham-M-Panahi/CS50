#include <stdio.h>
#include <cs50.h>

void draw_pyramid(int);
void draw_row(int, int);


int main(void)
{
    int height;
    do
    {
	height = get_int("Height: ");
    }while (height <= 0 || height > 23);

    draw_pyramid(height);
}

void draw_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
	draw_row(i, height);
    }
}

void draw_row(int row, int height)
{
    for (int i = 0; i < height - row; i++)
    {
	printf(" ");
    }
    for (int i = 0; i < row; i++)
    {
	printf("#");
    }
    printf("  ");
    for (int i = 0; i < row; i++)
    {
	printf("#");
    }
    for (int i = 0; i < height - row; i++)
    {
	printf(" ");
    }
    printf("\n");
}
