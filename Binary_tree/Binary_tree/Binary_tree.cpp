#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void prin(char a[], int cc)//�L�X
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

void find(char a[], int cc)//��`�I
{
	int index = 0;
	if (cc <= 0)
	{
		printf("�S�F��i�H��\n");
	}
	else
	{
		printf("��J�n�䪺��m");
		scanf("%d", &index);
		if (index < 0 || index >= cc)
		{
			printf("��J���~�A�n�b0~%d����\n", cc - 1);
		}
		else
		{
			index++;
			if (index != 1)
			{
				printf("���`�I��%c\n", a[(
					index) / 2]);
			}
			else
			{
				printf("�S�����`�I\n");
			}
			if (index * 2 <= cc)
			{
				printf("���l�`�I��%c\n", a[index * 2]);
			}
			else
			{
				printf("�S�����l�`�I\n");
			}
			if (index * 2 + 1 <= cc)
			{
				printf("�k�l�`�I��%c\n", a[index * 2 + 1]);
			}
			else
			{
				printf("�S���k�l�`�I\n");
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
		printf("��J�\��ﶵ   1)�����I(�����I�B�k���I)   2)�`��  -1)���X");
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
			printf("��J���~\n");
		}
	}

	system("pause");
	return 0;
}