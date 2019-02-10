#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty,b[100],x=0;
int signal(int s)
{
	return(++s);
}
int wait (int s)
{
	return (--s);
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("Enter the value\n");
	scanf("%d",&b[x]);
	x++;
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("Consumer consumed the item %d\n",b[x-1]);
	x--;
	mutex=signal(mutex);
}
void main()
{
	int choice,size;
	printf("Enter size of array:	");
	scanf("%d",&size);
	int b[size];
	empty=size;
	printf("1.PRODUCE\n2.CONSUME\n3.EXIT\n");
	do
	{
		printf("Enter your choice:	");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if((mutex==1) && (empty!=0))
					producer();
				else
					printf("Buffer is full \n");
			break;
			case 2:if((mutex==1) && (full!=0))
					consumer();
				else
					printf("Buffer is empty \n");
			break;
			case 3: exit(0);
			break;
		}
	}while(1);	
}
