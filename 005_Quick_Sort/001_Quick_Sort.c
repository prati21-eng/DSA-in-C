#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

int partition(int* arr, int p,int r)
{
    int pivote=arr[r];
    int i=p-1;
    int j,temp;

    for(int j = p ; j < r ; j++)
    {
        if(arr[j]<pivote)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return (i+1);
}
void quick_sort(int* arr,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}

//main function
void main()
{
    int N;
    int* arr=NULL;

    puts("Entre How Many Elements you Wants To Enter In The Array :");
    scanf("%d",&N);

    if(N<=0)
    {
        puts("Invalid Input ");
        exit(EXIT_FAILURE);
    }
    arr=(int*)malloc(N*sizeof(int));

    if(arr==NULL)
    {
        puts("Error in the memory allocation");
        exit(EXIT_FAILURE);
    }
    input(arr,N);
    show(arr,N,"Before Sorting");
    quick_sort(arr,0,N-1);
    show(arr,N,"After Sorting");
}