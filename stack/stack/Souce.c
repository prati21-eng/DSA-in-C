#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int* arr;
	int cap;
	int top;
};
struct stack* createstack()
{
	int cap;
	struct stack* tempstack = NULL;
	tempstack = (struct stack*)malloc(sizeof(struct stack));
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
	printf("Enter the elements to insert in the stack\n");
	scanf_s("%d", &val);
	if (isfull(stack))
	{
		printf("Stack is overflow\n");
	}
	else
	{
		(stack->top)++;
		stack->arr[stack->top] = val;
	}

}
void display(struct stack* stack)
{
	if (stack->top == -1)
	{
		printf("The stack is empty");
	}
	else
	{
		for (int i = 0; i <= (stack->top); i++)
		{
			printf("%d\t", stack->arr[i]);
		}
	}
}
int isempty(struct stack* stack)
{
	return stack->top == -1;
}
void pop(struct stack* stack)
{
	if (isempty(stack))
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d is deleted\n", stack->arr[stack->top]);
		(stack->top)--;
	}
}
void main()
{
	int choice;
	struct stack* stack= NULL;
	stack = createstack();
	
	do
	{
		printf("\n1.Push the elements in the stack\n");
		printf("2.Display stack\n");
		printf("3.Pop a element in the stack\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:push(stack);
			break;
		case 2:display(stack);
			break;
		case 3:pop(stack);
			break;
		default:printf("Please enter valid choice\n");
		}
	} while (choice != 0);
}