/*
 * 各种排序练习
 */
#include <stdio.h>
#define MAX 100

typedef struct element{
	int key;
}element;

element ele[MAX]={1,3,5,7,2,12,23,54,78,9,10};

void insertion_sort(element list[],int n);

int main(int argc,char *argv)
{
	int i;
	insertion_sort(ele,11);
	for(i=0;i<15;i++){
		printf("%3d",ele[i].key);
	}

	return 0;
}

/*
 * 插入排序
 */
void insertion_sort(element list[],int n)
{
	int i,j;
	element next;
	for(i=1;i<n;i++){
		next = list[i];
		for(j=i-1;j>=0;j--){
			if(next.key < list[j].key)
				list[j+1] = list[j];
			else{
				list[j+1] = next;
				break ;
			}
		}

	}
}

