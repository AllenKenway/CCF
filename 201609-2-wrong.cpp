//µÃ·Ö£º90
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	int l[20] = { 0 };
	int s[100] = { 0 };
	int num[100] = { 0 };
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	
	int p;
	bool flag = true;
	for (i = 0; i < n; i++)
	{
		p = num[i];
		flag =false;
		for (j = 0; j < 20; j++)
		{
			if (5 - l[j] >= p)
			{
				for (k = j * 5 + l[j]; k < 5 * j + p + l[j]; k++)
				{
					s[k] = 1;
					printf("%d ", k + 1);
				}
				flag = true;
				l[j] = l[j] + p;
				break;
			}
		}
		if (flag == false)
		{
			for (j = 0; p>0; j++)
			{
				if (s[j] == 0) 
				{
					s[j] = 1;
					l[j / 5] += 1;
					p--;
					printf("%d ", s[j]);
				}
			}
		}
		printf("\n");
	}

	system("pause");
	return 0;
}