#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int s[1000];
	int i, j;
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	int min = abs(s[1]-s[0]);
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (abs(s[j] - s[i]) < min)
				min = abs(s[j] - s[i]);
		}
	}
	printf("%d", min);


	system("pause");
	return 0;
}