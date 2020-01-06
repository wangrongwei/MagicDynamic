/*
 * Horner规则：使用最少的乘法运算
 */

#include <stdio.h>

int horner_recursion(int An[],int x,int n);

int main(int *argc,char *argv[])
{
	int x = (int)*argv[1]-0x30;
	printf("x = %d\n",x);
	int An[]={1,2,3,4,5,6};
	int value=0;
	value = horner_recursion(An,x,5);
	printf("the result is %d\n",value);
	return 0;
}

int horner_recursion(int An[],int x,int n)
{
	int retval;
	static int i=-1;
	i++;
	if(i==n){
		return An[i];
	}
	retval = An[i] + horner_recursion(An,x,n) * x;
	return retval;

}


