#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n;
	scanf("%d", &n);

	int a = 0;
	while (n > 0)
	{
		a += n % 10;
		n = n / 10;
	}
	printf("%d", a);


	system("pause");
	return 0;
}