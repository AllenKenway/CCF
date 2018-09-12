#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int s[1000];
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	int max;
	max = abs(s[0] - s[1]);
	for (i = 1; i < n - 1; i++)
	{
		if (max < (abs(s[i] - s[i + 1])))
			max = abs(s[i] - s[i + 1]);
	}
	printf("%d", max);

	system("pause");
	return 0;
}