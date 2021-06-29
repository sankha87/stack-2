#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *link;
}*top = NULL;				//struct Node *top = NULL

void push(int num);
int pop();
void display();

void main()
{
	int choice, num;
	while (1)
	{
		printf("\n1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Exit \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a number to be inserted : ");
			scanf("%d", &num);
			push(num);							//	while (1)	- for checking Stack overflow condition
												//	push(num)	- for checking Stack overflow condition
						
			break;
		case 2:
			num = pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default:
			printf("Invalid Input");
		}
	}
}

void push(int num)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)							//	while (1)	- for checking Stack overflow condition
	{											//	push(num)	- for checking Stack overflow condition
		printf("Stack overflow \n");			//  when memory is finished, then temp will be NULL.
		return;
	}
	temp->data = num;
	temp->link = top;
	top = temp;
}

int pop()
{
	int num;
	if (top == NULL)
	{
		printf("Stack underflow \n");
		return -1;
	}
	struct Node *temp = top;
	num = top->data;
	top = top->link;
	free(temp);
	printf("Deleted : %d \n", num);
	return num;
}

void display()
{
	if (top == NULL)
	{
		printf("Stack underflow \n");
		return;
	}
	printf("\nStack is \n");
	struct Node *temp = top;
	while (temp != NULL)
	{
		printf("%d \n", temp->data);
		temp = temp->link;
	}

}
