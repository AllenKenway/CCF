#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n;
	scanf("%d", &n);

	int s[1000];
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	int count = 0;
	for (i = 1; i < n-1; i++)
	{
		if ((s[i] > s[i - 1] && s[i] > s[i + 1]) || (s[i]<s[i - 1] && s[i]<s[i + 1]))
			count++;
	}

	printf("%d", count);

	system("pause");
	return 0;
}