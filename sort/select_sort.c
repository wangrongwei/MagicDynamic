/*
 * 选择排序:
 *	从未排序里寻找最小（或者最大）的放在已排序的数组里，然后
 * 又从未排序的数组里寻找最小或者最大的放在已排序的数组后边,直到排序完成
 */
#include<stdio.h>

#define NO_FIND -1

#define COMPARE(x,num) ((x>num)? -1:((x==num)? 0:1))
/****************************************************************
#define COMPARE(x,num) {\
	if(x>num)\
		return -1;\
	if(x==num)\
		return 0;\
	if(x<num)\
		return 1;\
}
****************************************************************/
void select_sort(int src[],int size);
int binary_search(int list[],int size,int num);
int binarysearch_recursion(int list[],int num,int left,int right);


int main(void)
{
	int retval;
	int k;
	int src[]={8,3,1,2,5,0,4,6,15,9};
	select_sort(src,10);

	for(k=0;k<10;k++){
		printf("%d,",src[k]);
	}
	retval = binary_search(src,10,16);
	if(retval <= 10)
		printf("\nthe 16 at src[%d]",retval);

	retval = binarysearch_recursion(src,8,0,9);
	printf("\n%d",retval);
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
				min = j; //找到一个更小的，交换数组序号
			}
		}//for循环结束以后，min就是未排序数组里最小的数的序号
		swp = src[min];
		src[min] = src[i];
		src[i] = swp;

	}

}

/*
 * 折半查找:不使用递归
 */
int binary_search(int list[],int size,int num)
{
	int left = 0,right = size-1;
	int middle = 0;
	while(1){
		// 指定中间位置
		middle = (left + right) / 2;
		if(num < list[middle])
			right = middle;
		else if(num == list[middle])
			return middle;
		else{
			left = middle;
		}
		// 当数组里没有这个num时，最终left + 1 = right
		if( left +1 == right){
			if(num != list[left] && num != list[right]){
				printf("\nnot search for num!!");
				return NO_FIND;
			}
		}

	}

}

/*
 * 折半查找:使用递归
 */
int binarysearch_recursion(int list[],int num,int left,int right)
{
	//int left = 0,right = size-1;
	int middle = (left + right) / 2;
	switch(COMPARE(list[middle],num)){
	case -1:
		return binarysearch_recursion(list,num,left,middle-1);
	case  0:
		return middle;
	case  1:
		return binarysearch_recursion(list,num,middle+1,right);

	}
	// 没找着,返回-1
	return -1;
}













