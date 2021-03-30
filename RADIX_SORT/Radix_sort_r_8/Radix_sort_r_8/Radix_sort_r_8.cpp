//針對8的
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 10000


int main()
{
	FILE* fp;
	char n[16][size] = {};
	int  a[16][size] = {};
	fp = fopen("rand10000.txt", "r");
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
			a[j][i] = n[j][i] - '0';//轉int
		}
	}

	int temp[2][size] = {};
	int k = 1, p = 1, q = 1;

	for (int i = 0; i < size; i++)
	{
		p = 1;
		q = 1;
		for (int j = 15; j >= 0; j--)
		{
			if (j <= 7)//八個八個算
			{
				temp[0][i] += a[j][i] * q;
				q = q * 10;
			}
			else
			{
				temp[1][i] += a[j][i] * p;
				p = p * 10;
			}
		}
	}






	start = clock();
	int temp1[2] = {};


	temp1[0] = temp[0][0];
	temp1[1] = temp[1][0];

	for (int i = 1; i >= 0; i--)
	{
		for (int r = 1; r < size; r++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (temp[i][j] > temp[i][j + 1] && i == 1)
				{
					temp1[k] = temp[i][j];//第二排
					temp1[k - 1] = temp[i - 1][j];//第一排

					temp[i][j] = temp[i][j + 1];//第二排
					temp[i - 1][j] = temp[i - 1][j + 1];//第一排

					temp[i][j + 1] = temp1[k];//第二排
					temp[i - 1][j + 1] = temp1[k - 1];//第一排
				}
				if (temp[i][j] > temp[i][j + 1] && i == 0)
				{
					temp1[k] = temp[i + 1][j];//第二排
					temp1[k - 1] = temp[i][j];//第一排

					temp[i + 1][j] = temp[i + 1][j + 1];//第二排
					temp[i][j] = temp[i][j + 1];//第一排

					temp[i + 1][j + 1] = temp1[k];//第二排
					temp[i][j + 1] = temp1[k - 1];//第一排

				}
			}
		}
	}

	int y = 0;
	int y1 = 0;
	int temp2[2][size] = {};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp2[j][i] = temp[j][i];//算不足幾位
		}
	}
	for (int i = 0; i < size; i++)
	{

		while (temp2[0][i] != 0)
		{
			temp2[0][i] /= 10;
			y++;
		}

		for (int w = 0; w < 8 - y; w++)
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

		for (int w = 0; w < 8 - y1; w++)
		{
			printf("0");
		}
		if (y1 != 0)
			printf("%d", temp[1][i]);
		printf("\n");
		y = 0;
		y1 = 0;
	}


	end = clock();
	printf("time:%f", (end - start) / (double)(CLOCKS_PER_SEC));




	system("pause");
	return 0;
}