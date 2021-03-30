#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

struct Edge
{
	int a, b, c;
};
int p[9];
int find(int x)
{
	if (x == p[x])
		return x;
	else
		return (p[x] = find(p[x]));
}
void unon(int x, int y)
{
	p[find(x)] = find(y);
}
int main()
{
	int matrix[9][9] = { 0 };
	int i = 0, j = 0, k = 0, line = 0, mincost = 0, n = 0;
	struct Edge e[20] = { 0 };
	struct Edge temp;//praice10.txt
	FILE* fp;
	fp = fopen("praice10.txt", "r");
	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &matrix[i][j]);
		}
	}
	for (i = 0; i < 9; i++)			//紀錄點和距離
	{
		for (j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0)
			{
				e[k].a = i;
				e[k].b = j;
				e[k].c = matrix[i][j];
				k++;
			}
		}
	}
	for (i = k; i < 20; i++)			//沒記到的距離無限大
	{
		e[i].c = 999;
	}
	for (i = 0; i < 9; i++)			//初始化連接線陣列
	{
		p[i] = i;
	}
	for (i = 0; i < k; i++)			//sort，由小到大
	{
		for (j = 0; j < k - i - 1; j++)
			if (e[j].c > e[j + 1].c)
			{
				temp = e[j + 1];
				e[j + 1] = e[j];
				e[j] = temp;
			}
	}

	char qw, wq;
	for (i = 0; line < 8; i++)
	{
		int f1 = find(e[i].a);
		int f2 = find(e[i].b);
		if (f1 == f2)
			continue;
		unon(e[i].a, e[i].b);
		line++;
		if (e[i].a == 0)
			qw = 'a';
		if (e[i].a == 1)
			qw = 'b';
		if (e[i].a == 2)
			qw = 'c';
		if (e[i].a == 3)
			qw = 'd';
		if (e[i].a == 4)
			qw = 'e';
		if (e[i].a == 5)
			qw = 'f';
		if (e[i].a == 6)
			qw = 'g';
		if (e[i].a == 7)
			qw = 'h';
		if (e[i].a == 8)
			qw = 'i';

		if (e[i].b == 0)
			wq = 'a';
		if (e[i].b == 1)
			wq = 'b';
		if (e[i].b == 2)
			wq = 'c';
		if (e[i].b == 3)
			wq = 'd';
		if (e[i].b == 4)
			wq = 'e';
		if (e[i].b == 5)
			wq = 'f';
		if (e[i].b == 6)
			wq = 'g';
		if (e[i].b == 7)
			wq = 'h';
		if (e[i].b == 8)
			wq = 'i';
		mincost += e[i].c;
		printf("%c<->%c：%d\n", qw, wq, e[i].c);
	}
	printf("Minimun=%d\n", mincost);
	system("pause");
	return 0;
}