#include<iostream>
using namespace std;


struct interval
{
	int start, finish, index;
};
void quicksort(interval* a, int head, int tail);
int mid(interval* a, int head, int tail);
void Recursive_Activities_Select(interval* a, int start, int total);
int main(void)
{
	int total;
	cout << "請輸入activities個數:";
	cin >> total;
	interval* temp = new interval[total];
	for (int i = 0; i < total; i++)
	{
		cout << "請輸入第" << i + 1 << "個\t Activities的開始時間:";
		cin >> temp[i].start;
		cout << "請輸入第" << i + 1 << "個\t Activities的結束時間:";
		cin >> temp[i].finish;
		if (temp[i].start > temp[i].finish)
		{
			while (temp[i].start > temp[i].finish)
			{
				cout << "請輸入第" << i + 1 << "個\t Activities的結束時間:";
				cin >> temp[i].finish;
			}
		}
		temp[i].index = i + 1;
	}
	quicksort(temp, 0, total - 1);
	for (int i = 0; i < total; i++)
	{
		cout << temp[i].index << '\t' << temp[i].start << '\t' << temp[i].finish << endl;
	}
	cout << "---------------------Recursive---------------------" << endl;
	Recursive_Activities_Select(temp, 0, total);
	cout << endl;
	cout << "---------------------For loop---------------------" << endl;
	int j = 0;
	cout << "A" << temp[j].index << '\t';
	for (int i = 1; i < total; i++)
	{
		if (temp[i].start >= temp[j].finish)
		{
			cout << "A" << temp[i].index << '\t';
			j = i;
		}
	}
	cout << endl;
	system("pause");
}
void Recursive_Activities_Select(interval* a, int start, int total)
{
	int m = start + 1;
	cout << "A" << a[m - 1].index << "\t";
	while (m <= total && a[m].start < a[start].finish)
	{
		m++;
	}
	if (m < total)
	{
		Recursive_Activities_Select(a, m, total);
	}
	else
	{

		return;
	}
}
void quicksort(interval* a, int head, int tail)
{
	if (head < tail)
	{
		int midone = mid(a, head, tail);
		quicksort(a, head, midone - 1);
		quicksort(a, midone + 1, tail);
	}
}
int mid(interval* a, int head, int tail)
{
	int A;
	A = head - 1;
	for (int j = head; j < tail; j++)
	{
		if (a[j].finish < a[tail].finish)
		{
			A++;
			interval temp = a[A];
			a[A] = a[j];
			a[j] = temp;
		}
	}
	A++;
	interval temp = a[A];
	a[A] = a[tail];
	a[tail] = temp;
	return A;
}
