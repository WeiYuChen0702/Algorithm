#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	int color;
	struct node* left, * right, * parent;
};
typedef struct node node;
typedef struct node* nodeptr;

void leftrotation(nodeptr x);
void rightrotation(nodeptr y);
void insert(int n);
void fix(nodeptr current);
void inorder(nodeptr a);
int height(nodeptr a);
void deletenode(int key);
void deletefix(nodeptr current);
nodeptr successor(nodeptr current);

nodeptr tree = NULL;
nodeptr neel = (nodeptr)malloc(sizeof(node));

int main(void)
{
	int n, choice;
	nodeptr a;
	neel->left = neel->parent = neel->right = neel;
	neel->color = 1;
	tree = neel;

	while (1)
	{
		printf("1)Insert 2)Delete 3)Inorder 4)Height 5)Exit: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter a number:");
			scanf("%d", &n);

			insert(n);
			break;
		case 2:
			printf("Enter delete number:");
			scanf("%d", &n);
			deletenode(n);
		case 3:
			a = tree;
			inorder(a);
			break;
		case 4:
			a = tree;
			printf("Height:%d\n", height(a));
			break;

		case 5:
			system("pause");
			return 0;

		default:
			break;
		}
	}
	system("pause");
	return 0;
}

void leftrotation(nodeptr x)
{
	nodeptr y = x->right;         // ��y���Vx��rightchild, �̫�y�|?��x��parent

	x->right = y->left;        // �ϤG(c)��, ��y��left���bx��rightchild

	if (y->left != neel) {           // �ϤG(c)�k, �Ynode(j)��NIL�h����
		y->left->parent = x;        // �N���y��left��parent�令x
	}

	y->parent = x->parent;               // �ϤG(d)��, ��sy��parent

	if (x->parent == neel) {              // �ϤG(d)�k, �Y���x�Oroot, �����y?���s��root
		tree = y;
	}
	else if (x == x->parent->left) { // �Y���x�O��parent��left
		x->parent->left = y;        // ��s��y�]�O��parent��left
	}
	else {                                // �Y���x�O��parent��rightchild
		x->parent->right = y;       // ��s��y�]�O��parent��rightchild
	}
	y->left = x;                    // �ϤG(e)��, �̫�~�ק�y�Px
	x->parent = y;                       // �ϤG(e)�k
}

void rightrotation(nodeptr y)
{
	nodeptr x = y->left;           // ��x�]��y��left

	y->left = x->right;         // ��x��rightchild���y��left    
	if (x->right != neel)
	{           // �Yx��rightchild����NIL, �N��parent���Vy
		x->right->parent = y;
	}

	x->parent = y->parent;                // �Nx��parent���V���y��parent
	// �H�U�@��if-else�N�ק���y��parent��child
	if (y->parent == neel)
	{               // �Yy����Oroot, x�N�����s��root
		tree = x;
	}
	else if (y == y->parent->left)
	{  // �Y���y�O��parent��left, 
		y->parent->left = x;         // x�N������s��parent��left
	}
	else
	{                                 // �Y���y�O��parent��rightchild, 
		y->parent->right = x;        // x�N������s��parent��rightchild
	}
	x->right = y;                    // �Ny�]��x��rightchild
	y->parent = x;                        // �Nx�]��y��parent

}

void insert(int n)
{
	// �e�b���P InsertBST()��??�����ۦP, �ȶȻݭn�ק� NULL <-> NIL
	nodeptr y = neel;
	nodeptr x = tree;
	nodeptr newnode;

	newnode = (nodeptr)malloc(sizeof(node));
	newnode->num = n;

	while (x != neel)
	{     // ��root��l�Ʀ�neel, �o�̴N�i�H��neel�Ӱ��P�_
		y = x;
		if (newnode->num < x->num)
		{
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	newnode->parent = y;

	if (y == neel)
	{
		tree = newnode;
	}
	else if (newnode->num < y->num)
	{
		y->left = newnode;
	}
	else
	{
		y->right = newnode;
	}

	// �H�U�O��RBT��node���]�w, �Nchild pointer���VNIL, �¦�]������
	newnode->left = neel;
	newnode->right = neel;
	newnode->color = 0;             // ����i�H�bconstructor���w�]

	fix(newnode);      // ��i��X�{����P����node�۳s�����ΰ��ץ�

}

void fix(nodeptr current)
{
	nodeptr uncle;
	// case0: parent�O�¦�, �N���ζi�^��
	while (current->parent->color == 0)
	{   // �Yparent�O����Y�i�J�j��

		// �W�b���Gparent�Ograndparent��left child
		if (current->parent == current->parent->parent->left)
		{
			uncle = current->parent->parent->right;
			// case1: �Yuncle�O����
			if (uncle->color == 0)
			{
				current->parent->color = 1;
				uncle->color = 1;
				current->parent->parent->color = 0;              //grandparent�令����
				current = current->parent->parent;
			}
			// case2 & 3: uncle�O�¦�
			else
			{
				if (current == current->parent->right)
				{     // case2
					current = current->parent;
					leftrotation(current);
				}
				// case3
				current->parent->color = 1;                      //��parent���
				current->parent->parent->color = 0;              // grandparent���
				rightrotation(current->parent->parent);
			}
		}
		// �U�b���Gparent�Ograndparent��right child, �P�W�b�����
		else
		{
			uncle = current->parent->parent->left;
			// case1: �Yuncle�O����
			if (uncle->color == 0)
			{
				current->parent->color = 1;
				uncle->color = 1;
				current->parent->parent->color = 0;              //grandparent�令����
				current = current->parent->parent;
			}
			// case2 & 3: uncle�O�¦�
			else
			{
				if (current == current->parent->left)
				{     // case2
					current = current->parent;
					rightrotation(current);
				}
				// case3
				current->parent->color = 1;
				current->parent->parent->color = 0;
				leftrotation(current->parent->parent);
			}
		}
	}
	tree->color = 1;    // �T�Oroot�O�¦�
}

void inorder(nodeptr a)
{
	if (a == neel)
		return;
	inorder(a->left);
	printf("Key: %d\nColor: %d\n", a->num, a->color);
	inorder(a->right);
}

int height(nodeptr a)
{
	int left, right;

	if (a == neel)
		return 0;
	left = height(a->left);
	right = height(a->right);

	if (left > right)
		return left + 1;
	else
		return right + 1;
}

nodeptr search(int key)
{
	nodeptr x = tree;

	while (x != neel) {
		if (key < x->num)
		{
			x = x->left;
		}
		else if (key > x->num)
		{
			x = x->right;
		}
		else break;
	}

	return x;
}

void deletenode(int key)
{              // �n�R���㦳KEY��node

	nodeptr dnode = search(key);   // ���T�{RBT���O�_�s�b�㦳KEY��node
	if (dnode == neel)
	{
		printf("Not found!\n");
		return;
	}

	nodeptr y = NULL;     // �u���n�Q�R��������O���骺node
	nodeptr x = NULL;     // �n�Q�R����node��"child"

	if (dnode->left == neel || dnode->right == neel)
	{
		y = dnode;
	}
	else
	{
		y = successor(dnode);         // �Ny�]��delete_node��Successor
	}                                       // ?�L�o��if-else, y�վ㦨�ܦh�u���@��child


	if (y->left != neel)
	{              // �Nx�]��y��child, �i�঳?�ڸ��, �]���i��ONIL
		x = y->left;
	}
	else
	{
		x = y->right;
	}

	x->parent = y->parent;                 // �Y��x�ONIL�]�n��x��parent���V���Ī��O�����m
	// �]���bFixUp�ɻݭn�ǥ�x->parent�P�_x��left�άOrightchild

	if (y->parent == neel) {                // ���ۦA��n�Q����O���骺node��"parent"���V�s��child
		tree = x;                    // �Y�R�����O�����root, �N��x�ܦ��s��root 
	}
	else if (y == y->parent->left) {   // �Yy�쥻�O��parent��left child
		y->parent->left = x;          // �K��x�Ҧby��parent��left child, ���Ny
	}
	else {                                  // �Yy�쥻�O��parent��right child
		y->parent->right = x;         // �K��x�Ҧby��parent��right child, ���Ny
	}

	if (y != dnode) {                // ���case3
		dnode->num = y->num;         // �Yy�Odelete_node������, �̫�n�A�Ny�����
		//dnode->element = y->element; // ��^delete_node���O�����m, �ñNy���O�����m����
	}

	if (y->color == 1) {                   // �Y�R����node�O�¦�, �n�qx�i��ץ�, �H�ŦXRBT��?��?�h
		deletefix(x);
	}
}

void deletefix(nodeptr current)
{
	// Case0:(i)  current�O���⪺, �����⥦���
	//       (ii) current�Oroot, �����⥦���
	while (current != tree && current->color == 1) {
		// current�Oleft
		if (current == current->parent->left) {
			nodeptr uncle = current->parent->right;
			// Case1: �p�Guncle�O����
			if (uncle->color == 0) {
				uncle->color = 1;
				current->parent->color = 0;
				leftrotation(current->parent);
				uncle = current->parent->right;
			}
			// �i�J Case2�B3�B4: uncle�O�¦�
			// Case2: uncle����?child���O�¦�
			if (uncle->left->color == 1 && uncle->right->color == 1) {
				uncle->color = 0;
				current = current->parent;           // �Ycurrent��s��root, �Y���X?��
			}
			// Case3 & 4: current�u���䤤�@��child�O�¦�
			else {
				// case3: uncle��right child�O�ª�, left child�O����
				if (uncle->right->color == 1) {
					uncle->left->color = 1;
					uncle->color = 0;
					rightrotation(uncle);
					uncle = current->parent->right;
				}
				// �g�LCase3��, �@�w�|�ܦ�Case4
				// Case 4: uncle��right child �O���⪺, left child�O�¦�
				uncle->color = current->parent->color;
				current->parent->color = 1;
				uncle->right->color = 1;
				leftrotation(current->parent);
				current = tree;     // �Ncurrent���ʨ�root, �@�w���X?��
			}
		}
		// current�Oright
		else {
			nodeptr uncle = current->parent->left;
			// Case1: �p�Guncle�O����
			if (uncle->color == 0) {
				uncle->color = 1;
				current->parent->color = 0;
				rightrotation(current->parent);
				uncle = current->parent->left;
			}
			// �i�J Case2�B3�B4: uncle�O�¦�
			// Case2: uncle����?child���O�¦�
			if (uncle->left->color == 1 && uncle->right->color == 1) {
				uncle->color = 0;
				current = current->parent;             // �Ycurrent��s��root, �Y���X?��
			}
			// Case3 & 4: current�u���䤤�@?child�O�¦�
			else {
				// case3: uncle��left child�O�ª�, right child�O����
				if (uncle->left->color == 1) {
					uncle->right->color = 1;
					uncle->color = 0;
					leftrotation(uncle);
					uncle = current->parent->left;
				}
				// �g�LCase3��, �@�w�|�ܦ�Case4
				// Case 4: uncle��left child �O���⪺, rightt child�O�¦�
				uncle->color = current->parent->color;
				current->parent->color = 1;
				uncle->left->color = 1;
				rightrotation(current->parent);
				current = tree;     // �Ncurrent���ʨ�root, �@�w���X�j��
			}
		}
	}
	current->color = 1;
}

nodeptr successor(nodeptr current)
{
	if (current->right != neel)
	{
		current = current->right;

		while (current->left != neel)
		{
			current = current->left;
		}
		return current;
	}

	nodeptr parent = current->parent;

	while (parent != neel && current == parent->right)
	{
		current = parent;
		parent = parent->parent;
	}

	return parent;
}