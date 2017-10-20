/*
 * 各种查找实现
 */
#include <stdio.h>
#define MAX 100

typedef struct element{
	int value;
}element;
element ele[MAX]={0,3,1,4,5,6,7,3,23,34,88,99,12};

int seqsearch(element ele[],int num,int n);

int main(int argc,char *argv[])
{
	int i = 0;
	i = seqsearch(ele,88,15);
	printf("i=%d",i);
	return 0;
}

int seqsearch(element ele[],int num,int n)
{
	int i;
	ele[n].value = num;
	for(i=0;ele[i].value!=num;i++);
	return ((i<n)?i:-1);
}





