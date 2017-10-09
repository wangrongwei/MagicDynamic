/*
 * 矩阵的加减乘除还有转置
 */
#include <stdio.h>

#define MAX 20
typedef struct{
	int row;
	int col;
	int value;
}matrix_t;

matrix_t matrix[MAX]={0};

void create_3x3();
matrix_t *add_3x3(matrix_t a[],matrix_t b[]);
matrix_t *sub_3x3(matrix_t a[],matrix_t b[]);
matrix_t *mul_3x3(matrix_t a[],matrix_t b[]);
matrix_t *div_3x3(matrix_t a[],matrix_t b[]);
void read_matrix(matrix_t src[],matrix_t dist[]);
void print_matrix(matrix_t a[]);
void search_num(int seanum);


struct matrix_operations_t{
	// 放在结构体里边的函数是一个指针，不用声明原型
	// 但是要表明这是一个函数指针
	void (*create)();
	matrix_t (*add)(matrix_t a[],matrix_t b[]);
	matrix_t (*sub)(matrix_t a[],matrix_t b[]);
	matrix_t (*mul)(matrix_t a[],matrix_t b[]);
	matrix_t (*div)(matrix_t a[],matrix_t b[]);
	void (*read)(matrix_t src[],matrix_t dist[]);
	void (*print)(matrix_t a[]);
	void (*search)(int seanum);
};

int main(int argc,char *argv[])
{
	int i;
	matrix_t matrix_1[3]={0};
	struct matrix_operations_t matrix_operations={
		.create = create_3x3,
		.add    = add_3x3,
		.sub    = sub_3x3,
		.mul    = mul_3x3,
		.div    = div_3x3,
		.read   = read_matrix,
		.print  = print_matrix,
		.search = search_num
	};
	matrix_operations.create();
	matrix_operations.print(matrix);
	matrix_operations.read(matrix,matrix_1);

	printf("\nmatrix_1:\n");
	matrix_operations.print(matrix_1);

	return 0;

}

void create_3x3()
{
	int i;
	for(i=0;i<3;i++){
		matrix[i].row = i;
		matrix[i].col = i;
		matrix[i].value = 1;
	}
	//return matrix;
}

matrix_t *add_3x3(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};

	return matrix;
}


matrix_t *sub_3x3(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};
	return matrix;

}
matrix_t *mul_3x3(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};
	return matrix;

}

matrix_t *div_3x3(matrix_t a[],matrix_t b[])
{
	//matrix_t matrix[MAX]={0};
	return matrix;

}


void read_matrix(matrix_t src[],matrix_t dist[])
{
	int i;
	for(i=0;i<3;i++){
		dist[i].row = src[i].row;
		dist[i].col = src[i].col;
		dist[i].value = src[i].value;
	}
}


void print_matrix(matrix_t a[])
{
	int i,j;
	for(i=0;i<3;i++){
		printf("%2d,%2d,%2d\n",a[i].row,a[i].col,a[i].value);

	}
}

void search_num(int num)
{
	return ;
}

