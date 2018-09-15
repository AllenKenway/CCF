//考虑所有情况 得分30
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct KEY {
	int w;
	int s;
	int e;
};
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	struct KEY key[1005];
	int i, j, k;
	for (i = 0; i < K; i++)
	{
		scanf("%d %d %d", &key[i].w, &key[i].s, &key[i].e);
		key[i].e += key[i].s;
	}

	int seat[1005];
	for (i = 0; i < N; i++)
		seat[i] = i + 1;
	for (; i < 1005; i++)
		seat[i] = 0;

	int t;
	int max, num;
	int daihuan[1005];
	bool flag = false;
	for (t = 0; t < 10200; t++)
	{
		k = 0;
		for (i = 0; i < 1005; i++)
			daihuan[i] = 0;
		for (i = 0; i < K; i++)
		{
			if (key[i].e == t)
			{
				daihuan[k] = key[i].w;
				k++;
			}
			else if (key[i].e > t) flag = true;
		}
		if (flag == false)break;
		for (k--; k >= 0; k--)
		{
			max = daihuan[k];
			i = 0;
			for (;i < k; i++)
				if (daihuan[i] > max)
				{
					max = daihuan[i];
					num = i;
				}
			daihuan[i] = daihuan[k];
			daihuan[k] = max;
		}

		for (i = 0;daihuan[i]!=0; i++)
		{
			for (j = 0; j < N; j++)
				if (seat[j] == 0)
				{
					seat[j] =daihuan[i];
					break;
				}
		}
		for (i = 0; i < K; i++)
		{
			if (key[i].s == t)
			{
				for (j = 0; j < N; j++)
				{
					if (seat[j] == key[i].w)
					{
						seat[j] = 0;
						break;
					}

				}
			}
		}

	}

	for (i = 0; i < N; i++)
		printf("%d ", seat[i]);


	system("pause");
	return 0;
}