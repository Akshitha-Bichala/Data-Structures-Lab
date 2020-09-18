//program for implementation of queue using array
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
int f=-1,r=-1,queue[maxsize];
int isfull()
{
	if(r==maxsize-1)
	return 1;
	else
	return 0;
}

int isempty()
{
	if(f==-1)
	return 1;
	else
	return 0;
}

void enqueue(int data)
{
	if(f==-1)
		f=0;
	queue[++r]=data;
}

int dequeue()
{
	
	return(queue[f++]);
	
}

void display()
{
	for(int i=f;i<=r;i++)
		printf("%d\t",queue[i]);
}

int main()
{
	int ch,x;
	while(1)
	{
		printf("--------------------------------------------\n");
		printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit");
		printf("Enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull())
					printf("queue overflow\n");
					else
					{
						printf("Enter the data to insert");
						scanf("%d",&x);
						enqueue(x);
					}
					break;
			case 2:if(isempty())
					printf("queue underflow");
					else if(f!=r)
					{
						printf("deleted element id %d \n",dequeue());
						if(f==r)
						f=r=-1;		
					}
					break;
			case 3:display();
					break;
			case 4:exit(0);
		}
	}
}
