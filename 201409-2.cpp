#include<stdio.h>
#include<stdlib.h>

typedef struct Square{
	int x1, x2, y1, y2;
}Square;
int main()
{
	Square s[100];

	int n;
	scanf("%d", &n);

	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
	}

	int visited[100][100];
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			visited[i][j] = 0;
	
	for (i = 0; i < n; i++)
	{
		for (j = s[i].x1; j < s[i].x2; j++)
			for (k = s[i].y1; k <= s[i].y2; k++)
				visited[j][k] = 1;
	}

	int count = 0;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			if (visited[i][j] == 1)
				count++;

	printf("%d", count);

	//system("pause");
	return 0;
}