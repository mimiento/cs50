#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height:\n"); //recieve user inputted height for pyramid
    }
    while (height < 1 || height > 8);

    int column = 0;
    int spaces = height - 1;

    for (int i = 0; i < height; i++) //creates pyramid with inputted height
    {
        for (int k = 0; k < spaces; k++) //left-aligns the pyramid
        {
            printf(" ");
        }
        for (int j = 0; j <= column; j++) //prints the pyramid
        {
            printf("#");
        }
        printf("\n");
        column++;
        spaces--;
    }
}