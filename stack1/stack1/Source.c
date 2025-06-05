#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int* arr;
	int top;
	int cap;
};
struct stack* createstack()
{
	int cap;
	struct stack* tempstack = NULL;
	tempstack =(struct stack*)malloc(sizeof(struct stack));
	printf("Enter the capacity of the stack\n");
	scanf_s("%d", &cap);
	tempstack->cap = cap;
	tempstack->arr = (int*)malloc((tempstack->cap) * sizeof(int));
	tempstack->top = -1;
	return tempstack;
}
int isfull(struct stack* stack)
{
	return stack->top == (stack->cap) - 1;
}
void push(struct stack* stack)
{
	int val;
	printf("Enter the value that you wants to insert in the stack\n");
	scanf_s("%d", &val);
	if (stack == NULL)
	{
		printf("Stack is not created");
	}
	else if (isfull(stack))
	{
		printf("\n");
		printf("The stack is overflow\n");
	}
	else
	{
		(stack->top)++;
		stack->arr[stack->top] = val;
	}

}
int isempty(struct stack* stack)
{
	return stack->top == -1;
}
void pop(struct stack* stack)
{
     if (stack == NULL)
	{
		printf("Stack is not created");
	}
	else if (isempty(stack))
	{
		printf("\n");
		printf("stack is underflow to delete an element\n");
	}
	else
	{
		printf("%d is deleted from stack\n",stack->arr[stack->top]);
		(stack->top)--;
	}
}
void peak(struct stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack is not created");
	}
	else if (isempty(stack))
	{
		printf("Stack is underflow to display peak element\n");
	}
	else
	{
		printf("Peak is\n=");
		printf("%d", stack->arr[stack->top]);
	}
}
void display(struct stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack is not created");
	}
	else if (isempty(stack))
	{
		printf("Elements is not inserted to the stack to display\n");
	}
	else
	{
		for (int i = 0; i <= (stack->top); i++)
		{
			printf("%d\t", stack->arr[i]);
		}
	}
}
void main()
{
	struct stack* stack = NULL;
	int choice;
	do
	{
		printf("\n");
		printf("1.Create stack\n");
		printf("2.Push a element\n");
		printf("3.Pop a element\n");
		printf("4.Peak element\n");
		printf("5.Display the stack\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:stack = createstack();
			break;
		case 2:push(stack);
			break;
		case 3:pop(stack);
			break;
		case 4:peak(stack);
			break;
		case 5:display(stack);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);
}