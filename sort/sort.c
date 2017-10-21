/*
 * 各种排序练习
 */
#include <stdio.h>
#define MAX 100
#define MOD
//#undef MOD

typedef struct element{
	int key;
}element;

element ele[MAX]={1,3,5,7,2,12,23,54,78,9,10};

void insertion_sort(element list[],int n);
void bininsertion_sort(element list[],int n);

int main(int argc,char *argv)
{
	int i;
	bininsertion_sort(ele,11);
	for(i=0;i<11;i++){
		printf("%3d",ele[i].key);
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
	int i,j;
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

			if( right == left || right == left + 1){
				break;
				//printf("2\n");
			}
			//printf("1\n");

		}while(1);
		for(j=i;j>mod;j--){
			list[j] = list[j-1];
		}
		list[mod].key = next.key;
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




