#include<iostream>
#include<string>
using namespace std;
struct MATRIX
{
	int count;
	int dir;
};
void LCS(string a, string b);
void Show(MATRIX** a, int i, int j, string A);
int main(void)
{
	string A, B;
	int option;
	while (1)
	{
		cout << "1:輸入字串 -1:Exit:";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "字串一:";
			cin >> A;
			cout << "字串二:";
			cin >> B;
			LCS(A, B);
			cout << endl;
			cout << "------------------------------------------------" << endl;
			LCS(B, A);
			cout << endl;
			break;
		case -1:
			system("pause");
			return 0;
		default:
			break;
		}
	}

	system("pause");
}
void LCS(string a, string b)
{
	MATRIX** A = new MATRIX * [(strlen(a.c_str()) + 1)];
	for (int i = 0; i <= strlen(a.c_str()); i++)
	{
		A[i] = new MATRIX[strlen(b.c_str()) + 1];
	}
	for (int i = 0; i < strlen(a.c_str()) + 1; i++)
	{
		A[i][0].count = 0;
	}
	for (int i = 0; i < strlen(b.c_str()) + 1; i++)
	{
		A[0][i].count = 0;
	}
	for (int i = 1; i < strlen(a.c_str()) + 1; i++)
	{
		for (int j = 1; j < strlen(b.c_str()) + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				A[i][j].count = A[i - 1][j - 1].count + 1;
				A[i][j].dir = 0;//0=左上
			}
			else
			{
				if (A[i - 1][j].count >= A[i][j - 1].count)
				{
					A[i][j].dir = 1;//左邊
					A[i][j].count = A[i - 1][j].count;
				}
				else
				{
					A[i][j].dir = 2;//上面
					A[i][j].count = A[i][j - 1].count;
				}
			}
		}
	}

	cout << "Longest Common Subsequence (LCS):";
	Show(A, strlen(a.c_str()), strlen(b.c_str()), a);
}
void Show(MATRIX** a, int i, int j, string A)
{
	if (a[i][j].count == 0)
	{
		return;
	}
	else
	{
		if (a[i][j].dir == 0)
		{
			Show(a, i - 1, j - 1, A);
			cout << A[i - 1];
		}
		else if (a[i][j].dir == 2)
		{
			Show(a, i, j - 1, A);
		}
		else
		{
			Show(a, i - 1, j, A);
		}
	}
}