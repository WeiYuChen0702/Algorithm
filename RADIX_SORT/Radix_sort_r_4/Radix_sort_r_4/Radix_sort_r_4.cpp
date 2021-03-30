//針對4的
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100


int main()
{
	FILE* fp;
	char n[16][size] = {};
	int  a[16][size] = {};
	fp = fopen("rand100.txt", "r");
	clock_t start, end;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			fscanf(fp, "%c", &n[j][i]);
			if (n[j][i] == '\n')
			{
				j--;
			}
		}
	}




	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			a[j][i] = n[j][i] - '0';
		}
	}

	int temp[8][size] = {};
	int k = 7, p, q, s, t, p1, q1, s1, t1;

	for (int i = 0; i < size; i++)
	{
		p = 1;
		q = 1;
		s = 1;
		t = 1;
		p1 = 1, q1 = 1, s1 = 1, t1 = 1;
		for (int j = 15; j >= 0; j--)
		{
			if (j > 11)
			{
				temp[3][i] += a[j][i] * q;
				q = q * 10;
			}
			else if (j > 7 && j <= 11)
			{
				temp[2][i] += a[j][i] * p;
				p = p * 10;
			}
			else if (j > 3 && j <= 7)
			{
				temp[1][i] += a[j][i] * s;
				s = s * 10;
			}
			else if (j <= 3 && j >= 0)
			{
				temp[0][i] += a[j][i] * t;
				t = t * 10;
			}
		}
	}






	start = clock();
	int temp1[4] = {0};




	for (int i = 3; i >= 0; i--)
	{
		for (int r = 1; r < size; r++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (temp[i][j] > temp[i][j + 1] && i == 3)
				{
					temp1[k] = temp[i][j];//第3排
					temp1[k - 1] = temp[i - 1][j];//第2排
					temp1[k - 2] = temp[i - 2][j];//第1排
					temp1[k - 3] = temp[i - 3][j];//第0排 (頭)

					temp[i][j] = temp[i][j + 1];//第3排
					temp[i - 1][j] = temp[i - 1][j + 1];//第2排
					temp[i - 2][j] = temp[i - 2][j + 1];//第1排
					temp[i - 3][j] = temp[i - 3][j + 1];//第0排

					temp[i][j + 1] = temp1[k];//第3排
					temp[i - 1][j + 1] = temp1[k - 1];//第2排
					temp[i - 2][j + 1] = temp1[k - 2];//第1排
					temp[i - 3][j + 1] = temp1[k - 3];//第0排
				}
				if (temp[i][j] > temp[i][j + 1] && i == 2)
				{
					temp1[k] = temp[i + 1][j];//第3排
					temp1[k - 1] = temp[i][j];//第2排
					temp1[k - 2] = temp[i - 1][j];//第1排
					temp1[k - 3] = temp[i - 2][j];//第0排

					temp[i + 1][j] = temp[i + 1][j + 1];//第3排
					temp[i][j] = temp[i][j + 1];//第2排
					temp[i - 1][j] = temp[i - 1][j + 1];//第1排
					temp[i - 2][j] = temp[i - 2][j + 1];//第0排

					temp[i + 1][j + 1] = temp1[k];//第3排
					temp[i][j + 1] = temp1[k - 1];//第2排
					temp[i - 1][j + 1] = temp1[k - 2];//第1排
					temp[i - 2][j + 1] = temp1[k - 3];//第0排
				}
				if (temp[i][j] > temp[i][j + 1] && i == 1)
				{
					temp1[k] = temp[i + 2][j];//第3排
					temp1[k - 1] = temp[i + 1][j];//第2排
					temp1[k - 2] = temp[i][j];//第1排
					temp1[k - 3] = temp[i - 1][j];//第0排

					temp[i + 2][j] = temp[i + 2][j + 1];//第3排
					temp[i + 1][j] = temp[i + 1][j + 1];//第2排
					temp[i][j] = temp[i][j + 1];//第1排
					temp[i - 1][j] = temp[i - 1][j + 1];//第0排


					temp[i + 2][j + 1] = temp1[k];//第3排
					temp[i + 1][j + 1] = temp1[k - 1];//第2排
					temp[i][j + 1] = temp1[k - 2];//第1排
					temp[i - 1][j + 1] = temp1[k - 3];//第0排

				}
				if (temp[i][j] > temp[i][j + 1] && i == 0)
				{
					temp1[k] = temp[i + 3][j];//第3排
					temp1[k - 1] = temp[i + 2][j];//第2排
					temp1[k - 2] = temp[i + 1][j];//第1排
					temp1[k - 3] = temp[i][j];//第0排


					temp[i + 3][j] = temp[i + 3][j + 1];//第3排
					temp[i + 2][j] = temp[i + 2][j + 1];//第2排
					temp[i + 1][j] = temp[i + 1][j + 1];//第1排
					temp[i][j] = temp[i][j + 1];//第0排

					temp[i + 3][j + 1] = temp1[k];//第3排
					temp[i + 2][j + 1] = temp1[k - 1];//第2排
					temp[i + 1][j + 1] = temp1[k - 2];//第1排
					temp[i][j + 1] = temp1[k - 3];//第0排


				}
			}
		}
	}

	int y = 0;
	int y1 = 0, y2 = 0, y3 = 0;
	int temp2[4][size] = {};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp2[j][i] = temp[j][i];
		}
	}
	for (int i = 0; i < size; i++)
	{

		while (temp2[0][i] != 0)//頭
		{
			temp2[0][i] /= 10;
			y++;
		}

		for (int w = 0; w < 4 - y; w++)
		{
			printf("0");
		}
		if (y != 0)
			printf("%d", temp[0][i]);



		while (temp2[1][i] != 0)
		{
			temp2[1][i] /= 10;
			y1++;
		}

		for (int w = 0; w < 4 - y1; w++)
		{
			printf("0");
		}
		if (y1 != 0)
			printf("%d", temp[1][i]);


		while (temp2[2][i] != 0)
		{
			temp2[2][i] /= 10;
			y2++;
		}

		for (int w = 0; w < 4 - y2; w++)
		{
			printf("0");
		}
		if (y2 != 0)
			printf("%d", temp[2][i]);


		while (temp2[3][i] != 0)
		{
			temp2[3][i] /= 10;
			y3++;
		}

		for (int w = 0; w < 4 - y3; w++)
		{
			printf("0");
		}
		if (y3 != 0)
			printf("%d", temp[3][i]);


		printf("\n");
		y = 0;
		y1 = 0;
		y2 = 0;
		y3 = 0;
	}


	end = clock();
	printf("time:%f", (end - start) / (double)(CLOCKS_PER_SEC));




	system("pause");
	return 0;
}