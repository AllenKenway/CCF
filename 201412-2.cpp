#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int s[500][500];
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &s[i][j]);


	i = 0; j = 0;
	printf("%d ", s[i][j]);
	while (1)
	{
		if (i == (n - 1) && j == (n - 1))
			break;

		if (j == n - 1)
			i++;
		else
			j++;

		if (i == (n - 1) && j == (n - 1))
			break;

		for (; j >= 0&&i < n; i++, j--)
			printf("%d ", s[i][j]);
		i--; j++;

		if (i == (n - 1) && j == (n - 1))
			break;

		if (i == n - 1)
			j++;
		else
			i++;

		for (; i >= 0&&j < n; i--, j++)
			printf("%d ", s[i][j]);	
		i++; j--;
		if (i == (n - 1) && j == (n - 1))
			break;
		
	}

//	system("pause");
	return 0;
}