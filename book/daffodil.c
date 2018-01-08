/*
 * 打印出100 - 999 之间的水仙花数
 */

#include <stdio.h>

void daffodil();

int main(int argc,char *argv[])
{
	daffodil();

	return 0;

}


void daffodil()
{
	int val = 0;
	int num,i2,i1,i0;
	for(num=100;num<=999;num++){
		i0 = num % 10;
		i1 = num / 10 % 10;
		i2 = num / 100;
		if(num == (i2*i2*i2 + i1*i1*i1 + i0*i0*i0))
			printf("%3d ",num);
	}
}

