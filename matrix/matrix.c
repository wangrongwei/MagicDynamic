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

struct{
	matrix_t *(create());
	matrix_t *(add(matrix_t a,matrix_t b));
	matrix_t *(sub(matrix_t a,matrix_t b));
	matrix_t *(mul(matrix_t a,matrix_t b));
	matrix_t *(div(matrix_t a,matrix_t b));

}matrix_operations_t;

int main(int argc,char *argv[])
{
	int i;
	struct matrix_operations_t matrix_operations{
		.create = creat,
		.add    = add,
		.sub    = sub,
		.mul    = mul,
		.div    = div,
	};
}




