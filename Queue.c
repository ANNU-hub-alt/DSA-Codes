#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int qu[MAX], f = -1, r = -1;
void enqueue();
void dequeue();
void display();

int main()
{
	int in;
	while(1){
		printf("\n\n1)Insert Data \n2)Delete Data \n3)Display \n4)Exit");
		printf("\nEnter Choice:");
		scanf("%d", &in);

		switch(in){
			case 1: enqueue(); 
				break;
			case 2: dequeue(); 
				break;
			case 3: display();
				break;
			case 4: exit(1);
			
			default: printf("Invalid Choice");
		}
	}
	return 0;
}

void enqueue(){
	int item;
	if(r == MAX-1){
		printf("Overflow\n");
		return;
	}

	printf("Enter Data: ");
	scanf("%d", &item);


	if(r == -1){
		r = f = 0;
		qu[r] = item;
	}else {
		r = r+1;
		qu[r] = item;
	}
}
void dequeue(){
	int item;
	if(f == -1){
		printf("Underflow\n");
		return;
	}

	if(f == r){
		item = qu[f];
		f = r = -1;
	}else{
		item = qu[f];
		f++;
	}

	printf("Removed Data: %d", item);
}
void display(){
	int i;

	if(f == -1){
		printf("Queue is Empty\n");
		return;
	}

	for(i=f; i<=r; i++){
		printf("%d\n", qu[i]);
	}
}
