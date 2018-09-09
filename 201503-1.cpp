#include<stdio.h>
#include<stdlib.h>

int s[1000][1000];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &s[i][j]);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", s[j][m - i - 1]);
		}
		printf("\n");
	}

			

	system("pause");
	return 0;
}