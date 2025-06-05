#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* next;
	int data;
};
struct node* createnode()
{
	int data;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		printf("Enter the data\n");
		scanf_s("%d", &data);
		newnode->data = data;
		newnode->next = NULL;
		return newnode;
	}


}
void push(struct node** head)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*head == NULL)
	{
		*head = tempnode;
	}
	else
	{
		struct node* travnode = *head;
		while (travnode->next!= NULL)
		{
			travnode = travnode->next;
		}
		travnode->next = tempnode;
	}

}
void display(struct node* head)
{
	if (head == NULL)
	{
		printf("Stack is not available to display\n");
	}
	else
	{
		struct node* travnode = head;
		while (travnode != NULL)
		{
			printf("%d->", travnode->data);
			travnode = travnode->next;
		}
	
	}
}
void peak(struct node* head)
{
	if (head == NULL)
	{
		printf("Stack is underflow\n");
	}
	else
	{
		struct node* travnode = head;
		while (travnode->next != NULL)
		{
			
			travnode = travnode->next;
		}
		printf("%d->", travnode->data);
	}
}
void pop(struct node** head)
{
	struct node* travnode = *head;
	if (*head == NULL)
	{
		printf("Stack is underflow\n");
	}
	else if (travnode->next == NULL)
	{
		printf("%d id poped\n",travnode->data);
		free(travnode);
		*head = NULL;
	}
	else
	{
		struct node* tempnode = NULL;
		while (travnode->next->next != NULL)
		{
			travnode = travnode->next;
		}
		printf("%d is poped\n", travnode->next->data);
		free(travnode->next);
		travnode->next = NULL;
	}
}
void main()
{
	int choice;
	struct node* top = NULL;
	do
	{
		printf("\n");
		printf("1.Create stack OR push\n");
		printf("2.display linked list\n");
		printf("3.Pop\n");
		printf("4.peak");
		printf("0.Exit\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:push(&top);
			break;
		case 2:display(top);
			break;
		case 3:pop(&top);
			break;
		case 4:peak(top);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);
}