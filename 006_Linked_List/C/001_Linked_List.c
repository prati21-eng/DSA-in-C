#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* create_node()
{
    struct node* newnode=NULL;
    newnode =(struct node*) malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        puts("Error In memory allocation");
        exit(EXIT_FAILURE);
    }
    int data;
    puts("Enter The Data:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void createlinkedlist(struct node** head)
{
    struct node* tempnode=(*head);
    struct node* newnode=create_node();

    if((*head)==NULL)
    {
        (*head)=newnode;
    }
    else{
        while (tempnode->next!=NULL)
        {
            tempnode=tempnode->next;
        }
        tempnode->next=newnode;
    }
}
void displaylinkedlist(struct node* head)
{
    struct node* tempnode=head;
    
    if(head==NULL)
    {
        puts("Liked List Is Empty");
    }
    else
    {
        while (tempnode!=NULL)
        {
            printf("%d=>",tempnode->data);
            tempnode=tempnode->next;
        }
        
    }
}

void insertatfirst(struct node** head)
{
    struct node* newnode=create_node();
    newnode->next=*head;
    *head=newnode; 
}
void insertatlast(struct node** head)
{
    createlinkedlist(head);
}
void deleteatfirst(struct node** head)
{
    if(*head==NULL)
    {
        puts("Linked list is empty :");
    }
    else
    {
        struct node* tempnode=*head;
        *head=(*head)->next;
        free(tempnode);
        tempnode=NULL;
    }
}

void deleteatlast(struct node** head)
{
    struct node* tempnode=*head;
    if(*head==NULL)
    {
        puts("Linked List Is Empty");
    }
    else if(tempnode->next==NULL)
    {
        struct node* t_node=tempnode;
        *head=NULL;
        free(t_node);
        t_node=NULL;
    }
    else
    {
        
        while (tempnode->next->next!=NULL)
        {
            tempnode=tempnode->next;
        }
        struct node* t_node=tempnode->next;
        tempnode->next=NULL;
        free(t_node);
        t_node=NULL;

    }
}

int main(void)
{

    int choice;
    struct node* rootNode=NULL;
    do
    {
        puts(" ");
        puts("1.For create linked list");
        puts("2.Display Linked List");
        puts("3:Insert at First");
        puts("4:Insert at last");
        puts("5:Delete At first");
        puts("4:Delete at last");

        puts("0.For Exit");
        
        puts("Enter Your choice :");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:createlinkedlist(&rootNode);
            break;

        case 2:displaylinkedlist(rootNode);
            break;

        case 3:insertatfirst(&rootNode);
            break;

        case 4:insertatlast(&rootNode);
            break;

        case 5:deleteatfirst(&rootNode);
            break;

        case 6:deleteatlast(&rootNode);
            break;
        case 0:puts("Exit");
            break;

        default:puts("Inavlid Choice");
            break;

        } 
        


    } while (choice!=0);
    
    return 0;
}