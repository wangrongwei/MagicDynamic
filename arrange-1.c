/*
 * 排列出n个布尔代数的排列
 */
#include <stdio.h>

#define MAX 100
void recursion(int i,int n);

int bool_list[MAX] = {1,1,1,1,1};

int main(int argc,char *argv[])
{
	recursion(0,4);
	return 0;
}

/*
 * 有待改进，不能取反第一个
 */
void recursion(int i,int n)
{
	int j,k;
	//int set[2]={0,1};
	//int bool_list[MAX] = {1,1,1,1,1};
	if(i==n){
		for(k=0;k<n;k++){
			printf("%d",bool_list[k]);
		}
		printf("\n");

	}
	else{
		for(j=i;j<n;j++,i++){
			bool_list[j] = !bool_list[j];
			recursion(i+1,n);
		}
	}
}





