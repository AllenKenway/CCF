//得分：10
//时间使用：1.187s
//空间使用：404.0KB
#include<stdio.h>

int match(int num);
int main()
{
	int n, result = 0;
	scanf("%d", &n);

	int i, first = 2, last = 3;
	for (i = 0; i < n - 1; i++)
	{
		first = first * 10;
		last = last * 10 + 3;
	}

	for (; first <= last; first++)
		if (match(first) == 1)
			result++;
	result = result % 1000000007;
	printf("%d", result);

	return 0;
}
int match(int num)
{
	bool flag0 = false, flag2 = false, flag1 = false, flag3 = false;
	int a;
	while (num != 0)
	{
		a = num % 10;
		num = num / 10;
		if (a >= 4)
			return 0;
		else if (a == 1)
		{
			if (flag0 == true)
				return 0;
			flag1 = true;
		}
		else if (a == 3)
		{
			if (flag2 == true)
				return 0;
			flag3 = true;
		}
		else if (a == 0)
			flag0 = true;
		else if (a == 2)
			flag2 = true;
	}

	if (flag0 == true && flag1 == true && flag2 == true && flag3 == true)
		return 1;

	return 0;
}