#include<stdio.h>
#include<stdlib.h>


int main()
{

	int n;
	scanf("%d", &n);

	int s[1000] = {0};

	int i,j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		s[j - 1]++;
		printf("%d ", s[j - 1]);
	}

//	system("pause");
	return 0;
}