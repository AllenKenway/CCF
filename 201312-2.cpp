#include<stdio.h>

int main()
{
	char s[20];
	scanf("%s", s);

	int sum = 0,i,j;

	for (i = 0,j = 1; j <= 9; i++)
	{
		if (s[i] == '-')
			continue;
		sum = sum + j * (s[i]-'0');
		j++;
	}
	sum = sum % 11;
	if ((sum + '0') == s[12] || ((sum == 10) && (s[12] == 'X')))
		printf("Right");
	else
	{
		if (sum < 10)
			s[12] = sum + '0';
		else
			s[12] = 'X';
		printf("%s", s);
	}

	return 0;
}
