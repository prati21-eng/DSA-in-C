#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	struct node* right;
	int data;
};
struct node* createnode()
{
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		printf("Memory is not alloacated\n");

	}
	else
	{
		int data;
		printf("Please enter the data\n");
		scanf_s("%d", &data);
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
}
void createBST(struct node** root)
{
	struct node* newnode = NULL;
	struct node* tempnode = *root;
	newnode = createnode();
	if ((*root) == NULL)
	{
		*root = newnode;
	}
	else
	{
		while (tempnode != NULL)
		{
			if (newnode->data < tempnode->data )
			{
				if (tempnode->left == NULL)
				{
					tempnode->left = newnode;
					break;
				}
				else
				{
					tempnode = tempnode->left;
				}
			}
			else
			{
				if (tempnode->right == NULL)
				{
					tempnode->right = newnode;
					break;
				}
				else
				{
					tempnode = tempnode->right;
				}
			}
		}
	}
}
void preorder(struct node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
struct queue
{
	int front;
	int rear;
	int capacity;
	struct root** arr;
};
void insert(struct queue* ptr, struct node* root)
{
	if (ptr->rear != ptr->capacity)
	{
		(ptr->rear)++;
		(ptr->arr)[ptr->rear] = root;
	}
}
struct node* front(struct queue* ptr)
{

	return ptr->arr[(ptr->front) + 1];
}
void delete(struct queue* ptr)
{
	(ptr->front)++;
}
void levelorder(struct node* root)
{
	struct queue* ptr = (struct queue*)malloc(sizeof(struct queue));
	ptr->rear = -1;
	ptr->rear = -1;
	printf("Please enter capacity\n");
	scanf_s("%d", &(ptr->capacity));
	ptr->arr = (struct node**)malloc(sizeof(struct node*));
	insert(ptr, root);
	while (ptr->front != ptr->rear)
	{
		struct node* current = front(ptr);
		printf("%d\t",current->data);
		delete(ptr);

		if (current->left != NULL)
		{
			insert(ptr, current->left);
		}
		if (current->right != NULL)
		{
			insert(ptr, current->right);
		}
	}

}
void postorder(struct node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}
void main()
{
	struct node* root = NULL;
	int choice;
	do
	{
		printf("\n");
		printf("1.Create BST\n");
		printf("2.Preorder\n");
		printf("3.Inorder\n");
		printf("4.Postorder\n");
		printf("5.Level order\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:createBST(&root);
			break;
		case 2:preorder(root);
			break;
		case 3:inorder(root);
			break;
		case 4:postorder(root);
			break;
		case 5:levelorder(root);
			break;
		default:printf("Enter valid choice\n");
			break;
		}
	} while (choice != 0);
}