/*
 * 计算pi值
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000000

int main(int argc,char *argv[])
{
	long count = 0,N = 0;
	float x,y,dist,pi;

	while(1){
		x = 2*(float)random() / RAND_MAX;
		y = 2*(float)random() / RAND_MAX;
		dist = sqrt((x-1)*(x-1)+(y-1)*(y-1));
		//printf("dist = %f\n",dist);
		N++;
		if(N > MAX){
			printf("Time out\n");
			break;
		}
		if(dist <= 1){
			count++;
		}
	}
	pi = (float)(count * 4) / MAX;
	printf("we cmput pi = %f\n",pi);

	return 0;
}




