//得分：10
#include<stdio.h>
#include<stdlib.h>

int main()
{

	int i, j, k;

	int s[20][10];
	for (i = 0; i < 15; i++)
		for (j = 0; j < 10; j++)
			scanf("%d", &s[i][j]);
	for (; i < 20; i++)
		for (j = 0; j < 10; j++)
			s[i][j] = 0;

	int s1[4][4];
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &s1[i][j]);
			

	int s2;
	scanf("%d", &s2);

	int f;
	for (i = 0; i <15; i++)
	{
		f = 1;
		for (k = 0; k < 4; k++)
		{
			for (j = s2 - 1; j < s2 + 3; j++)
			{
				if (s[i+k][j] == 1 && s1[k][j - 2] == 1)
				{
					f = 0;
					break;
				}
			}
			if (f == 0)break;
		}
		if (f == 0)
		{
			i--;
			for (k = 0; k < 4; k++)
				for (j = s2 - 1; j < s2 + 4; j++)
				{
					if(s1[k][j - 2]==1)
						s[i + k][j] = s1[k][j - 2];
				}	
			break;
		}
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 10; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}


	system("pause");
	return 0;
}
