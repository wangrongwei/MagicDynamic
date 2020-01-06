/*
 * 全排列问题
 */

#include <stdio.h>

#define MAX 100
#define swap(x,y,t) (t=x,x=y,y=t)

void full_arrangement(int list[],int size);
void recursion(int list[],int i,int size);

int main(void)
{
	int list[]={1,2,3,4};
	full_arrangement(list,3);
	return 0;
}

void full_arrangement(int list[],int size)
{
	recursion(list,0,size);
	//int *point = list;

}

void recursion(int list[],int i,int size)
{
	int j,k,temp;
	if(i == size){
		// 打印出排列数据
		for(k=0;k<=size;k++)
			printf("%d,",list[k]);
		printf("\n");
	}
	else{
		for(j=i;j<=size;j++){
			swap(list[i],list[j],temp);
			recursion(list,i+1,size);
			swap(list[i],list[j],temp);
		}
	}

}

