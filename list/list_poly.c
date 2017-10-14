/*
 * 使用链表表示多项式
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list_poly *list_point;
typedef struct list_poly{
	float coef;
	int expon;
	list_point link;
}list_poly;

void add(list_point *front,list_point *rear,float coef,int expon);

//list_point front=NULL;
//list_point rear=NULL;

int main(int argc,char *argv[])
{
	list_point front=NULL;//(list_point)malloc(sizeof(list_poly));
	list_point rear=NULL;


	add(&front,&rear,5.1,5);
	//printf("front1 = %d\n",front);
	//printf("rear1 = %d\n",rear);
	add(&front,&rear,4.7,3);
	add(&front,&rear,2.5,2);
	add(&front,&rear,1.3,1);
	for(;front;front=front->link){
		printf("coef = %3.1f,expon = %3d",front->coef,front->expon);
		printf("\n");
	}

	return 0;

}


/*
 * 能成功实现在rear后面添加的
 */
void add(list_point *front,list_point *rear,float coef,int expon)
{
	list_point new = (list_point)malloc(sizeof(list_poly));
	new->coef = coef;
	new->expon = expon;
	new->link = NULL;
	if(*front){
		(*rear)->link = new;
		*rear = new;
		//printf("coef = %3.1f,expon = %3d",(*rear)->coef,(*rear)->expon);
		//printf("\n");

	}
	else{
		*front = new;
		*rear = new;
		//printf("front2 = %d\n",*front);

	}

}






