#include<stdio.h>
#include<stdlib.h>

typedef struct BALL {
	int x;
	bool vector;
};
int main()
{
	int n, L, t;
	scanf("%d %d %d", &n, &L, &t);

	BALL a[100];
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i].x);
		a[i].vector = 1;//1表示向右 0表示向左
	}



	//判断是否有碰撞
	for (k = 0; k < t; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i].vector == 1)
				a[i].x++;
			else
				a[i].x--;
		}
		for (i = 0; i < n; i++)
		{
			if (a[i].x == L)a[i].vector = 0;
			else if (a[i].x == 0)a[i].vector = 1;
			else
			{
				for (j = i+1; j < n; j++)
				{
					if (a[i].x == a[j].x)
					{
						a[i].vector = !a[i].vector;
						a[j].vector = !a[j].vector;
					}
				}
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i].x);


	system("pause");
	return 0;
}