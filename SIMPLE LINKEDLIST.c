#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//structure defination
struct node 
{
	int data;
	struct node*next; //self refrential structure 
	};

//function declaraction 
void createlist(struct node**);
void displaylist(struct node*);
void insertatbeg(struct node**);
void insertatend(struct node**);
void insertafterval(struct node**);
void delatbeg(struct node**);
void delatend(struct node**);
void delnode(struct node**);
void searchnode(struct node**);
void countnode(struct node*);
void insertatmid(struct node**);
			
//main function or body of code
int main()
{
	struct node*start= NULL;
	int ch;
	while(1)
	{
		printf("Simple Linked List \n");
		printf("\n1. Create List \n");
		printf("2. Display List \n");
		printf("3. Insert Node at Starting\n");
		printf("4. Insert Node at Ending\n");
		printf("5. Insert Node after Node in List\n");
		printf("6. Delete Node at Starting \n");
		printf("7. Delete Node at Ending  \n");
		printf("8. Delete Selected Node\n");
		printf("9. Search Node in List \n");
		printf("10. Insert Node at Middle\n");
		printf("11. Count Node\n");
		printf("12. EXIT\n");
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
			case 10 :	insertatmid(&start);
						break;
			case 11 :	countnode(start);
						break;			
			case 12 :	exit(1);
			default:	printf("Invalid Choice !! ");
		
		}
		
	}
	return 0;
}

void createlist(struct node**head)
{	int d;
	struct node*p,*q=*head;
	p =  (struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{	printf("Memory allocation failed !! ");
		return;
		}
	else
	{	printf("Enter value :- ");
		scanf("%d",&d);
		p->data=d;
		p->next=NULL;
		
		if(*head==NULL)
		{
			*head = p;
			return;
			}
		else
		{	while(q->next!=NULL)
			{	q=q->next;
				}
			q->next=p;
		}
	}
}
	
void displaylist(struct node*head)
{
	struct node*p=head;
	if(head==NULL)
	{	printf("Empty List !! ");
		return;
	}
	else
	{	while(p->next!=NULL)
		{
			printf("%d\n",p->data);
			p= p->next;
		}
		
		printf("%d\n",p->data);
	}
}


void insertatbeg(struct node**head)
{
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data :- ");
	scanf("%d",&p->data);
	p->next=NULL;
		
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

void insertatend(struct node**head)
{
	struct node*p,*q=*head;
		
	if(*head==NULL)
	{	
		insertatbeg(head);
		return;
	}
	else
	{	
		p=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data :- ");
		scanf("%d",&p->data);
		p->next=NULL;
		
		while(q->next!=NULL)
		{
			q=q->next;
		}
		
		q->next=p;
	}
		
}

void insertafterval(struct node**head)
{
	struct node*p,*r,*q=*head;
	int val;
	
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		p=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data For Node :- ");
		scanf("%d",&p->data);
		p->next=NULL;
	
		printf("Enter Data to match :- ");
		scanf("%d",&val);	
	
		while(q->data!=val)
		{
			q=q->next;
				
			if(q==NULL)
			{
			printf("Invalid input !!");
			return;
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


void delatbeg(struct node**head)
{
	struct node*p=*head;
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		*head=p->next;
		free(p);
	}	
} 


void delatend(struct node**head)
{
	struct node*p=*head,*q;
	if(*head==NULL)
	{	
		printf("Empty List\n");
		return;
	}
	else
	{
		while(p->next->next!=NULL)
		{	p=p->next;
			}
		q=p->next;
		p->next=NULL;
		free(q);
		}	
} 

void delnode(struct node**head)
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
		printf("Enter value for delate node after Entered Value Node ->  ");
		scanf("%d",&val);
		while(p->data!=val)
		{	p=p->next;
		
			if(p==NULL)  
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



void searchnode(struct node**head)
{
	struct node*p=*head;
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
		
			if(p==NULL)
			{
			printf("Invalid input!!\n Or\n Data is not matach!!");
			return;
			}
		}
		
	
		if(p->data==val)
		{
			printf("Data is present at %d  in Memory\n",p);
		}
	}
} 


void insertatmid(struct node**head)
{
	struct node*p,*r,*q=*head,*s=*head;
	int count=1,i;	
	if(*head==NULL)
	{	
		printf("List is Empty");
		return;
	}
	else
	{	
		while(q->next!=NULL)
		{
			q=q->next;
			count++;
		}
		
		if(count%2==NULL)
		{ 
			p=(struct node*)malloc(sizeof(struct node));
			printf("Enter Data :- ");
			scanf("%d",&p->data);
			p->next=NULL;
		
			count=count/2;
			
			for(i=1;i<count;i++)
			{
				s=s->next;	
			}
			r=s->next;
			s->next=p;
			p->next=r;
		}
		else
		{
			printf("The Number of Nodes are ODD so we already have a middle node... \n We can'nt Insert Node at Middle!!\n");
		}
	}
}

void countnode(struct node*head)
{
	struct node*p=head;
	int c = 1;
	if(head==NULL)
	{	printf("Empty List !! ");
		return;
	}
	else
	{	while(p->next!=NULL)
		{
			p=p->next;
			c++;
		}
		printf(" Total node in LinkedList is %d\n",c);
	}
}


