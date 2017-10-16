/*
 * 包括二叉树的前序遍历、中序遍历和后序遍历
 * 还包括二叉树的复制和判断是否相等
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node *tree_point;
typedef struct tree_node{
	tree_point left_node;
	tree_point right_node;
	int value;
}tree_node;

void create(tree_point *origin,int i);
void preorder(tree_point origin);
void inorder(tree_point origin);
void postorder(tree_point origin);

//tree_point copy(tree_point origin);

int main(int argc,char *argv[])
{
	tree_point origin = NULL;
	tree_point origin1 = NULL;
	tree_point origin2 = NULL;
	tree_point origin3 = NULL;
	tree_point origin4 = NULL;

	create(&origin,0);
	create(&origin1,3);
	create(&origin2,6);
	create(&origin3,9);
	create(&origin4,12);
	//开始组装
	origin->left_node->left_node = origin1;
	origin->left_node->right_node = origin4;
	origin1->left_node->left_node = origin2;
	origin1->left_node->right_node = origin3;

	inorder(origin);
	printf("\n");
	postorder(origin);

	return 0;

}
/*
 * 创建一个简单的树: A
 *		    B C
 */
void create(tree_point *origin,int i)
{
	//int i=0;
	*origin = (tree_point)malloc(sizeof(tree_point));
	(*origin)->left_node  = (tree_point)malloc(sizeof(tree_point));
	(*origin)->right_node = (tree_point)malloc(sizeof(tree_point));

	(*origin)->value = i;
	(*origin)->left_node->value  = i+1;
	(*origin)->right_node->value = i+2;

	(*origin)->left_node->left_node   = NULL;
	(*origin)->left_node->right_node  = NULL;
	(*origin)->right_node->left_node  = NULL;
	(*origin)->right_node->right_node = NULL;

}

/*
 * 前序遍历:打印出origin树遍历结果
 */
void preorder(tree_point origin)
{
	if(origin){
		printf("%d ",origin->value);
		preorder(origin->left_node);
		preorder(origin->right_node);
	}
	return;

}

/*
 * 中序遍历打印origin树的遍历结果
 */
void inorder(tree_point origin)
{
	if(origin){
		inorder(origin->left_node);
		printf("%d ",origin->value);
		inorder(origin->right_node);
	}
	return ;

}
/*
 * 后序遍历
 */
void postorder(tree_point origin)
{
	if(origin){
		postorder(origin->left_node);
		postorder(origin->right_node);
		printf("%d ",origin->value);
	}
	return ;
}
/*
 * 从origin中复制整个tree，然后返回根节点
 * 复制方式与后序遍历顺序一样
 */

//tree_point copy(tree_point origin)
//{
//	
//}






