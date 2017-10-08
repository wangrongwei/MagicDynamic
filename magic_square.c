/*
 * 魔方问题：使用coxeter的简单法则：
 * 当n=奇数，最开始令第一行中间的为1，然后依次往左上方排序，
 * 已经有数字的排在当前下方。
 */

#include <stdio.h>

#define MAX 15
void magic(int n);

int main(int argc,char *argv[])
{
	int num=0;
	printf("enter your magic square num:");
	//while(1)
	scanf("%d",&num);
	if(num < 1 || num >15){
		printf("please enter right magic num!!!\n");
		return 0;
	}
	else
		magic(num);

	return 0;
}
/*
 * 参数n:魔方的阶数
 */
void magic(int n)
{
	int i=0,j,row,col;
	int magic_t[MAX][MAX]={0};
	//这里的col <= n多余了
	for(col=n/2,row=0;col<=n;col--,row--){
		if(row==-1){
			row = n-1;
		}
		if(col==-1){
			col = n-1;
		}
		i++;
		if(i<=n*n){
			//检测是不是0，不是0需要重新计算放置位置
			if(magic_t[row][col] == 0)
				magic_t[row][col] = i;
			else{
				if((row+2)<=n-1 || (col+1)<=n-1){
					row = row + 2;
					col = col + 1;
				}
				else{
					if(row==n-1 || col==n-1){
						if(row==n-1)
							row = 0;
						if(col==n-1)
							col = 0;
					}
					row = row + 1;

				}

				magic_t[row][col] = i;
			}
		}
		else
			break;

	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",magic_t[i][j]);
		}
		printf("\n");
	}

}


