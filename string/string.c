/*
 * KMP算法例子
 */

#include <stdio.h>
#include <string.h>

#define MAX 100
//char string[MAX]="abcadaaaaa";
//char pat[MAX] = "aaaab";
int failure[MAX];

void fail(char pat[]);
void fail_func(char pat[]);
int match(char str[],char pat[]);


int main(int argc,char *argv[])
{
	int i;

	fail_func(argv[1]);
	for(i=0;i<strlen(argv[1]);i++){
		printf("%d",failure[i]);
	}
	printf("\n");
	printf("pos=%d",match(argv[2],argv[1]));
	return 0;

}
/*
 * 失配函数产生(书上的)
 */
void fail(char pat[])
{
	int i,j;
	int n = strlen(pat);
	failure[0] = -1;
	for(j=1;j<n;j++){
		i = failure[j-1];
		while((pat[j] != pat[i+1]) && (i>=0))
			i = failure[i];
		if(pat[j] == pat[i+1])
			failure[j] = i+1;
		else
			failure[j] = -1;
	}
}
/*
 * KMP算法的失配函数(自定义的)
 */
void fail_func(char pat[])
{
	int i,j,len;
	failure[0] = -1;
	len = strlen(pat);
	for(i=1;i<len;i++){
		// 如何已经算出的失配函数是-1 0 1 2,x,y
		// 那么x=3还是0，取决于下面是否相等，相等则为3.
		if(pat[i]==pat[failure[i-1] + 1]){
			failure[i] = failure[i-1] + 1;
		}
		else{
			if(pat[i]==pat[0])
				failure[i] = 0;
			else
				failure[i] = -1;
		}
	}

}

int match(char str[],char pat[])
{
	int i=0,j=0;
	int lens = strlen(str);
	int lenp = strlen(pat);
	while(i<lens){
		if(str[i] == pat[j]){
			i++;
			j++;
			if(j==lenp)
				break;
		}
		else{
			if(j==0)
				i++;
			else
				j = failure[j-1]+1;
		}
	}
	return (j==lenp)?(i-lenp):-1;
}





