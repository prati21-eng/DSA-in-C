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
		newnode->prev = NULL;
		newnode->data = data;
		newnode->next = NULL;
		return newnode;
	}
}
void createlinkedlist(struct node** headfirst, struct node** headlast)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*headfirst == NULL && *headlast == NULL)
	{
		*headfirst = tempnode;
		*headlast = tempnode;
	}
	else
	{
		(*headlast)->next = tempnode;
		tempnode->prev = *headlast;
		*headlast = tempnode;


	}

}
void displaylinkedlist(struct node* head)
{
	if (head == NULL)
	{
		printf("Linked list is not available to display\n");

	}
	else
	{
		while (head != NULL)
		{
			printf("%d->", head->data);
			head = head->next;
		}
	}
}
void insertatfirst(struct node** headfirst, struct node** headlast)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*headfirst == NULL && *headlast == NULL)
	{
		*headfirst = tempnode;
		*headlast = tempnode;

	}
	else
	{
		tempnode->next = *headfirst;
		(*headfirst)->prev = tempnode;
		*headfirst = tempnode;
	}
}
void insertatlast(struct node** headfirst, struct node** headlast)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*headlast == NULL && *headfirst == NULL)
	{
		*headlast = tempnode;
		*headfirst = tempnode;
	}
	else{
		tempnode->prev = *headlast;
		(*headlast)->next = tempnode;
		*headlast = tempnode;
	}
}
int countnode(struct node* head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}
void insertatpos(struct node** headfirst ,struct node** headlast)
{
	int pos;
	printf("Enter the position to enter the data:\n");
	scanf_s("%d", &pos);
	int n = countnode(*headfirst);
	if (pos == 1)
	{
		insertatfirst(headfirst, headlast);
	}
	else if (pos == n + 1)
	{
		insertatlast(headfirst, headlast);
	}
	else if (pos<1 || pos>n + 1)
	{
		printf("Enter valid position \n");
		insertatpos(headfirst, headlast);
	}
	else
	{
		struct node* tempnode = NULL;
		struct node*  travnode = *headfirst;
		tempnode = createnode();
		for (int i = 1; i < pos; i++)
		{
			travnode = travnode->next;
		}
		travnode->prev->next = tempnode;
		tempnode->prev = travnode->prev;
		tempnode->next = travnode;
	}
}
void deleteatfirst(struct node** headfirst, struct node** headlast)
{
	if (*headfirst == NULL && *headlast == NULL)
	{
		printf("The linklist is not available to delete element\n");
	}
	else if ((*headfirst)->next == NULL)
	{
		free(*headfirst);
		*headfirst = NULL;
		*headlast = NULL;
	}
	else
	{
		*headfirst = (*headfirst)->next;
		free((*headfirst)->prev);
	}
}
void deleteatlast(struct node** headfirst, struct node** headlast)
{
	if (*headfirst == NULL && *headlast == NULL)
	{
		printf("There is no link list availabale to delete an element.\n");
	}
	else if((*headfirst)->next == NULL)
	{
		free(*headlast);
			* headlast = NULL;
		*headfirst = NULL;


	}
	else
	{
		*headlast = (*headlast)->prev;
		free((*headlast)->next);
		(*headlast)->next = NULL;
	}
}
void deleteatpos(struct node** headfirst, struct node** headlast)
{
	int pos;
	printf("Enter the position to delete element\n");
	scanf_s("%d", &pos);
	int n = countnode(*headfirst);
	if (pos == 1)
	{
		deleteatfirst(headfirst, headlast);
	}
	else if (pos == n)
	{
		deleteatlast(headfirst, headlast);
	}
	else if (pos<1 || pos>n)
	{
		printf("Enter valid position to delete an elements\n");
	}
	else
	{
		struct node* travnode = *headfirst;
		for (int i = 1; i < pos; i++)
		{
			travnode = travnode->next;
		}
		travnode->next->prev = travnode->prev;
		travnode->prev->next = travnode->next;
		free(travnode);
	}

}

void main()
{
	int choice;
	struct node* first = NULL;
	struct node* last = NULL;
	
	do
	{
		printf("\n1.Create DoublyLinkList\n");
		printf("2.Display LinkedList\n");
		printf("3.Insert at first\n");
		printf("4.Insert at last\n");
		printf("5.Insert at position\n");
		printf("6.Delete at first\n");
		printf("7.Delete at last\n");
		printf("8.Delete at position\n");
		printf("0.Exit\n");
		printf("\n");
		printf("Plese enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:createlinkedlist(&first, &last);
			break;
		case 2:displaylinkedlist(first);
			break;
		case 3:insertatfirst(&first, &last);
			break;
		case 4:insertatlast(&first, &last);
			break;
		case 5:insertatpos(&first, &last);
			break;
		case 6:deleteatfirst(&first, &last);
			break;
		case 7:deleteatlast(&first, &last);
			break;
		case 8:deleteatpos(&first, &last);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);

}