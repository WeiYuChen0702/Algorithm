#include<stdio.h>
#include<stdlib.h>

#define maxlong 20
struct my
{
	int l;
	int r;
	int sum;
};

my maxCrossingSum(int arr[], int l, int m, int h);
my maxSubArraySum(int arr[], int l, int h);

my max(my a, my b)
{
	return (a.sum > b.sum) ? a : b;
}
my max(my a, my b, my c)
{
	return max(max(a, b), c);
}
void main()
{
	int arr[maxlong] = { NULL };
	FILE* ftp;
	ftp = fopen("06.txt", "r");
	if (ftp == NULL)
	{
		printf("Open faile\n");
	}
	else
	{
		for (int i = 0; i < maxlong; i++)
		{
			fscanf(ftp, "%d", &arr[i]);
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	my answer = maxSubArraySum(arr, 0, maxlong);
	printf("%d:%dMaxnum:%d\n", answer.l, answer.r, answer.sum);
	system("pause");
}
my maxCrossingSum(int arr[], int l, int m, int h)
{
	int sum = 0;
	int left_sum = -9999;
	my num;
	for (int i = m; i >= l; i--)
	{
		sum = sum + arr[i];
		if (sum > left_sum)
		{
			num.l = i;
			left_sum = sum;
		}
	}
	sum = 0;
	int right_sum = -9999;
	for (int i = m + 1; i <= h; i++)
	{
		sum = sum + arr[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			num.r = i;
		}
	}
	num.sum = left_sum + right_sum;
	return num;
}
my maxSubArraySum(int arr[], int l, int h)
{
	if (l == h)
	{
		my n;
		n.sum = arr[l];
		return n;
	}
	int m = (l + h) / 2;
	return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}