#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 * description: print the value of n status:
 * greater than, is zero and is not less than 6.
 * Return: Always O (Success)
*/

int main(void)
{
	int i, dig;

	srand(time(0));
	i = rand() - RAND_MAX / 2;
	dig = i % 10;

	if (dig > 5)
		printf("Last digit of %i is %i and is greater than 5\n", i, dig);
	else if (dig == 0)
		printf("Last digit of %i is %i and is 0\n", i, dig);
	else if (dig < 6 && dig != 0)
		printf("Last digit of %i is %i and is less than 6 and not 0\n", i, dig);
	return (0);
}
