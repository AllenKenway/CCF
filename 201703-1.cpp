#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int a[1000];
	int i, j;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int w = 0;
	int count = 0;
	for (i = 0; i < n;)
	{
		w = a[i];
		if (w < k)
		{
			for (j = i + 1; j < n; j++)
			{
				w = w + a[j];
				if (w >= k) break;
			}
			i = j + 1;
		}
		else
			i++;
		count++;
	}

	printf("%d", count);
	system("pause");
	return 0;
}