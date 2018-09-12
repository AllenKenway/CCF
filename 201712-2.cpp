#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n, k;
	scanf("%d %d", &n,&k);
	int s[1000];
	int i, j;
	for (i = 0; i < n; i++)
		s[i] = 1;
	for (; i < 1000; i++)
		s[i] = 0;

	int count=0;
	i = 0;
	j = n;
	while (j != 1)
	{
		if (s[i%n] == 0)
			i++;
		else
		{
			count++;
			if (count%k == 0 || count%10 == k )
			{
				j--;
				s[i%n] = 0;
			}
			i++;
		}

	}

	for (i = 0; i < n; i++)
		if (s[i] == 1)
			printf("%d", i+1);

	system("pause");
	return 0;
}