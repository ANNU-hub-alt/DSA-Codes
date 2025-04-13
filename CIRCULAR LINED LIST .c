#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//structure defination
typedef struct node 
{
	int data;
	struct node*next; //self refrential structure 
	}node;

//function declaraction 
void createlist(node**);
void displaylist(node*);
void insertatbeg(node**);
void insertatend(node**);
void insertafterval(node**);
void delatbeg(node**);
void delatend(node**);
void delnode(node**);
void searchnode(node**);
void countnode(node*);
node* memoryallocate();
			
//main function or body of code
int main()
{
	node*start= NULL;
	int ch;
	printf("Operations on Circular Linked list\n");
	while(1)
	{
		printf("\n1. Create List \n");
		printf("2. Display List \n");
		printf("3. Insert Node at Starting\n");
		printf("4. Insert Node at Ending\n");
		printf("5. Insert Node after Node in List\n");
		printf("6. Delete Node at Starting \n");
		printf("7. Delete Node at Ending  \n");
		printf("8. Delete Selected Node\n");
		printf("9. Search Node in List \n");
		printf("10. Count Node\n");
		printf("11. EXIT\n");
		printf("ENTER YOUR CHOICE :- \n");
		printf("------->");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 :	createlist(&start);
						break;
		 	case 2 :	displaylist(start);
						break;
			case 3 :	insertatbeg(&start);
						break;
			case 4 :	insertatend(&start);
						break;
			case 5 :	insertafterval(&start);
						break;
			case 6 :	delatbeg(&start);
						break;
			case 7 :	delatend(&start);
						break;
			case 8 :	delnode(&start);
						break;
			case 9 :	searchnode(&start);
						break;
			case 10 :   countnode(start);
			case 11 :	exit(1);
			default:	printf("Invalid Choice !! ");
		
		}
		
	}
	return 0;
}

node* memoryallocate()
{	int val;
	node *a=(node*)malloc(sizeof(node));
	
	if(a==NULL)
	{	printf("Memory allocation failed !! ");
		exit(1);
		}	
	printf("Enter Value :- \n");
	scanf("%d",&val);
	a->data=val;
	a->next=NULL;
	return a;
}

void createlist(node**head)
{
	node*p,*q,*r=*head;
	q=memoryallocate();
	
	if(*head==NULL)
	{
		*head=q;
		q->next=*head;
		return;
	}
	
	else
	{	while(r->next!=*head)
		{	r=r->next;
			}
		r->next=q;
		q->next=*head;	
	}
}

void displaylist(node*head)
{
	node*p=head;
	if(head==NULL)
	{	printf("Empty List !! ");
		return;
	}
	else
	{	while(p->next!=head)
		{
			printf("%d\n",p->data);
			p=p->next;
		}
		
		printf("%d\n",p->data);
	}
}

void insertatbeg(node**head)
{
	node*p;
	p=memoryallocate();
		
	if(*head==NULL)
	{
		*head=p;
		return;
	}
	else
	{
		p->next=*head;
		*head=p;
	}		
}

void insertatend(node**head)
{
	node*p,*q=*head;
	p=memoryallocate();
	if(*head==NULL)
	{	
		*head=p;
		return;
	}
	else
	{	while(q->next!=*head)
		{
			q=q->next;
		}
		q->next=p;
		p->next=*head;
	}
}


void insertafterval(node**head)
{
	node*p,*r,*q=*head;
	int val;
	
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		p=memoryallocate();	
		printf("Enter Data to match :- ");
		scanf("%d",&val);	
	
		while(q->data!=val)
		{
			q=q->next;	
			if(q==NULL)
			{
				printf("Invalid data input !!");
			}
		}
		
		if(q->data==val)
		{
			r=q->next;
			q->next=p;
			p->next=r;
		}
	}		
}

void delatbeg(node**head)
{
	node*q=*head,*p=*head;
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		while(p->next!=*head)
		{
			p=p->next;	
		}
		*head=q->next;
		p->next=*head;
		free(q);
	}	
} 

void delatend(node**head)
{
	node*p=*head,*q;
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{	while(p->next->next!=*head)
		{	p=p->next;
			}
		q=p->next;
		p->next=*head;
		free(q);
	}	
} 


void delnode(node**head)
{
	struct node*p=*head,*q;
	int val;
	
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		printf("Enter value to delate node after Node ->  ");
		scanf("%d",&val);
		while(p->data!=val)
		{	p=p->next;
		
			if(p->next==*head) 
			{
				printf("Invalid input!! Or Data is not matach!!");
				return;
			}
		}
		if(p->data==val)
		{
			q=p->next;
			p->next=q->next;
			free(q);
		}
	}
} 



void searchnode(node**head)
{
	node*p=*head;
	int val;
	
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		printf("Enter value for Searching ->  ");
		scanf("%d",&val);
		while(p->data!=val)
		{	p=p->next;		
	
			if(p==*head)
			{
				printf("Invalid input!! Or Data is not matach!!");
				return;
			}
		}
		
		if(p->data==val)
		{
			printf("Data is present at %d  in Memory\n\n",p);
		}
	}
} 

void countnode(node*head)
{
	node*p=head;
	int count = 1;
	if(head==NULL)
	{	printf("Empty List !! ");
		return;
	}
	else
	{	while(p->next!=head)
		{
			p=p->next;
			count++;
		}
		
		printf(" Total node in LinkedList is %d\n",count);
	}
}
