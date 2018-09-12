//https://blog.csdn.net/tigerisland45/article/details/54799557
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int salaryrange[] = { 3500, 3500 + 1500, 3500 + 4500, 3500 + 9000, 3500 + 35000, 3500 + 55000, 3500 + 80000 };
int taxrate[] = { 3, 10, 20, 25, 30, 35, 45 };

int main()
{
	int range[7];

	range[0] = salaryrange[0];
	for (int i = 1; i<7; i++) {
		range[i] = range[i - 1] + (salaryrange[i] - salaryrange[i - 1]) - (salaryrange[i] - salaryrange[i - 1]) * taxrate[i - 1] / 100;
	}

	int t, s;
	scanf("%d", &t);
	int i;
	for (i = 0; i < 7; i++)
		if (t <= range[i])
			break;

	if (i == 0)
		s = t;
	else
		s= salaryrange[i - 1] + (t - range[i - 1]) * 100 / (100 - taxrate[i - 1]);

	printf("%d", s);



	system("pause");
	return 0;
}