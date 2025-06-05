#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
struct node* createnode()
{
	struct node* newnode = NULL;
	int data;
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
		newnode->prev = NULL;
		newnode->next = NULL;
		return newnode;
	}
}
void createlinkedlist(struct node** first, struct node** last)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*first == NULL && *last == NULL)
	{
		*last = tempnode;
		*first = tempnode;
		tempnode->next = tempnode;
		tempnode->prev = tempnode;
	}
	else
	{
		tempnode->prev = *last;
		tempnode->next = (*last)->next;
		*last = tempnode;
		(*first)->prev = tempnode;


	}

}

void displaylinkedlist(struct node* first,struct node* last)
{
	if (first == NULL && last == NULL)
	{
		printf("There is no linked list available to display\n");
	}
	else
	{
		struct node* travnode = first;

		do
		{
			printf("%d->", travnode->data);
			travnode = travnode->next;
		} while (travnode->next != first);
	}
}
void main()
{
	struct node* first=NULL;
	struct node* last=NULL;
	int choice;
	do {
		printf("\n1.Create linked list\n");
		printf("2.Display linked list\n");
		printf("0.Exit");
		printf("\n");
		printf("Enter your choice\n->");
			scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:createlinkedlist(&first, &last);
			break;
		case 2:displaylinkedlist(first,last);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);

}