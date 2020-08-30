#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node* head=NULL,*tail=NULL,*cur,*prev,*next;


void sll_create()
{
	int i,n;
	printf("enter the no.of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter current node data");
		scanf("%d",&cur -> data);
		cur -> link=NULL;
		if(head == NULL)
		{
			head=tail=cur;
		}
		else
		{
			tail -> link = cur;
			tail=cur;
		}
	}
}
void sll_insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter the cur data elements: \n");
	scanf("%d",&(cur-> data));
	printf("%d",(cur->data));
	cur->link=head;
	head=cur;
}

void sll_insert_at_position()
{
	int count =1,c,pos;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter the cur data elements: \n");
	scanf("%d",&(cur-> data));
	printf("Enter the position of the node to perform insertion: \n");
	scanf("%d",&pos);
	next = head;
	while(count < pos)
	{
		prev = next;
		next = next -> link;
		count++;
	}
	prev->link=cur;
	cur->link = next;
}

void sll_insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter the cur data elements: \n");
	scanf("%d",&(cur-> data));
	cur->link=NULL;
	tail->link=cur;
	tail=cur;
}

void sll_insert_before()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter the cur data elements: \n");
	scanf("%d",&(cur-> data));
	printf("Enter the node tp perform insertion: \n");
	scanf("%d",&value);
	next = head;
	while(next->data !=value && next!=NULL)
	{
		prev = next;
		next = next -> link;
	}
	prev->link=cur;
	cur->link = next;
}

void sll_insert_after()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter the cur data elements: \n");
	scanf("%d",&(cur-> data));
	printf("Enter the node to perform after insertion: \n");
	scanf("%d",&value);
	next = head;
	while(next->data !=value && next!=NULL)
		next = next -> link;
	cur->link = next-> link;
	next-> link=cur;
	
}

void sll_delete_at_begin()
{
	cur = head;
	head = cur -> link;
	cur -> link = NULL;
	printf("Deleted element is : %d\n",cur -> data);
	free(cur);
}

void sll_delete_at_end()
{
	cur = head;
	while(cur-> link != tail)
	{
		cur=cur->link;
	}
	cur -> link = NULL;	
	next = tail;
	printf("Deleted element is :%d \n",next -> data);
	free(next);
	tail=cur;
}

void sll_delete_at_pos()
{
	int pos,c=1;
	printf("enter the position for deletion \n");
	scanf("%d",&pos);
	next = head;
	while(c < pos)
	{
		prev = next;
		next= next -> link;
		c++;
	}
	prev -> link =next -> link;	
	printf("Deleted element is :%d \n",next -> data);
	next -> link = NULL;
	free(next);
}
void sll_delete_before()
{
	int value;
	printf("enter before which node we need to perform deletion");
	scanf("%d",&value);
	next=head;
	while(next -> link -> data != value)
	{
			prev =next;
			next = next -> link;
	}
	prev -> link =next-> link;
	next -> link = NULL;
	printf("deleted element is %d\n",next -> data);
	free(next);
}
void sll_delete_after_node()
{
	int value;
	printf("enter the value of node where deletion is performed\n");
	scanf("%d",&value);
	next = head;
	while(next ->data != value)
	{	
		prev = next;
		next=next -> link;
	}
	prev = next -> link;
	next -> link = prev -> link;
	printf("deleted data is %d\n",prev -> data);
	prev -> link = NULL;
	free(prev);
}
void sll_display()
{
	if (head==NULL)
	printf("list is empty \n");
	else
	{
		next = head;
		while(next != NULL)
		{
			printf("%d->",next->data);
			next = next -> link;
		}
	}
}
void sll_reverse_recursion(struct node * head)
{
	if(head != NULL)
	{
		sll_reverse_recursion(head -> link);
		printf("%d->",head ->data);
	}
}
void sll_search_element()
{
	int value,flag = 0,count=0;
	printf("enter the value to be searched :\n");
	scanf("%d",&value);
	next = head;
	while(next !=  NULL)
	{	
		if(next -> data == value)
		{
			flag = 1;
			break;
		}
		next=next -> link;
		count ++;
	}
	if(flag == 1)
	printf("element present in list at %d pos\n",count);
	else
	printf("element not present in list \n");
	
}
void sll_bubble_sort_ease()
{
	struct node *p1,*last=NULL;
	int i,c,t;
	do
	{
	c=0;
	p1=head;
	while(p1 -> link !=last)
	{
		if(p1->data > p1->link->data)
		{
			t=p1->data;
			p1->data=p1->link->data;
			p1->link->data=t;	
		}
		p1=p1 -> link;
		
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
		printf("program for single linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at pos\n4-insert at end\n5-insert before");	
		printf("\n6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
		printf("11- delete after\n12-traversal or display\n13-display in reverse\n14-search\n15-sort\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:sll_create();
				break;
			case 2:sll_insert_at_begin();
				break;
			case 3:sll_insert_at_position();
				break;
			case 4:sll_insert_at_end();
				break;
			case 5:sll_insert_before();
				break;
			case 6:sll_insert_after();
				break;
			case 7:sll_delete_at_begin();
				break;
			case 8:sll_delete_at_end();
				break;
			case 9:sll_delete_at_pos();
				break;
			case 10:sll_delete_before();
				break;
			case 11:sll_delete_after_node();
				break;
			case 12:sll_display();
				break;
			case 13:sll_reverse_recursion(head);
				break;
			case 14:sll_search_element();
				break;
			case 15:sll_bubble_sort_ease();
				break;
			case 17:exit(0);
		}
	}
}
