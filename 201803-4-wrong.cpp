//µÃ·Ö£º10
#include<stdio.h>
#include<stdlib.h>

int pinggu(int a[3][3], int nx, int no, int nk);
int pinggu(int a[3][3],int nx, int no, int nk)
{
	int flag = 0;
	int i, j;
	int score;



	for (j = 0; j < 3; j++)
		if (a[j][0] == a[j][1] && a[j][0] == a[j][2] && a[j][0] != 0)
		{
			if (a[j][0] == 1)score = nk + 1;
			else score = -nk - 1;
			flag = 1;
			break;
		}

	for (j = 0; j < 3; j++)
		if (a[0][j] == a[1][j] && a[0][j] == a[2][j] && a[0][j] != 0)
		{
			if (a[0][j] == 1)score = nk + 1;
			else score = -nk - 1;
			flag = 1;
			break;
		}

	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != 0)
	{
		if (a[0][0] == 1)score = nk + 1;
		else score = -nk - 1;
		flag = 1;
	}
	else if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != 0)
	{
		if (a[0][0] == 1)score = nk + 1;
		else score = -nk - 1;
		flag = 1;
	}

	if (flag == 0)
		score = 0;
	return score;
}
int main()
{
	int T;
	scanf("%d", &T);


	int i, j, k;
	int score, smax;
	int nx = 0;
	int no = 0;
	int nk = 0;
	int a[3][3];

	for (i = 0; i < T; i++)
	{
		nx = 0;
		nk = 0;
		no = 0;
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
			{
				scanf("%d", &a[j][k]);
				if (a[j][k] == 1)nx++;
				else if (a[j][k] == 2)no++;
				else nk++;
			}
		score = pinggu(a, nx, no, nk);
		if (score == 0 && nk != 0)
		{
			for (j = 0; j < 3; j++)
				for (k = 0; k < 3; k++)
				{
					if (a[j][k] == 0)
					{
						a[j][k] = 1;
						nk--;
						nx++;
						smax = pinggu(a, nx, no, nk);
						if (smax > score)
							score = smax;
						a[j][k] = 0;
						nk++;
						nx--;
							
					}
				}
		}

		printf("%d\n", score);
	}



	system("pause");
	return 0;
}