/*
 * 多项式操作
 *
 */

#include <stdio.h>
#include <float.h>

#define MAX 15
typedef struct{
	float coef;
	int expon;
}poly_t;

poly_t newpoly[MAX];
void readpoly(float a[],int n[],int size);
void printpoly(int size);

int main(int argc,char *argv[])
{
	float a[3] = {1,2,3};
	int n[3] = {4,5,6};

	readpoly(a,n,3);
	printpoly(3);

	return 0;
}

void readpoly(float a[],int n[],int size)
{
	int i;
	//poly_t newpoly[MAX];
	if(size > MAX){
		printf("please enter suitable size\n");
		return;
	}
	for(i=0;i<size;i++){
		newpoly[i].coef = a[i];
		newpoly[i].expon = n[i];
	}
	//return newpoly;

}
/*
 * 打印多项式
 */
void printpoly(int size)
{
	int i;
	printf("An(x)=");
	for(i=0;i<size;i++){
		printf("%1fx^%d",newpoly[i].coef,newpoly[i].expon);
		if(i<size-1)
			printf("+");
	}

}





