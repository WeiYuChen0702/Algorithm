#include <stdio.h>
#include <stdlib.h>
#include<math.h>



typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} node;

typedef int(*comparer)(int, int);
typedef void(*callback)(node*);

node* create_node(int data)
{
	node* new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Out of memory!!! (create_node)\n");
		exit(1);
	}
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

node* insert_node(node* root, comparer compare, int data)
{

	if (root == NULL)
	{
		root = create_node(data);
	}
	else
	{
		int is_left = 0;
		int r = 0;
		node* cursor = root;
		node* prev = NULL;

		while (cursor != NULL)
		{
			r = compare(data, cursor->data);
			prev = cursor;
			if (r < 0)
			{
				is_left = 1;
				cursor = cursor->left;
			}
			else if (r > 0)
			{
				is_left = 0;
				cursor = cursor->right;
			}

		}
		if (is_left == 1)
			prev->left = create_node(data);
		else
			prev->right = create_node(data);

	}
	return root;
}

int compare(int left, int right)//比較大小
{
	if (left > right)
		return 1;
	if (left < right)
		return -1;
	return 0;
}

void display_tree(node* nd)
{
	if (nd == NULL)
		return;
	/* display node data */
	printf("\n%d", nd->data);
	if (nd->left != NULL)
		printf("(L:%d)", nd->left->data);
	if (nd->right != NULL)
		printf("(R:%d)", nd->right->data);
	printf("\n");

	display_tree(nd->left);
	display_tree(nd->right);
}

void dispose(node* root)//釋放記憶體
{
	if (root != NULL)
	{
		dispose(root->left);
		dispose(root->right);
		free(root);
	}
}

int maxDepth(node* nd)
{
	if (nd == NULL)
	{
		return (-1); // an empty tree  has height −1
	}
	else {
		// compute the depth of each subtree
		int leftDepth = maxDepth(nd->left);
		int rightDepth = maxDepth(nd->right);
		// use the larger one
		if (leftDepth > rightDepth)
			return (leftDepth + 1);
		else
			return (rightDepth + 1);
	}
}

void print_inorder(node* tree)
{
	if (tree)
	{
		print_inorder(tree->left);
		printf("%d\t", tree->data);
		print_inorder(tree->right);
	}
}

void print_postorder(node* tree)
{
	if (tree)
	{
		print_postorder(tree->left);
		print_postorder(tree->right);
		printf("%d\t", tree->data);
	}
}

int main()
{
	node* root = NULL;
	comparer int_comp = compare;
	int choice = 0, temp2 = 0;
	/* insert data into the tree */
	int a[100];
	int i;
	int k;
	int n;
	printf("--- C Binary Search Tree ---- \n\n");
	printf("請輸入總共有幾個:");
	scanf("%d", &n);
	printf("Insert: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);

		root = insert_node(root, int_comp, a[i]);
	}


	display_tree(root);
	printf(" \ninto the tree.\n\n");

	while (1)
	{
		printf("(1)新增節點 (2)樹的深度 (3)Inorder (4)Postorder (-1)離開：");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("輸入節點:");
			scanf("%d", &temp2);

			root = insert_node(root, int_comp, temp2);

			display_tree(root);
		}
		if (choice == 2)
		{
			k = maxDepth(root);
			printf("Depth:%d\n", k);
		}
		if (choice == 3)
		{
			printf("Inorder:\n");
			print_inorder(root);
		}
		if (choice == 4)
		{
			printf("Postorder:\n");
			print_postorder(root);
		}
		if (choice == -1)
			break;
	}
	system("pause");
	dispose(root);
	return 0;
}

