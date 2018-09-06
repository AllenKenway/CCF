#include<stdio.h>

int main()
{
	int a = 0;
	int sum = 0, plus = 1;
	while (1)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			plus = 1;
			sum = sum + plus;
		}
		else if (a == 2)
		{
			if (plus == 1)
				plus = 2;
			else
				plus = plus + 2;
			sum = sum + plus;
		}
		else
			break;
	}
	printf("%d", sum);
	return 0;
}
