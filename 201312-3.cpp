#include<stdio.h>
#include<cstdlib>

int min(int h[1000], int i, int j);
int main()
{
	int n, h[1000];
	int x, y,square,result=0;
	scanf("%d", &n);
	int i,j;
	for (i = 0; i < n; i++)
		scanf("%d", &h[i]);

	for(i=0;i<n;i++)
		for (j = i; j < n; j++)
		{
			x = j - i + 1;
			y = min(h, i, j);
			square = x*y;
			if (square > result)
				result = square;
		}

	printf("%d", result);

	return 0;
}
int min(int h[1000], int i, int j)
{
	int count = i,min = h[i];
	for (; count <= j; count++)
	{
		if (min > h[count])
			min = h[count];
	}
	return min;
}