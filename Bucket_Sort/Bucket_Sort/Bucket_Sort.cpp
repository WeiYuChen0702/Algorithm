#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define n 10000//

using namespace std;
struct arraydouble
{
	double num;
	arraydouble* nextone;
};
void insert_sort(arraydouble* A);
void Bucket_sort(double* A, double* temp);

int main(void)
{
	clock_t start_time, end_time;
	double tatol_time;
	char tempD[10000];
	//srand(time(NULL));
	int past = -1, nextnum;
	double* temp = 0, * ans = 0;
	temp = (double*)malloc(sizeof(double) * n);
	ans = (double*)malloc(sizeof(double) * n);
	FILE* fptr;
	if (n == 100)
	{
		fptr = fopen("100.txt", "r");
	}
	else if (n == 1000)
	{
		fptr = fopen("1000.txt", "r");
	}
	else
	{
		fptr = fopen("10000.txt", "r");
	}
	for (int i = 0; !feof(fptr); i++)
	{
		fgets(tempD, 10000, fptr);
		sscanf(tempD, "%lf", &temp[i]);//轉成數字
	}
	start_time = clock();
	Bucket_sort(temp, ans);
	end_time = clock();
	tatol_time = (double)(end_time - start_time) / (double)CLOCKS_PER_SEC;
	printf("Logarithms:%f\n", tatol_time);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cout << ans[i] << "\t";
			continue;

		}
		if (i % 10 == 9)
		{
			cout << ans[i] << endl;
		}
		else
		{
			cout << ans[i] << "\t";
		}
	}


	system("pause");
	return 0;
}
void Bucket_sort(double* A, double* temp)
{
	arraydouble* tempA;
	tempA = (arraydouble*)malloc(sizeof(arraydouble) * 10);
	for (int i = 0; i < 10; i++)
	{
		tempA[i].nextone = NULL;
		tempA[i].num = -1;
	}
	for (int i = 0; i < n; i++)
	{
		int one = A[i] * 10;//乘10判斷是哪個BOX
		if (one == 10)
		{
			arraydouble* c = new arraydouble;
			c->num = A[i];
			c->nextone = tempA[9].nextone;
			tempA[9].nextone = c;
		}
		else
		{
			if (tempA[one].nextone == NULL)//當下是的第一個就開一個新的給
			{
				tempA[one].nextone = new arraydouble;
				tempA[one].nextone->num = A[i];
				tempA[one].nextone->nextone = NULL;
			}
			else
			{
				arraydouble* c = new arraydouble;//繼續接下去
				c->num = A[i];
				c->nextone = tempA[one].nextone;
				tempA[one].nextone = c;
			}
		}

	}
	int index = 0;
	/*for (int i = 0; i < 10; i++)
	{
		arraydouble *c;
		if (tempA[i].nextone == NULL)
		{
			continue;
		}
		c = tempA[i].nextone;
		for (int i = 0; c != NULL; i++)
		{
			temp[index] = c->num;
			c = c->nextone;
			index++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cout << temp[i] << "\t";
			continue;

		}
		if (i % 10 == 9)
		{
			cout << temp[i] << endl;
		}
		else
		{
			cout << temp[i] << "\t";
		}
	}*/
	cout << "===========================排序後================================" << endl;
	for (int i = 0; i < 10; i++)
	{
		insert_sort(tempA[i].nextone);
	}
	index = 0;
	for (int i = 0; i < 10; i++)
	{
		arraydouble* c;
		if (tempA[i].nextone == NULL)
		{
			continue;
		}
		c = tempA[i].nextone;
		for (int i = 0; c != NULL; i++)
		{
			temp[index] = c->num;
			c = c->nextone;
			index++;
		}
	}
}

void insert_sort(arraydouble* A)
{
	if (A == NULL || A->nextone == NULL)
	{
		return;
	}
	struct arraydouble* t1 = A->nextone;
	while (t1 != NULL)
	{
		double sec_data = t1->num;
		double found = 0;
		struct arraydouble* t2 = A;
		while (t2 != t1)
		{
			if (t2->num > t1->num && found == 0)
			{
				sec_data = t2->num;
				t2->num = t1->num;
				found = 1;
				t2 = t2->nextone;
			}
			else
			{
				if (found == 1)
				{
					double temp = sec_data;
					sec_data = t2->num;
					t2->num = temp;
				}
				t2 = t2->nextone;
			}
		}
		t2->num = sec_data;
		t1 = t1->nextone;
	}
}