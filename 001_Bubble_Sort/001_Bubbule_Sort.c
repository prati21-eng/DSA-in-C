#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int*,int);
void show(int *,int,const char*);
void bubble_sort(int*,int);
void swap(int*,int*);
void main()
{
    int N;
    int* arr=NULL;
    time_t start_time,end_time,delta_time;
    arr=(int*)malloc(N*sizeof(int));
    puts("Enter how many elements you wants to enter :");
    scanf("%d",&N);

    if(N<=0)
    {
        puts("Invalid Input");
        exit(EXIT_FAILURE);
    }
     if(arr==NULL)
    {
        puts("Error in memeory generation for array");
        exit(EXIT_FAILURE);
    }
    input(arr,N);
    show(arr,N,"Before Sorting");

    start_time=time(0);
    bubble_sort(arr,N);
    end_time=time(0);
    show(arr,N,"\n\nAfter Sorting\n");
    delta_time=end_time-start_time;
    printf("Total time required to execute Buuble Sort Function is: %ld",delta_time);

    free(arr);
    arr=NULL;
}
void input(int* arr,int N)
{
    int i;
    srand(time(0));
    for(i=0;i<N;i++)
    {
        arr[i]=rand();
    }
}
void show(int* arr,int N,const char* msg)
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
//bubble sort function
void bubble_sort(int* a,int N)
{
    int itr,i,flag=0;

    for(itr=1;itr<N;itr++)
    {
        for(i=0;i<N-itr;i++)
        {
            if(a[i]>a[i+1])
            {
                flag=1;
                swap(&a[i],&a[i+1]); //function call for swapping provides only address
            }

        }
        if(flag==0)
        {
            break;
        }
    }
}
//function for swapping
void swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}