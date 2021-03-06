/*
 * 各种排序练习
 */
#include <stdio.h>
#define MAX 20
#define MOD
//#undef MOD

#define SWAP(i,j,k) (k=i,i=j,j=k)

typedef struct element{
	int key;
}element;

element ele[MAX] = {1,0,5,7,2,12,23,54,78,9,10};
element list[MAX] = {1,3,5,9,11,2,4,6,18,20};
element sorted[MAX] = {0};
void insertion_sort(element list[],int n);
void bininsertion_sort(element list[],int n);
void quicksort(element list[],int left,int right);
void merge(element list[],element sorted[],int i,int j,int n);


int main(int argc,char *argv)
{
	int i;
	//quicksort(ele,0,10);
	merge(list,sorted,0,5,9);
	for(i=0;i<10;i++){
		printf("%3d",sorted[i].key);
	}

	return 0;
}

#ifdef MOD
/*
 * 直接插入排序（从小到大）
 */
void insertion_sort(element list[],int n)
{
	int i,j;
	element next;
	for(i=1;i<n;i++){
		next = list[i];
		for(j=i-1;j>=0;j--){
			if(list[j].key > next.key)
				list[j+1] = list[j];
			else{
				list[j+1] = next;
				break;
			}
		}
		//存在一种可能----j==-1,但是上面的list[j+1] = next还没有执行
		list[j+1] = next;
	}
}
/*
 * 折半插入排序（从小到大）
 */
void bininsertion_sort(element list[],int n)
{
	int left,right,mod;
	int i,j,k=0;
	//left = 0;
	//right = 1;
	element next;
	for(i=1;i<n;i++){
		next = list[i];
		left = 0;
		right = i;
		do{
			mod = (left + right) / 2;
			if(next.key < list[mod].key){
				right = mod;
			}
			else{
				left = mod;
			}
			//printf("%d\n",k++);

		}while(!(right == left || right == left + 1));
		//if(mod == right)
		for(j=i;j>right;j--){
			list[j] = list[j-1];
		}
		list[right].key = next.key;
	}
}

/*
 * 快速排序（不稳定的排序）
 */
void quicksort(element list[],int left,int right)
{
	int i,j,pivot;
	int temp;
	//int left,right;
	//left = 0,right = n-1;
	//pivot = list[left].key;
	if(left < right){
		i = left;
		j = right + 1;
		pivot = list[left].key;
		do{
			//pivot = list[left];
			do{
				i++;
			}while(list[i].key < pivot);
			do{
				j--;
			}while(list[j].key > pivot);
			if(i < j)
				SWAP(list[i].key,list[j].key,temp);
			else
				SWAP(list[j].key,list[left].key,temp);
		}while(i < j);
		//SWAP();
		quicksort(list,left,j-1);
		quicksort(list,i+1,right);
	}
}

/*
 * 归并排序:sort为排好序的数组
 *	i:list里边第一个数组开始下标
 *	j:list里边第二个数组开始下标
 *	n:第二个数组结束的下标
 */
void merge(element list[],element sorted[],int i,int j,int n)
{
	int m = 0;
	int k = j; // 代表第一个数组的上限
	while(i < k && j <= n){
		if(list[i].key < list[j].key){
			sorted[m++].key = list[i++].key;
			//i++;
		}
		else{
			sorted[m++].key = list[j++].key;
			//j++;
		}
	}
	// 存在一种可能，有一个数组有余下的
	if(i < k){
		while(i < k){
			sorted[m++].key = list[i++].key;
		}
	}
	else{
		while(j <= n){
			sorted[m++].key = list[j++].key;
		}
	}

}



#else
/*
 * 直接插入排序（从大到小）
 */
void insertion_sort(element list[],int n)
{
	int i,j;
	element next;
	for(i=1;i<n;i++){
		next = list[i];
		for(j=i-1;j>=0;j--){
			//如果比next小，往后移一位
			if(list[j].key < next.key)
				list[j+1] = list[j];
			else{
				list[j+1] = next;
				break;
			}
		}
		//存在一种可能----j==-1,但是上面的list[j+1] = next还没有执行
		list[j+1] = next;
	}

}


#endif




