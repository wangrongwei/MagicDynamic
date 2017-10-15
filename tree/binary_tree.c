/*
 * 包括二叉树的前序遍历、中序遍历和后序遍历
 * 还包括二叉树的复制和判断是否相等
 */
#include <stdio.h>

typedef struct tree_node *tree_point
typedef struct tree_node{
	tree_point left_node;
	tree_point right_node;
	int value;
}tree_node;


tree_point copy(tree_point origin);

int main(int argc,char *argv[])
{
	

}

/*
 * 从origin中复制整个tree，然后返回根节点
 * 复制方式与后序遍历顺序一样
 */
tree_point copy(tree_point origin)
{
	
}






