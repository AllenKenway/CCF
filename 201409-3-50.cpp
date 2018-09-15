//µÃ·Ö50
#include<stdio.h>
#include<stdlib.h>

int match(char s1[105], char s2[105]);
int main()
{
	int i, j;
	char s[105];
	scanf("%s", s);
	int c;
	scanf("%d", &c);
	if (c == 0)
	{
		for (i = 0; i < 105 && s[i] != '\0'; i++)
			if (s[i] >= 'A'&&s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a';
	}

	char sss[105][105];
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", sss[i]);

	for (i = 0; i < n; i++)
	{
		if (c == 0)
		{
			for (j= 0; j < 105 && sss[i][j] != '\0'; j++)
				if (sss[i][j] >= 'A'&&sss[i][j] <= 'Z')
					sss[i][j] = sss[i][j] - 'A' + 'a';
		}
		if (match(s, sss[i]) == 1)
			printf("%s\n", sss[i]);
	}

	system("pause");
	return 0;
}
int match(char s1[105], char s2[105])
{
	int i = 0, j = 0;
	int flag = false;
	for (; i < 105 && s2[i] != '\0'; i++)
	{
		if (s2[i] == s1[0])
		{
			for (j = 0; s2[i+j] != '\0'&&s1[j] != '\0'; j++)
			{
				if (s2[i+j] != s1[j]) break;
			}
			if (s1[j] == '\0')
			{
				flag = true;
				break;
			}
		}
	}

	if (flag == true)return 1;
	else return 0;
}
