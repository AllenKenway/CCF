#include<stdio.h>
#include<cstdlib>

int main()
{
	int n,s,result=0;
	int a[1000] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s);
		a[s]++;
	}
	for (int i = 0; i < 1000-1; i++)
	{
		if (a[result] < a[i])
			result = i;
	}
	printf("%d", result);
	system("pause");
	return 0;
}