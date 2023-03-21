#include <stdio.h>
/**
* main - first 50 fibonacci numbers
* multiplies of 3 or 5 and sum of the multiples
*
* Return: Always 0.
*/
int main(void)
{
	int i;
	unsigned long int sum;
	unsigned long int n1 = 0;
	unsigned long int n2 = 1;

	for (i = 1; i <= 98; i++)
	{
		sum = n1 + n2;
		printf("%lu", sum);
		n1 = n2;
		n2 = sum;
		if (i < 98)
			printf(", ");
	}
	printf("\n");
	return (0);
}
