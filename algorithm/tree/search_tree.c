/*
 * 对二叉查找树的操作(没有完成)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node *tree_point;
typedef struct tree_node{
	int value;
	tree_point left_node,right_node;
}tree_node;

void modify_treenode(tree_point origin,int value,char code);

int main(int argc,char *argc[])
{
	int i;
	tree_point root=NULL;

}

/*
 * 使用前序遍历的方法，创建一个tree骨架
 */
void create_tree(tree_point *root,int node_num)
{
	if(*root==NULL)
		*root = (tree_point)malloc(sizeof(tree_point));
	tree_point node[8]={NULL};
	for()
}

/*
 * 修改tree中的某位置的值
 */
void modify_treenode(tree_point origin,int value,char code)
{
	if(origin){
		
	}
	else
		printf("error! there is NULL\n");
	return ;
}

//tree_point tree_search(tree_point root,int value)
//{
//lib64	
//}






