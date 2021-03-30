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
	nodeptr y = x->right;         // 把y指向x的rightchild, 最後y會?成x的parent

	x->right = y->left;        // 圖二(c)左, 把y的left托在x的rightchild

	if (y->left != neel) {           // 圖二(c)右, 若node(j)為NIL則忽略
		y->left->parent = x;        // 將原先y的left的parent改成x
	}

	y->parent = x->parent;               // 圖二(d)左, 更新y的parent

	if (x->parent == neel) {              // 圖二(d)右, 若原先x是root, 旋轉後y?成新的root
		tree = y;
	}
	else if (x == x->parent->left) { // 若原先x是其parent的left
		x->parent->left = y;        // 更新後y也是其parent的left
	}
	else {                                // 若原先x是其parent的rightchild
		x->parent->right = y;       // 更新後y也是其parent的rightchild
	}
	y->left = x;                    // 圖二(e)左, 最後才修改y與x
	x->parent = y;                       // 圖二(e)右
}

void rightrotation(nodeptr y)
{
	nodeptr x = y->left;           // 把x設成y的left

	y->left = x->right;         // 把x的rightchild放到y的left    
	if (x->right != neel)
	{           // 若x的rightchild不為NIL, 將其parent指向y
		x->right->parent = y;
	}

	x->parent = y->parent;                // 將x的parent指向原先y的parent
	// 以下一組if-else將修改原先y的parent之child
	if (y->parent == neel)
	{               // 若y原先是root, x將成為新的root
		tree = x;
	}
	else if (y == y->parent->left)
	{  // 若原先y是其parent之left, 
		y->parent->left = x;         // x就成為其新的parent之left
	}
	else
	{                                 // 若原先y是其parent之rightchild, 
		y->parent->right = x;        // x就成為其新的parent之rightchild
	}
	x->right = y;                    // 將y設為x之rightchild
	y->parent = x;                        // 將x設為y之parent

}

void insert(int n)
{
	// 前半部與 InsertBST()之??完全相同, 僅僅需要修改 NULL <-> NIL
	nodeptr y = neel;
	nodeptr x = tree;
	nodeptr newnode;

	newnode = (nodeptr)malloc(sizeof(node));
	newnode->num = n;

	while (x != neel)
	{     // 把root初始化成neel, 這裡就可以用neel來做判斷
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

	// 以下是對RBT之node的設定, 將child pointer指向NIL, 黑色設為紅色
	newnode->left = neel;
	newnode->right = neel;
	newnode->color = 0;             // 紅色可以在constructor中預設

	fix(newnode);      // 對可能出現紅色與紅色node相連之情形做修正

}

void fix(nodeptr current)
{
	nodeptr uncle;
	// case0: parent是黑色, 就不用進回圈
	while (current->parent->color == 0)
	{   // 若parent是紅色即進入迴圈

		// 上半部：parent是grandparent的left child
		if (current->parent == current->parent->parent->left)
		{
			uncle = current->parent->parent->right;
			// case1: 若uncle是紅色
			if (uncle->color == 0)
			{
				current->parent->color = 1;
				uncle->color = 1;
				current->parent->parent->color = 0;              //grandparent改成紅色
				current = current->parent->parent;
			}
			// case2 & 3: uncle是黑色
			else
			{
				if (current == current->parent->right)
				{     // case2
					current = current->parent;
					leftrotation(current);
				}
				// case3
				current->parent->color = 1;                      //把parent塗黑
				current->parent->parent->color = 0;              // grandparent塗紅
				rightrotation(current->parent->parent);
			}
		}
		// 下半部：parent是grandparent的right child, 與上半部對稱
		else
		{
			uncle = current->parent->parent->left;
			// case1: 若uncle是紅色
			if (uncle->color == 0)
			{
				current->parent->color = 1;
				uncle->color = 1;
				current->parent->parent->color = 0;              //grandparent改成紅色
				current = current->parent->parent;
			}
			// case2 & 3: uncle是黑色
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
	tree->color = 1;    // 確保root是黑色
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
{              // 要刪除具有KEY的node

	nodeptr dnode = search(key);   // 先確認RBT中是否存在具有KEY的node
	if (dnode == neel)
	{
		printf("Not found!\n");
		return;
	}

	nodeptr y = NULL;     // 真正要被刪除並釋放記憶體的node
	nodeptr x = NULL;     // 要被刪除的node的"child"

	if (dnode->left == neel || dnode->right == neel)
	{
		y = dnode;
	}
	else
	{
		y = successor(dnode);         // 將y設成delete_node的Successor
	}                                       // ?過這組if-else, y調整成至多只有一個child


	if (y->left != neel)
	{              // 將x設成y的child, 可能有?際資料, 也有可能是NIL
		x = y->left;
	}
	else
	{
		x = y->right;
	}

	x->parent = y->parent;                 // 即使x是NIL也要把x的parent指向有效的記憶體位置
	// 因為在FixUp時需要藉由x->parent判斷x為left或是rightchild

	if (y->parent == neel) {                // 接著再把要被釋放記憶體的node之"parent"指向新的child
		tree = x;                    // 若刪除的是原先的root, 就把x變成新的root 
	}
	else if (y == y->parent->left) {   // 若y原本是其parent之left child
		y->parent->left = x;          // 便把x皆在y的parent的left child, 取代y
	}
	else {                                  // 若y原本是其parent之right child
		y->parent->right = x;         // 便把x皆在y的parent的right child, 取代y
	}

	if (y != dnode) {                // 比對case3
		dnode->num = y->num;         // 若y是delete_node的替身, 最後要再將y的資料
		//dnode->element = y->element; // 放回delete_node的記憶體位置, 並將y的記憶體位置釋放
	}

	if (y->color == 1) {                   // 若刪除的node是黑色, 要從x進行修正, 以符合RBT的?色?則
		deletefix(x);
	}
}

void deletefix(nodeptr current)
{
	// Case0:(i)  current是紅色的, 直接把它塗黑
	//       (ii) current是root, 直接把它塗黑
	while (current != tree && current->color == 1) {
		// current是left
		if (current == current->parent->left) {
			nodeptr uncle = current->parent->right;
			// Case1: 如果uncle是紅色
			if (uncle->color == 0) {
				uncle->color = 1;
				current->parent->color = 0;
				leftrotation(current->parent);
				uncle = current->parent->right;
			}
			// 進入 Case2、3、4: uncle是黑色
			// Case2: uncle的兩?child都是黑色
			if (uncle->left->color == 1 && uncle->right->color == 1) {
				uncle->color = 0;
				current = current->parent;           // 若current更新到root, 即跳出?圈
			}
			// Case3 & 4: current只有其中一個child是黑色
			else {
				// case3: uncle的right child是黑的, left child是紅色
				if (uncle->right->color == 1) {
					uncle->left->color = 1;
					uncle->color = 0;
					rightrotation(uncle);
					uncle = current->parent->right;
				}
				// 經過Case3後, 一定會變成Case4
				// Case 4: uncle的right child 是紅色的, left child是黑色
				uncle->color = current->parent->color;
				current->parent->color = 1;
				uncle->right->color = 1;
				leftrotation(current->parent);
				current = tree;     // 將current移動到root, 一定跳出?圈
			}
		}
		// current是right
		else {
			nodeptr uncle = current->parent->left;
			// Case1: 如果uncle是紅色
			if (uncle->color == 0) {
				uncle->color = 1;
				current->parent->color = 0;
				rightrotation(current->parent);
				uncle = current->parent->left;
			}
			// 進入 Case2、3、4: uncle是黑色
			// Case2: uncle的兩?child都是黑色
			if (uncle->left->color == 1 && uncle->right->color == 1) {
				uncle->color = 0;
				current = current->parent;             // 若current更新到root, 即跳出?圈
			}
			// Case3 & 4: current只有其中一?child是黑色
			else {
				// case3: uncle的left child是黑的, right child是紅色
				if (uncle->left->color == 1) {
					uncle->right->color = 1;
					uncle->color = 0;
					leftrotation(uncle);
					uncle = current->parent->left;
				}
				// 經過Case3後, 一定會變成Case4
				// Case 4: uncle的left child 是紅色的, rightt child是黑色
				uncle->color = current->parent->color;
				current->parent->color = 1;
				uncle->left->color = 1;
				rightrotation(current->parent);
				current = tree;     // 將current移動到root, 一定跳出迴圈
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