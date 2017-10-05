/*
 * 选择排序:
 *	从未排序里寻找最小（或者最大）的放在已排序的数组里，然后
 * 又从未排序的数组里寻找最小或者最大的放在已排序的数组后边,直到排序完成
 */
#include<stdio.h>


void select_sort(int src[],int size);

int main(void)
{
	int k;
	int src[]={8,3,1,2,5,0,4,6,15,9};
	select_sort(src,10);

	for(k=0;k<10;k++){
		printf("%d,",src[k]);
	}
}
/*
 * 从小到大排序
 */
void select_sort(int src[],int size)
{
	int i,j;
	int swp;
	int min=0;
	for(i=0;i<size-1;i++){
		min = i;//先假定未排序数组里第一个数最小
		for(j=i+1;j<size;j++){
			if(src[j] < src[min]){
				//swp = src[j];
				//src[j] = src[i];
				min = j; //找到一个更小的，交换数组序号
			}
		}//for循环结束以后，min就是未排序数组里最小的数的序号
		swp = src[min];
		src[min] = src[i];
		src[i] = swp;

	}

}




