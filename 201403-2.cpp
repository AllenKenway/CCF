#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int num;
	int x1, x2, y1, y2;
}Node;
Node node[10];
int visited[2559][1439];

void re_sort(int i,int N);

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	int i,j;
	for (i = 0; i < N; i++)
	{
		node[i].num = i + 1;
		scanf("%d %d %d %d", &node[i].x1, &node[i].y1, &node[i].x2, &node[i].y2);
	}
		

	int x, y;
	int m, n, flag ;

	for (j = 0; j < M; j++)
	{
		flag = 0;
		for (m = 0; m < 2559; m++)
			for (n = 0; n < 1439; n++)
				visited[m][n] = 0;
		scanf("%d %d", &x, &y);
		for (i = N - 1; i >= 0; i--)
		{

			if (visited[x][y]==0 && node[i].x1 <= x && x <= node[i].x2 && node[i].y1 <= y && y <= node[i].y2)
			{
				printf("%d\n", node[i].num);
				re_sort(i,N);
				flag = 1;
				break;
			}	
		}
		for (m = node[i].x1; m <= node[i].x2; m++)
			for (n = node[i].y1; n <= node[i].y2; n++)
				visited[m][n] = 1;
		if (flag == 0)printf("IGNORED\n");
	}


	system("pause");
	return 0;
}
void re_sort(int i, int N)
{
	int j = 0;
	Node temp = node[i];
	for (j = i; j < N - 1; j++)
		node[j] = node[j + 1];
	node[N - 1] = temp;
}