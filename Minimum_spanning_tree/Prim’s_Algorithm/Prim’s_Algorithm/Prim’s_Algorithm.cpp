#include<stdio.h>
#include<stdlib.h>
int a, b, u, v, n, i, j, ne = 1, m = 0;
char qw, wq;
int visited[9] = { 0 }, min, mincost = 0;
int main(void)
{
	int cost[9][9] = { 0 };
	FILE* fp;
	fp = fopen("praice10.txt", "r");
	fscanf(fp, "%d", &m);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			fscanf(fp, "%d", &cost[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	visited[0] = 1;
	while (ne < 9)
	{
		for (i = 0, min = 999; i < 9; i++)
			for (j = 0; j < 9; j++)
				if (cost[i][j] < min)
					if (visited[i] != 0)
					{
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
		if (a == 0)
			qw = 'a';
		if (a == 1)
			qw = 'b';
		if (a == 2)
			qw = 'c';
		if (a == 3)
			qw = 'd';
		if (a == 4)
			qw = 'e';
		if (a == 5)
			qw = 'f';
		if (a == 6)
			qw = 'g';
		if (a == 7)
			qw = 'h';
		if (a == 8)
			qw = 'i';

		if (b == 0)
			wq = 'a';
		if (b == 1)
			wq = 'b';
		if (b == 2)
			wq = 'c';
		if (b == 3)
			wq = 'd';
		if (b == 4)
			wq = 'e';
		if (b == 5)
			wq = 'f';
		if (b == 6)
			wq = 'g';
		if (b == 7)
			wq = 'h';
		if (b == 8)
			wq = 'i';
		if (visited[u] == 0 || visited[v] == 0)
		{
			printf("%c<->%c¡G%d\n", qw, wq, min);
			ne++;
			mincost += min;
			visited[b] = 1;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	printf("Minimun=%d\n", mincost);
	system("pause");
	return 0;
}