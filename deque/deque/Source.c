#include<stdio.h>
#include<stdlib.h>
struct deque
{
	int* arr;
	int cap;
	int front;
	int rear;
};
struct queue* createqueue()
{
	int cap;
	struct deque* tempqueue = NULL;
	tempqueue = (struct deque*)malloc(sizeof(struct deque));
	printf("Please enter the capacity\n");
	scanf_s("%d", &cap);
	tempqueue->cap = cap;
	tempqueue->arr = (int*)malloc((tempqueue->cap) * sizeof(int));
	tempqueue->front = -1;
	tempqueue->rear = -1;
	return tempqueue;
}
int isfull(struct deque* queue)
{
	return (queue->rear) == (queue->cap) - 1;
}
int isempty(struct deque* queue)
{
	return (queue->front) == (queue->rear);

}
void enqueuerear(struct deque* queue)
{
	if (queue == NULL)
	{
		printf("Queue is not created\n");
	}
	else if (isfull(queue))
	{
		printf("Queue is full\n");
		printf("\n");
	}
	else
	{
		int val;
		printf("Enter the value to insert in the queue\n");
		scanf_s("%d", &val);
		(queue->rear)++;
		(queue->arr)[queue->rear] = val;
	}
	
}

void dequeuefront(struct deque* queue)
{
	if (queue == NULL)
	{
		printf("Queue is not created\n");
	}
	else if (isempty(queue))
	{
		printf("Queue is empty\n");
		printf("\n");
	}
	else
	{
		(queue->front)++;
		printf("%d is deleated\n", queue->arr[queue->front]);
		printf("\n");

	}
}
void enqueuefront(struct deque* queue)
{
	if (queue == NULL)
	{
		printf("Queue is not created\n");
	}
	else if (isfull(queue))
	{
		printf("Queue is full\n");
		printf("\n");
	}
	else
	{
		int i;
		int val;
		printf("Enter the data to insert in the queue\n");
		scanf_s("%d", &val);
		while((queue->rear)!=(queue->front))
		{
			(queue->arr)[(queue->rear)+1] = (queue->arr)[queue->rear];
			(queue->rear)--;
		}
		(queue->front)++;
		(queue->arr)[queue->front] = val;
		
	}

}
void display(struct deque* queue)
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
		for (int i = (queue->front)+1; i <= (queue->rear); i++)
		{
			printf("%d\t", (queue->arr)[i]);
		}
	}
}
void main()
{
	struct deque* queue = NULL;
	int choice;
	do
	{
		printf("\n");
		printf("1.create queue\n");
		printf("2.Enqueuerear\n");
		printf("3.Dequeuefront\n");
		printf("4.Enqueuefront\n");
		printf("5.Dequeuerear\n");
		printf("6.Display\n");
		printf("7.Exit\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:queue = createqueue();
			break;
		case 2:enqueuerear(queue);
			break;
		case 3:dequeuefront(queue);
			break;
		case 4:enqueuefront(queue);
			break;
		//case 5:dequeuerear(queue);
			//break;
		case 6:display(queue);
			break;
		default:printf("Enter the valid choice\n");
			break;
		}
	} while (choice != 0);
}