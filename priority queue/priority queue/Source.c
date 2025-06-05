//priority queue.

#include<stdio.h>
#include<stdlib.h>
struct element
{
	int data;
	int priority;
};
struct priorityqueue
{
	struct element** arr;
	int cap;
	int rear;
};
struct priorityqueue* createqueue()
{
	int cap;
	struct priorityqueue* tempqueue = NULL;
	tempqueue = (struct priorityqueue*)malloc(sizeof(struct priorityqueue));
	printf("Please enter the capacity of the queue\n");
	scanf_s("%d", &cap);
	tempqueue->cap = cap;
	tempqueue->arr = (struct element**)malloc((tempqueue->cap) * sizeof(struct element*));
	tempqueue->rear = -1;
	return tempqueue;
}
int isfull(struct priorityqueue* queue)
{
	return (queue->rear) == (queue->cap) - 1;
}
int isempty(struct priorityqueue* queue)
{
	return (queue->rear) == -1;
}
void enqueue(struct priorityqueue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}
	
	else if (isfull(queue))
	{
		printf("The queue is full\n");
		printf("\n");

	}
	else
	{
		int data;
		int priority;
		printf("Enter the data\n");
		scanf_s("%d", &data);
		printf("Enter the priority\n");
		scanf_s("%d", &priority);
		(queue->rear)++;
		(queue->arr)[queue->rear] = (struct element*)malloc(sizeof(struct element));
		(queue->arr[queue->rear])->data = data;
		(queue->arr[queue->rear])->priority = priority;


	}
}

void display(struct priorityqueue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}
	else if (isempty(queue))
	{
		printf("The queue is empty\n");
		printf("\n");
	}
	else
	{
		printf("The data->priority is\n");
		for (int i = 0; i <= (queue->rear); i++)
		{
			printf("%d->%d\t", (queue->arr)[i]->data, (queue->arr)[i]->priority);
			
		}
	}
}
void dequeue(struct priorityqueue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}
	else if (isempty(queue))
	{
		printf("The queue is empty to perform dequeue operation\n");
	}
	else
	{
		int index = 0;
		int max = ((queue->arr)[0])->priority;
		for (int i = 0; i <= (queue->rear); i++)
		{
			if (max < ((queue->arr)[i])->priority)
			{
				max = ((queue->arr)[i])->priority;
				index = i;
			}
		}
		printf("%d is deleted\n", ((queue->arr)[index])->data);
		free((queue->arr)[index]);
			for (int i = index; i < (queue->rear); i++)
			{
				(queue->arr)[i] = (queue->arr)[i + 1];

			}
			(queue->rear)--;
	}
}
void main()
{
	int choice;
	struct priorityqueue* queue = NULL;
	
	do {
		printf("\n");
		printf("1.Create queue\n");
		printf("2.Enqueue\n");
		printf("3.Display queue\n");
		printf("4.DEqueue\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{

		case 1:queue = createqueue();
			break;
		case 2:enqueue(queue);
			break;
		case 3:display(queue);
			break;
		case 4:dequeue(queue);
			break;
		default:printf("Enter valid choice\n\n");
			break;
		}
	} while (choice != 0);

}