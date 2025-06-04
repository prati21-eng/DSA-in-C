#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int*,int);
void show(int* arr,int N,char* msg);
void insertion_sort(int*,int);
void main()
{
    int* arr=NULL;
    int N;
    puts("How Many elements you wants to insert in the array :");
    scanf("%d",&N);
    if(N<=0)
    {
        puts("Invalid Input");
        exit(EXIT_FAILURE);
    }

    arr=(int*)malloc(N*sizeof(int));

    if(arr==NULL)
    {
        puts("Memory Not alocated");
        exit(EXIT_FAILURE);
    }

    input(arr,N);
    show(arr,N,"Befor Sorting");
    insertion_sort(arr,N);
    show(arr,N,"\n\nAfter sorting\n\n");
}

void input(int* arr,int N)
{
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        arr[i]=rand();
    }
}
void show(int* arr,int N,char* msg)
{
    if(msg!=NULL)
    {
        puts(msg);
    }
    for(int i=0;i<N;i++)
    {
        printf("arr[%d]=>%d\n",i,arr[i]);
    }
}
void insertion_sort(int* arr,int N)
{
    int empty;
    int key;
    for(int i=1;i<N;i++)
    {
        key=arr[i];
        empty=i;
        while (empty>0&&arr[empty-1]>key)
        {   
            arr[empty]=arr[empty-1];
            empty--;
        }
        arr[empty]=key; 
    }
}