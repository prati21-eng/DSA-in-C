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
	tempstack->arr = (int*)malloc((tempstack->cap) * sizeof(int);
	tempstack->top = -1;
	return tempstack;
}
int isfull(struct node* stack)
{
	return if(stack->top==(stack->cap)-1)
}
void push(struct stack* stack) 
{
	int val;
	printf("Enter the elements to insert in the stack\n");
	scanf_s("%d", & val);
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
void main()
{
	struct stack = NULL;
	stack = createstack();
	push(stack);
	push(stack);
	push(stack);
	push(stack);
	push(stack);
	push(stack);
	push(stack);
	push(stack);
	push(stack);
	push(stack);


}