#include<stdio.h>
#include<stdlib.h>
#define N 6

int matrix_chain_order(int* p, int len, int m[N + 1][N + 1], int s[N + 1][N + 1]);
void print_optimal_parents(int s[N + 1][N + 1], int i, int j);

int main()
{
	int p[N + 1] = { 30,35,15,5,10,20,25 };
	int m[N + 1][N + 1] = { 0 };
	int s[N + 1][N + 1] = { 0 };
	int i, j;
	printf("Min: %d\n\n", matrix_chain_order(p, N + 1, m, s));
	printf("m value is:\n");
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
	printf("\n\ns value is:\n");
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
			printf("%d\t", s[i][j]);
		printf("\n");
	}
	printf("\n\nThe result is:\n");
	print_optimal_parents(s, 1, N);
	printf("\n");
	system("pause");
	return 0;
}

int matrix_chain_order(int* p, int len, int m[N + 1][N + 1], int s[N + 1][N + 1])
{
	int i, j, k, t, min;
	for (i = 0; i <= N; ++i)
		m[i][i] = 0;
	for (t = 2; t <= N; t++)
	{
		for (i = 1; i <= N - t + 1; i++)
		{
			j = i + t - 1;
			m[i][j] = 999999999;
			for (k = i; k <= j - 1; k++)
			{
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;
					s[i][j] = k;
					min = temp;
				}
			}
		}
	}

	return min;
}

void print_optimal_parents(int s[N + 1][N + 1], int i, int j)
{
	if (i == j)
		printf("A%d", i);

	else
	{
		printf("(");
		print_optimal_parents(s, i, s[i][j]);
		print_optimal_parents(s, s[i][j] + 1, j);
		printf(")");
	}
}