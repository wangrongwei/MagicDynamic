/*
 * 冒泡排序
 */
#include <stdio.h>

void bubble(int src[],int n);
int main(int argc,char* argv[])
{
	int i;
	int src[]={2,4,1,6,9,7,3,10,16,19};
	bubble(src,9);
	for(i=0;i<=9;i++)
		printf("%d  ",src[i]);
	return 0;

}
/*
 * 冒泡排序函数
 *	从小到大排序
 *	src[] 数组
 *	n src最后一个元素下标
 */
void bubble(int src[],int n)
{
	int i,j,temp;
	for(j=1;j<=n-1;j++)
		for(i=n;i>=j;i--){
			if(src[i-1] > src[i]){
				temp = src[i-1];
				src[i-1] = src[i];
				src[i] = temp;
			}
		}

}

