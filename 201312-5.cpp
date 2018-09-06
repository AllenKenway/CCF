//https://blog.csdn.net/tigerisland45/article/details/55060929

#include <stdio.h>
#include <cstring>

const int N = 50;
const int DIRECTSIZE = 4;
struct _direct {
	int dr, dc;
} direct[DIRECTSIZE] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };

char grid[N][N + 1];
int visited[N][N];
int visited2[N][N];	

int R, C;

// �ж������Ƿ�Ϸ�����ƶ���
inline bool islegal(int r, int c)
{
	if (0 <= r && r < R && 0 <= c && c < C && !visited[r][c] && grid[r][c] != '#')
		return true;
	else
		return false;
}

// �����������
void dfs(int r, int c)
{
	int nextr, nextc;

	visited[r][c] = 1;

	int i;

	if (grid[r][c] == '+' || grid[r][c] == 'S' || grid[r][c] == 'T') {
		for (i = 0; i<DIRECTSIZE; i++) {
			nextr = r + direct[i].dr;
			nextc = c + direct[i].dc;

			if (islegal(nextr, nextc))
				dfs(nextr, nextc);
		}
	}
	else if (grid[r][c] == '-') {
		for (i = 2; i<DIRECTSIZE; i++) {
			nextr = r + direct[i].dr;
			nextc = c + direct[i].dc;

			if (islegal(nextr, nextc))
				dfs(nextr, nextc);
		}
	}
	else if (grid[r][c] == '|') {
		for (i = 0; i<2; i++) {
			nextr = r + direct[i].dr;
			nextc = c + direct[i].dc;

			if (islegal(nextr, nextc))
				dfs(nextr, nextc);
		}
	}
	else if (grid[r][c] == '.') {
		nextr = r + direct[1].dr;
		nextc = c + direct[1].dc;

		if (islegal(nextr, nextc))
			dfs(nextr, nextc);
	}
}

int main()
{
	int sr, sc, tr, tc;

	// ��������
	scanf("%d %d", &R, &C); getchar();
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			scanf("%c", &grid[i][j]);
		getchar();
	}


	// �ҵ������յ�����
	for (i = 0; i<R; i++)
		for (j = 0; j<C; j++)
			if (grid[i][j] == 'S')
				sr = i, sc = j;
			else if (grid[i][j] == 'T')
				tr = i, tc = j;


	// bfs����Ǵ�"S"����Ե���ĵ�
	int m, n;
	for (m = 0; m < R; m++)
		for (n = 0; n < C; n++)
			visited[m][n] = 0;
	dfs(sr, sc);

	for (m = 0; m < R; m++)
		for (n = 0; n < C; n++)
			visited2[m][n] = visited[m][n];
	
	int count;

	if (visited2[tr][tc]) {
		count = 0;

		// ͳ��"S"����Ե�������ɵ���"T"�������
		for (i = 0; i<R; i++)
			for (j = 0; j<C; j++) {
				if (visited2[i][j]) 
				{   // "S"����Ե����<i,j>��
					// bfs����Ǵ�<i,j>�㿪ʼ���Ե���ĵ㣬������ܵ���"T"�������
					for (m = 0; m < R; m++)
						for (n = 0; n < C; n++)
							visited[m][n] = 0;

					dfs(i, j);

					if (!visited[tr][tc])
						count++;

				}
			}

		// ������
		printf("%d",count);
	}
	else
		// ��"S"�㲻���Ե���"T"��
		printf("I'm stuck!");

	return 0;
}
