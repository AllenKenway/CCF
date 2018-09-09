#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n;
	scanf("%d", &n);

	int i;
	int pri, now;

	scanf("%d", &pri);
	int count = 1;
	for (i = 1; i < n; i++)
	{
		scanf("%d", &now);
		if (now != pri)
		{
			count++;
			pri = now;
		}
	}
	printf("%d",count);

	system("pause");
	return 0;
}