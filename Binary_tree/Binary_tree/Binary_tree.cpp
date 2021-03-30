#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void prin(char a[], int cc)//印出
{
	int count = 0, chang = 2;
	if (cc > 0)
	{
		printf("%c\n", a[0]);
	}
	for (int i = 1; i < cc; i++)
	{
		printf("%c ", a[i]);
		count++;
		if (count == chang)
		{
			printf("\n");
			count = 0;
			chang *= 2;
		}
	}
	printf("\n");
}

void find(char a[], int cc)//找節點
{
	int index = 0;
	if (cc <= 0)
	{
		printf("沒東西可以找\n");
	}
	else
	{
		printf("輸入要找的位置");
		scanf("%d", &index);
		if (index < 0 || index >= cc)
		{
			printf("輸入錯誤，要在0~%d之間\n", cc - 1);
		}
		else
		{
			index++;
			if (index != 1)
			{
				printf("父節點為%c\n", a[(
					index) / 2]);
			}
			else
			{
				printf("沒有父節點\n");
			}
			if (index * 2 <= cc)
			{
				printf("左子節點為%c\n", a[index * 2]);
			}
			else
			{
				printf("沒有左子節點\n");
			}
			if (index * 2 + 1 <= cc)
			{
				printf("右子節點為%c\n", a[index * 2 + 1]);
			}
			else
			{
				printf("沒有右子節點\n");
			}
		}

	}
}

int main()
{
	char a[100] = { '0','A','B','C','D','E','F' };
	int c = 6, count = 6;
	double number = 0;
	int cho = 0;
	int temp = 100;
	//prin(a, c);

	while (1)
	{
		printf("輸入功能選項   1)父結點(左結點、右結點)   2)深度  -1)跳出");
		scanf("%d", &cho);

		if (cho == 1)
		{
			find(a, c);
		}
		else if (cho == 2)
		{
			for (int i = temp - 1; i >= 0; i--)
			{
				if (a[i] != '\0')
				{
					number = log(i) / log(2);
					break;
				}
			}
			printf("Depth:%d\n", (int)number);
		}

		else if (cho == -1)
		{
			break;
		}
		else
		{
			printf("輸入錯誤\n");
		}
	}

	system("pause");
	return 0;
}