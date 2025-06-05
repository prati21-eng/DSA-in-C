#include<stdio.h>
#include<stdlib.h>
struct node
{
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
		printf("The memory is not alloacated\n");
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
void createlinkedlist(struct node** last)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*last == NULL)
	{
		*last = tempnode;
		(*last)->next = tempnode;
	}
	else
	{
		tempnode->next = (*last)->next;
		(*last)->next = tempnode;
		*last = tempnode;

	}
}
	void displaylinkedlist(struct node* last)
	{
		if (last == NULL)
		{
			printf("The linked is not created\n");
		}
		else
		{
			struct node* travnode = last->next;
			do
			{
				printf("%d->", travnode->data);
				travnode = travnode->next;
			}while (travnode != last->next);
		}
	}
	void insertatfirst(struct node** last)
	{
		struct node* tempnode = NULL;
		tempnode = createnode();
		if (*last == NULL)
		{
			*last = tempnode;
			(*last)->next = tempnode;
		}
		else
		{
			tempnode->next = (*last)->next;
			(*last)->next = tempnode;

		}
	}
	void insertatlast(struct node** last)
	{
		createlinkedlist(last);
	}
	int countnode(struct node* last)
	{
		int count = 0;
		struct node* travnode = last->next;
		do
		{
			count++;
			travnode = travnode->next;
		} while (travnode != last->next);
		return count;
	}
	void insertatpos(struct node** last)
	{
		int pos;
		int n;
		printf("Enter the position there you want to insert the elements\n");
		scanf_s("%d", &pos);
		n = countnode(*last);
		if (pos == 1)
		{
			insertatfirst(last);
		}
		else if (pos == n + 1)
		{
			insertatlast(last);
		}
		else if (pos<1 || pos>n + 1)
		{
			printf("Enter valid position");
		}
		else
		{
			struct node* tempnode = NULL;
			tempnode = createnode();
			struct node* travnode = (*last)->next;
			for (int i = 1; i < pos - 1; i++)
			{
				travnode = travnode->next;

			}
			tempnode->next = travnode->next;
			travnode->next = tempnode;
		}
	}
	void deleteatfirst(struct node** last)
	{
		if (*last == NULL)
		{
			printf("There is no element to delete\n");
		}
		else if ((*last)->next == *last)
		{
			free(*last);
			*last = NULL;
		}
		else
		{
			struct node* tempnode = NULL;
			tempnode = (*last)->next;
			(*last)->next = tempnode->next;
			free(tempnode);
		}
	}
	void deleteatlast(struct node** last)
	{
		if(*last == NULL)
		{
			printf("The linked list is not created to delete element\n");
		}
		else if((*last)->next == *last)
		{
			free(*last);
			*last = NULL;

		}
		else
		{
			struct node* tempnode = NULL;
			struct node* travnode = (*last)->next;
			while (travnode->next != *last)
			{
				travnode = travnode->next;
			}
			tempnode = travnode->next;
			travnode->next = tempnode->next;
			free(tempnode);
			*last = travnode;
		}
		
	}
	void deleteatpos(struct node** last)
	{
		int pos;
		int n;
		printf("Enter the position there you want to delete element\n");
		scanf_s("%d", &pos);
		n = countnode(*last);
		if (pos == 1)
		{
			deleteatfirst(last);
		}
		else if (pos == n)
		{
			deleteatlast(last);
		}
		else if (pos<1 || pos>n)
		{
			printf("Enter the valid position to delete the element");
		}
		else
		{
			struct node* travnode = (*last)->next;
			struct node* tempnode = NULL;
			for (int i = 1; i < n - 1; i++)
			{
				travnode = travnode->next;
			}
			tempnode = travnode->next;
			travnode->next = tempnode->next;
			free(tempnode);
		}
	}

void main()
{
	int choice;
	struct node* last = NULL;
	
	do
	{
		printf("\n");
		printf("1.create linked lisst\n");
		printf("2.Display linked list\n");
		printf("3.Insert at first\n");
		printf("4.Insert at last\n");
		printf("5.Insert at position\n");
		printf("6.Delete at first\n");
		printf("7.Delete at last\n");
		printf("8.Delete at position\n");
		printf("0.Exit\n");
		printf("Enter yout choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:createlinkedlist(&last);
			break;
		case 2:displaylinkedlist(last);
			break;
		case 3:insertatfirst(&last);
			break;
		case 4:insertatlast(&last);
			break;
		case 5:insertatpos(&last);
			break;
		case 6:deleteatfirst(&last);
			break;
		case 7:deleteatlast(&last);
			break;
		case 8:deleteatpos(&last);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);

}