#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int* arr;
	int cap;
	int rear;
	int front;
};
struct queue* createqueue()
{
	
	struct queue* tempqueue = NULL;
	tempqueue = (struct queue*)malloc(sizeof(struct queue));
	printf("Enter the capacity\n");
	scanf_s("%d", &tempqueue->cap);
	tempqueue->arr = (int*)malloc((tempqueue->cap) * sizeof(int));
	tempqueue->rear = -1;
	tempqueue->front = -1;
	return tempqueue;

}
int isfull(struct queue* queue)
{
	return (queue->rear) == (queue->cap) - 1;
}
void enqueue(struct queue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}

	else if (isfull(queue))
	{
		printf("Queue is full\n");
	}
	else
	{
		int val;
		printf("Enter the value that insert in the queue\n");
		scanf_s("%d", &val);
		
		(queue->rear)++;
		queue->arr[queue->rear] = val;
	}
}
int isempty(struct queue* queue)
{
	return (queue->front) == (queue->rear);
}
void dequeue(struct queue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}

	else if (isempty(queue))
	{
		printf("Queue is empty\n");
		printf("\n");
	}
	else
	{
		(queue->front)++;
		printf("%d is deleated\n",queue->arr[queue->front]);
		printf("\n");

	}
}
void peek(struct queue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}
	else if (isempty(queue))
	{
		printf("Queue is empty\n");
		printf("\n");
	}
	else
	{
		printf("%d is peek\n", queue->arr[queue->front+1]);
		printf("\n");

	}
}
void display(struct queue* queue)
{
	if (queue == NULL)
	{
		printf("The queue is not created\n");
	}
	else if (isempty(queue))
	{
		printf("The queue is empty to display elements\n");
	}
	else
	{
		printf("The queue is\n");
		for (int i = (queue->front) + 1; i <= (queue->rear); i++)
		{
			printf("%d\t", (queue->arr)[i]);
		}
	}
}

void main()
{
	struct queue* queue = NULL;
	int choice;
	do
	{
		printf("\n");
		printf("1.Create queue \n");
		printf("2.Enqueue\n");
		printf("3.Dequeue\n");
		printf("4.Display\n");
		printf("5.Peek\n");
		printf("0.Exit\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:queue = createqueue();
			break;
		case 2:enqueue(queue);
			break;
		case 3:dequeue(queue);
			break;
		case 4:display(queue);
			break;
		case 5:peek(queue);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);
}