#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int N;
	scanf("%d", &N);

	int i;
	int n = N / 10;
	int max = 0;
	int now;
	for (i = 0; i < n; i++)
	{
		now = (i / 3) * 4 + ((n - i) / 5) * 7 + (n - i) % 5;
		if (now> max)
			max = now ;
	}

	printf("%d", max);
	system("pause");
	return 0;
}