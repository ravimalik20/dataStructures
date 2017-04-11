#include<stdio.h>
#include<assert.h>

#define PRINT_FACTORIAL(num) printf("Factorial of %d is %d\n", (num), factorial((num)))

int factorial(int num)
{
	assert(num >= 0);

	if (num == 0)
		return 1;

	return num * factorial(num-1);
}

void main()
{
	int i=0;

	for (i=0 ; i < 10 ; i++)
		PRINT_FACTORIAL(i);
}
