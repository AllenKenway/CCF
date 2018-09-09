#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n, m;
	scanf("%d %d", &n, &m);

	int s[30][30];

	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &s[i][j]);


	int visited[30][30];;
	for (i = 0; i < n; i++)
		for (j = 0; j <m; j++)
			visited[i][j] = 0;


	for (i = 0; i < n ; i++)
	{
		for (j = 0; j < m - 2; j++)
		{

			if (s[i][j] == s[i][j+1] && s[i][j+1] == s[i][j+2])
			{
				visited[i][j] = 1;
				visited[i][j + 1] = 1;
				visited[i][j + 2] = 1;
				for (k = j + 2; k < n; k++)
				{
					if (s[i][k] == s[i][j])
					{
						visited[i][k] = 1;
					}
					else
						break;
				}
			}

		}

	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n - 2; j++)
		{

			if (s[j][i] == s[j+1][i] && s[j+1][i] == s[j+2][i])
			{
				visited[j][i] = 1;
				visited[j+1][i] = 1;
				visited[j+2][i] = 1;
				for (k = j + 2; k < m; k++)
				{
					if (s[k][i] == s[j][i])
					{
						visited[k][i] = 1;
					}
					else
						break;
				}
			}

		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (visited[i][j] == 1)
				printf("0 ");
			else
				printf("%d ", s[i][j]);
		}
		printf("\n");
	}



	system("pause");
	return 0;
}