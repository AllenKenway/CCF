#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int i, j, k;
	int p[1000], q[1000];
	for (i = 0; i < m; i++)
		scanf("%d %d", &p[i], &q[i]);

	int s[1000];
	for (i = 0; i < n; i++)
		s[i] = i + 1;

	int temp;
	for (i = 0; i < m; i++)
	{
		for (k = 0; k < n; k++)
			if (s[k] == p[i])break;
		if (q[i] >= 0)
		{
			for (j = k; j < k + q[i] ; j++)
			{
				s[j] = s[j + 1];
			}
			s[j] = p[i];
		}
		else
		{
			for (j = k; j > k + q[i] ; j--)
			{
				s[j] = s[j - 1];
			}
			s[j] = p[i];
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", s[i]);

	system("pause");
	return 0;
}