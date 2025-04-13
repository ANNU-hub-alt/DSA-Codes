#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[100];
int top=-1;

void push(char x)
{
	stack[++top]=x;	
}

char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}

int priocheck(char x)
{
	if(x=='(')
		return 0;
	else if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	else
		return 0;
}

void main()
{	char *p,x;
	char exp[100];
	printf("Please Enter Expression :-\n ");
	scanf("%s",&exp);
	p=exp;
	while(*p!=NULL)
	{
		if(isalnum(*p))	
		{	printf("%c",*p);
			}
		else if(*p=='(')
		{	push(*p);
			}
		else if(*p==')')
		{
			while((x=pop())!='(')
			{
				printf("%c",x);
			}
		}
		else
		{
			while(priocheck(stack[top])>=priocheck(*p))
			{  printf("%c", pop());
				}
            push(*p);
		}
        p++;
	}
	while (top != -1)
	{
        printf("%c", pop());
    }
}
