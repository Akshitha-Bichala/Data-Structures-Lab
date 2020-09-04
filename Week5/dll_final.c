#include <stdio.h>
#include <stdlib.h>
struct node
{
	float data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL,*tail=NULL,*cur,*t1,*t2;

void dll_create()
{
	int n,i;
	printf("enter the number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter the current data:\n");
		scanf("%f",&(cur->data));
		cur->prev=NULL;
		cur->next=NULL;
		if(head == NULL)
		tail=head=cur;
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;	
		}
	}
}

void dll_insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the current data:\n");
	scanf("%f",&(cur->data));
	cur->prev=NULL;
	cur->next=head;
	head->prev=cur;
	head=cur;
}

void dll_insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the current data:\n");
	scanf("%f",&(cur->data));
	cur->next=NULL;
	cur->prev=tail;
	tail->next=cur;
	tail=cur;
}

void dll_insert_at_position()
{
	int c=1,pos;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the current data:\n");
	scanf("%f",&(cur->data));
	printf("Enter the position to perform insertion: \n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
	
}

void dll_insert_before()
{
	float value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the current data:\n");
	scanf("%f",&(cur->data));
	printf("Enter the value of node before to perform insertion: \n");
	scanf("%f",&value);
	t1=head;
	while(t1!=NULL && t1->data !=value)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
	
}

void dll_insert_after()
{
	float value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the current data:\n");
	scanf("%f",&(cur->data));
	printf("Enter the data of node after which node to perform insertion: \n");
	scanf("%f",&value);
	t1=head;
	while(t1!=NULL && t1->data !=value)
		t1=t1->next;
	cur->next=t1->next;
	t1->next->prev=cur;
	t1->next=cur;
	cur->prev=t1;
}

void dll_delete_at_begin()
{
	cur=head;
	head=head->next;
	head->prev=NULL;
	cur->next=NULL;
	printf("Deleted element is %f",cur->data);
	free(cur);
}

void dll_delete_at_end()
{
	cur=tail;
	tail=tail->prev;
	tail->next=NULL;
	cur->prev=NULL;
	printf("Deleted element is %f",cur->data);
	free(cur);
}

void dll_delete_at_pos()
{
	int c=1,pos;
	printf("enter the position to perform deletion\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deleted data is %f",t1->data);
	free(t1);
}

void dll_delete_before()
{
	float value;
	printf("enter the value of node before which we need to delete:\n ");
	scanf("%f",&value);
	t1=head;
	while(t1->next->data != value && t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deleted data is %f",t1->data);
	free(t1);
}

void dll_delete_after()
{
	float value;
	t1=head;
	printf("enter the data of node to perform delete after: \n");
	scanf("%f",&value);
	while(t1!=NULL && t1->data!=value)
		t1=t1->next;
	t2=t1->next;
	t1->next=t2->next;
	t2->next->prev=t1;
	printf("deleted element is %f",t2->data);
	free(t2);
}

void dll_display_forward()
{
	if(head == NULL)
	printf("dll is empty\n");
	else
	{
		cur=head;
		printf("elements of dll are \n");
		while(cur != NULL)
		{
			printf("%.2f<->",cur->data);
			cur=cur->next;
		}
	}
}

void dll_display_reverse()
{
	if(head == NULL)
	printf("dll is empty\n");
	else
	{
		cur=tail;
		printf("elements of dll are \n");
		while(cur != NULL)
		{
			printf("%.2f<->",cur->data);
			cur=cur->prev;
		}
	}
}

void dll_searching()
{
	float value,flag=0;
	printf("enter the value to be searched :\n");
	scanf("%f",&value);
	int c=1;
	t1 = head;
	while(t1 !=  NULL)
	{	
		if(t1 -> data == value)
		{
			flag = 1;
			break;
		}
		t1=t1-> next;
		c++;
	}
	if(flag == 1)
	printf("element present in list at %d pos\n",c);
	else
	printf("element not present in list \n");	
}

void dll_sort()
{
	struct node *p1,*p2,*last=NULL;
	int i,c,t;
	do
	{
		c=0;
		p1=head;
		while(p1 -> next !=last)
		{
			if(p1->data > p1->next->data)
			{
				t=p1->data;
				p1->data=p1->next->data;
				p1->next->data=t;
				c=1;	
			}
		p1=p1 -> next;
	}
	last=p1;
	}while(c);
}


int main()
{
	int ch;
	while(1)
	{
		printf("------------------------------------------------------------------------\n");
		printf("program for double linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before");	
		printf("\n6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
		printf("11- delete after node \n12-display in forward\n13-display in reverse\n14-searching\n15-sort\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:dll_create();
				break;
			case 2:dll_insert_at_begin();
				break;
			case 3:dll_insert_at_position();
				break;
			case 4:dll_insert_at_end();
				break;
			case 5:dll_insert_before();
				break;
			case 6:dll_insert_after();
				break;
			case 7:dll_delete_at_begin();
				break;
			case 8:dll_delete_at_end();
				break;
			case 9:dll_delete_at_pos();
				break;
			case 10:dll_delete_before();
				break;
			case 11:dll_delete_after();
				break;
			case 12:dll_display_forward();
				break;
			case 13:dll_display_reverse();
				break;
			case 14:dll_searching();
				break;
		    case 15:dll_sort();
				break;
			case 16:exit(0);
		}
	}
}

