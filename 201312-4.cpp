//https://blog.csdn.net/u013580497/article/details/48326879
#include<stdio.h>

int main() {
	long mod = 1000000007;
	int n, i, j;
	scanf("%d",&n);
	long long **status = new long long*[n + 1];
	for (i = -1; ++i<n + 1;) {
		status[i] = new long long[6];
		if (i == 0) {
			for (j = -1; ++j<6;) {
				status[0][j] = 0;
			}
		}
		else {
			status[i][0] = 1;
			status[i][1] = (status[i - 1][1] * 2 + status[i - 1][0]) % mod;
			status[i][2] = (status[i - 1][2] + status[i - 1][0]) % mod;
			status[i][3] = (status[i - 1][3] * 2 + status[i - 1][1]) % mod;
			status[i][4] = (status[i - 1][4] * 2 + status[i - 1][2] + status[i - 1][1]) % mod;
			status[i][5] = (status[i - 1][5] * 2 + status[i - 1][4] + status[i - 1][3]) % mod;
		}
	}
	printf("%d", status[n][5]);
	return 0;
}
