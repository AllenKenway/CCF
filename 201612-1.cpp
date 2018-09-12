#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i, j;
	int s[1000];
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	int high = 0, low = 0;

	for (i = 0; i < n; i++)
	{
		high = 0, low = 0;
		for (j = 0; j < n; j++)
		{
			if (s[j] > s[i])high++;
			else if (s[j] < s[i])low++;
		}

		if (high == low)
		{
			printf("%d", s[i]);
			system("pause");
			return 0;
		}
	}
	printf("%d", -1);


	system("pause");
	return 0;
}