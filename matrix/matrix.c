/*
 * 矩阵的加减乘除还有转置
 * 矩阵的形式：row,col,value;使用三元表的形式定义一个矩阵，尤其是对于这个矩阵是
 * 稀疏矩阵,节省空间。
 *
 * 三元表：[0].row:代表矩阵总的行数
 *	   [0].col:代表矩阵总的列数
 *	   [0].value:代表矩阵的非零项的个数
 */

#include <stdio.h>

#define MAX 3
#define MAX_RANK 15
#define RANK 15

typedef struct{
	int row;
	int col;
	int value;
}matrix_t;

matrix_t matrix[MAX]={0};
//NxN的矩阵操作
matrix_t *create_nxn(int a[][MAX]);
matrix_t *add_nxn(matrix_t a[],matrix_t b[]);
matrix_t *sub_nxn(matrix_t a[],matrix_t b[]);
matrix_t *mul_nxn(matrix_t a[],matrix_t b[]);
matrix_t *div_nxn(matrix_t a[],matrix_t b[]);
void read_matrix(matrix_t src[],matrix_t dist[]);
void print_matrix(matrix_t a[]);
void search_num(int seanum);

/*
 * 对矩阵操作的operations函数
 */
struct matrix_operations_t{
	// 放在结构体里边的函数是一个指针，不用声明原型
	// 但是要表明这是一个函数指针
	matrix_t *(*create)(int a[MAX][MAX]);
	matrix_t *(*add)(matrix_t a[],matrix_t b[]);
	matrix_t *(*sub)(matrix_t a[],matrix_t b[]);
	matrix_t *(*mul)(matrix_t a[],matrix_t b[]);
	matrix_t *(*div)(matrix_t a[],matrix_t b[]);
	void (*read)(matrix_t src[],matrix_t dist[]);
	void (*print)(matrix_t a[]);
	void (*search)(int seanum);
};

int main(int argc,char *argv[])
{
	int i;

	int mat[4][MAX] = {{3,3,3},{0,0,1},{1,1,1},{2,2,1}};
	matrix_t *mat1=NULL;
	matrix_t matrix_1[4]={0};
	/*
	 * 初始化operation函数
	 */
	struct matrix_operations_t matrix_operations={
		.create = create_nxn,
		.add    = add_nxn,
		.sub    = sub_nxn,
		.mul    = mul_nxn,
		.div    = div_nxn,
		.read   = read_matrix,
		.print  = print_matrix,
		.search = search_num
	};
	mat1 = matrix_operations.create(mat);
	matrix_operations.print(mat1);
	matrix_operations.read(mat1,matrix_1);

	printf("\nmatrix_1:\n");
	matrix_operations.print(matrix_1);

	return 0;

}
/*
 * 将定义的二位矩阵形式转化为三元表的形式
 */
matrix_t *create_nxn(int a[][MAX])
{
	int i;
	matrix_t matrix_new[MAX+1];
	matrix_t *matrix_point = matrix_new;
	for(i=0;i<4;i++){
		matrix_new[i].row = a[i][0];
		matrix_new[i].col = a[i][1];
		matrix_new[i].value = a[i][2];
	}
	return matrix_point;
}
/*
 * 三元组的矩阵形式
 * 不支持广播
 */
matrix_t *add_nxn(matrix_t a[],matrix_t b[])
{
	int i,j,k=1;
	matrix_t retmat[MAX]={0};
	int matrix_one[RANK][RANK]={0};
	// 先检查两个矩阵是否阶一样
	// 如何两个矩阵的阶不相等，退出
	if(a[0].row==b[0].row && a[0].col==b[0].col){
		// 从两部分开始相加
		for(i=1;i<=a[0].value;i++){
			matrix_one[a[i].row][a[i].col] = a[i].value;

		}
		for(i=1;i<=b[0].value;i++){
			matrix_one[b[i].row][b[i].col] = matrix_one[b[i].row][b[i].col]+b[i].value;
		}
		// 开始转化为三元表的形式
		for(i=0;i<a[0].value;i++){
			for(j=0;j<a[0].value;j++){
				if(matrix_one[i][j] == 0){
					continue;
				}
				else{
					retmat[k].row = i;
					retmat[k].col = j;
					retmat[k].value = matrix_one[i][j];
					k++;
				}
			}
		}
		// 记录矩阵的阶和非零项个数
		retmat[0].row = a[0].row;
		retmat[0].col = a[0].col;
		retmat[0].value = k-1;
	}
	else{
		printf("rank(a) != rank(b),please enter suitable paremeter!!\n");
		return NULL;

	}
	// 转化成三元组的矩阵形式

	return matrix;
}


matrix_t *sub_nxn(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};
	return matrix;

}
matrix_t *mul_nxn(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};
	return matrix;

}

matrix_t *div_nxn(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};
	return matrix;

}


void read_matrix(matrix_t src[],matrix_t dist[])
{
	int i;
	for(i=0;i<4;i++){
		dist[i].row = src[i].row;
		dist[i].col = src[i].col;
		dist[i].value = src[i].value;
	}
}


void print_matrix(matrix_t a[])
{
	int i,j;
	for(i=0;i<4;i++){
		printf("%2d,%2d,%2d\n",a[i].row,a[i].col,a[i].value);

	}
}

void search_num(int num)
{
	return ;
}





