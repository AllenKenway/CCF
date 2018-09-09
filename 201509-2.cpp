#include<stdio.h>
#include<stdlib.h>

int main()
{

	int y;
	scanf("%d", &y);
	int d;
	scanf("%d", &d);

	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		days[1]++;

	int i = 0;
	int day = 0;
	while (d > 0)
	{
		if (d > days[i])
		{
			d = d - days[i];
			i = i + 1;
		}
		else
		{
			printf("%d\n%d", i + 1, d);
			break;
		}

	}


	system("pause");
	return 0;
}