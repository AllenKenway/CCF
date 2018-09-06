#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int s[500];

	int i, j, count = 0;

	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	for (i = 0; i < n; i++)
		 for (j = i; j < n; j++)
		 {
			 if (s[i] == -s[j])
				 count++;
		 }

	printf("%d", count);


	return 0;
}