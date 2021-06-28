#include <stdio.h>

void	mb(int *a)
{
	*a = 5;
}

void	test(int *a)
{
	return (mb(a));
}

int main(int argc, char const *argv[])
{
	
	int a;
	test(&a);
	printf("====%d", a);

	for (int i=1; i<argc; i++)
		printf("%s\n", argv[i]);
	return 0;
}
