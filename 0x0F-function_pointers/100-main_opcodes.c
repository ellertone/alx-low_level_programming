#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: pointer to an array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    int i, nbytes;
    char *main_ptr;

    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    nbytes = atoi(argv[1]);

    if (nbytes < 0)
    {
        printf("Error\n");
        exit(2);
    }

    main_ptr = (char *)main;

    for (i = 0; i < nbytes; i++)
    {
        printf("%02hhx", main_ptr[i]);

        if (i != nbytes - 1)
            printf(" ");
    }

    printf("\n");

    return (0);
}

