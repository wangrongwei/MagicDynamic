/*
 * 求圆的表面积
 */

#include <stdio.h>
#include <math.h>

const double pi = acos(-1.0);

int main(int argc,char *argv[])
{
	double area = 0;
	float r,h;
	//printf("pi = %f",pi);
	// area = 2*pi*r*r+2*pi*r*h
	printf("please input r and h:");
	// 输入时候必须使用空格分开
	scanf("%f %f",&r,&h);
	area = 2*pi*r*r+2*pi*r*h;
	printf("area = %.3f",area);

	return 0;
}



