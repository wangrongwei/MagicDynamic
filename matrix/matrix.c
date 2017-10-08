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

void create_2x2();
matrix_t *add_2x2(matrix_t a,matrix_t b);
matrix_t *sub_2x2(matrix_t a,matrix_t b);
matrix_t *mul_2x2(matrix_t a,matrix_t b);
matrix_t *div_2x2(matrix_t a,matrix_t b);

struct matrix_operations_t{
	void (*create)();
	matrix_t (*add)(matrix_t a,matrix_t b);
	matrix_t (*sub)(matrix_t a,matrix_t b);
	matrix_t (*mul)(matrix_t a,matrix_t b);
	matrix_t (*div)(matrix_t a,matrix_t b);

};

int main(int argc,char *argv[])
{
	int i;
	struct matrix_operations_t matrix_operations={
		.create = create_2x2,
		.add    = add_2x2,
		.sub    = sub_2x2,
		.mul    = mul_2x2,
		.div    = div_2x2
	};
	matrix_operations.create();
	return 0;

}

void create_2x2()
{
	int i;
	matrix_t matrix[MAX]={0};
	for(i=0;i<9;i++){
		matrix[i].row = i;
		matrix[i].col = i;
		matrix[i].value = 1;
	}
	//return matrix;
}

matrix_t *add_2x2(matrix_t a,matrix_t b)
{
	matrix_t matrix[MAX]={0};

	return matrix;
}


matrix_t *sub_2x2(matrix_t a,matrix_t b)
{
	matrix_t matrix[MAX]={0};
	return matrix;

}
matrix_t *mul_2x2(matrix_t a,matrix_t b)
{
	matrix_t matrix[MAX]={0};
	return matrix;

}

matrix_t *div_2x2(matrix_t a,matrix_t b)
{
	matrix_t matrix[MAX]={0};
	return matrix;

}





