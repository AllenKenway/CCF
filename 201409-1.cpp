#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int num[1000];
	int i, j;
	int count = 0;

	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (abs(num[i] - num[j]) == 1)
				count++;
		}

	printf("%d", count);
	return 0;
}