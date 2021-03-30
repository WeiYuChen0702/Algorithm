#include<iostream>
#include<time.h>
#include<math.h>
#include<iomanip>
#include<math.h>
#define b 16
#define n 100
#define r 2

using namespace std;
int* changetoBinary(int k);
void Binarytodec(int* a);
void counting_sort(int** A, int Base, int start, int** ans);
void radix_sort(int** A, int Base, int** ans);
int main(void)
{
	int** A, ** temp;
	char tempD[10000];
	int temp2[100];
	char** store;
	FILE* fp = fopen("100.txt", "r");
	int tempone;
	A = (int**)malloc(sizeof(int*) * n);
	temp = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		/*fgets(tempD, 10000, fp);
		temp2[i] = atoi(tempD);
		printf("%d", A[i]);*/
		tempone = rand() % 65536;
		A[i] = changetoBinary(tempone);
		temp[i] = changetoBinary(tempone);
	}
	clock_t start_time, end_time;
	double tatol_time;
	double a;
	double ans = 1;
	start_time = clock();
	radix_sort(A, r, temp);
	end_time = clock();
	tatol_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++)
	{
		Binarytodec(A[i]);
		cout << ":";
		for (int k = b - 1; 0 <= k; k--)
		{
			cout << A[i][k];
		}
		cout << endl;
	}
	cout << "°õ¦æ®É¶¡:" << setprecision(30) << tatol_time << "mircosecond" << endl;
	system("pause");
	return 0;
}
int* changetoBinary(int k)
{
	int* temp = (int*)malloc(sizeof(int) * b);
	for (int i = 0; i < b; i++)
	{
		temp[i] = k % 2;
		k /= 2;
	}
	for (int i = 0; i < b; i++)
	{
		cout << temp[i];
	}
	cout << endl;
	return temp;
}
void counting_sort(int** A, int Base, int start, int** ans)
{
	int* countarray = (int*)malloc(sizeof(int) * pow(2, Base));
	int temp = 0;
	for (int i = 0; i < pow(2, Base); i++)
	{
		countarray[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		switch (Base)
		{
		case 2:
			temp = 0;
			for (int j = 0; j < Base; j++)
			{
				if (j == 0 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * 1;
				}
				if (j == 1 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * 2;
				}
			}
			countarray[temp]++;
			break;
		case 4:
			temp = 0;
			for (int j = 0; j < Base; j++)
			{
				if (j == 0 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 1 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 2 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 3 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
			}
			countarray[temp]++;
			break;
		case 8:
			temp = 0;
			for (int j = 0; j < Base; j++)
			{
				if (j == 0 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 1 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 2 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 3 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 4 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 5 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 6 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 7 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
			}
			countarray[temp]++;
			break;
		}
	}
	switch (Base)
	{
	case 2:
		for (int i = 0; i < pow(2, Base); i++)
		{
			if (i == 0)
			{
				continue;
			}
			else
			{
				countarray[i] += countarray[i - 1];
			}
		}
		break;
	case 4:
		for (int i = 0; i < pow(2, Base); i++)
		{
			if (i == 0)
			{
				continue;
			}
			else
			{
				countarray[i] += countarray[i - 1];
			}
		}
		break;
	case 8:
		for (int i = 0; i < pow(2, Base); i++)
		{
			if (i == 0)
			{
				continue;
			}
			else
			{
				countarray[i] += countarray[i - 1];
			}
		}
		break;
	}
	for (int i = n - 1; 0 <= i; i--)
	{
		switch (Base)
		{
		case 2:
			temp = 0;
			for (int j = 0; j < Base; j++)
			{
				if (j == 0 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * 1;
				}
				if (j == 1 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * 2;
				}
			}
			for (int k = 0; k < b; k++)
			{
				ans[countarray[temp] - 1][k] = A[i][k];
			}
			countarray[temp]--;
			break;
		case 4:
			temp = 0;
			for (int j = 0; j < Base; j++)
			{
				if (j == 0 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 1 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 2 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 3 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
			}
			for (int k = 0; k < b; k++)
			{
				ans[countarray[temp] - 1][k] = A[i][k];
			}
			countarray[temp]--;
			break;
		case 8:
			temp = 0;
			for (int j = 0; j < Base; j++)
			{
				if (j == 0 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 1 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 2 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 3 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 4 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 5 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 6 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
				if (j == 7 && A[i][start + j] == 1)
				{
					temp += A[i][start + j] * pow(2, j);
				}
			}
			for (int k = 0; k < b; k++)
			{
				ans[countarray[temp] - 1][k] = A[i][k];
			}
			countarray[temp]--;
			break;
		}
	}
}
void radix_sort(int** A, int Base, int** ans)
{
	switch (Base)
	{
	case 2:
		for (int i = 0; i < 16; i += 2)
		{
			if (i == 0 || i == 4 || i == 8 || i == 12)
			{
				counting_sort(A, Base, i, ans);
			}
			else
			{
				counting_sort(ans, Base, i, A);
			}
		}
		//ans=>A
		break;
	case 4:
		for (int i = 0; i < 16; i += 4)
		{
			if (i == 0 || i == 8)
			{
				counting_sort(A, Base, i, ans);
			}
			else
			{
				counting_sort(ans, Base, i, A);
			}
		}
		break;
	case 8:
		for (int i = 0; i < 16; i += 8)
		{
			if (i == 0)
			{
				counting_sort(A, Base, i, ans);
			}
			else
			{
				counting_sort(ans, Base, i, A);
			}
		}
		break;
	}
}
void Binarytodec(int* a)
{
	int temp = 0;
	for (int i = 0; i < b; i++)
	{
		if (a[i] == 1)
		{
			temp += pow(2, i);
		}
	}
	cout << temp;
}