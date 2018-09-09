#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n;
	scanf("%d", &n);
	int i = 0, j = 0;
	int count[1005] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		count[j]++;
	}

	int max, t;

	for (i = 1005; i>0; i--)
	{
		for (j = 0; j < 1005; j++)
		{
			if (count[j] == i)
			{
				printf("%d %d\n", j, count[j]);
				continue;
			}
		}
	}

	system("pause");
	return 0;
}