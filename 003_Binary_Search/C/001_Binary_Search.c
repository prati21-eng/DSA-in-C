#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int*,int);
void show(int *,int,const char*);
void bubble_sort(int*,int);
void swap(int*,int*);
int binary_search(int*,int,int,int);
void main()
{
    int N;
    int* arr=NULL;
    time_t start_time,end_time,delta_time;
    puts("Enter how many elements you wants to enter :");
    scanf("%d",&N);

    if(N<=0)
    {
        puts("Invalid Input");
        exit(EXIT_FAILURE);
    }
    arr=(int*)malloc(N*sizeof(int));
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
    printf("Total time required to execute Buuble Sort Function is: %ld\n",delta_time);

    int search;
    puts("Enter Element that you want to search :\n");
    scanf("%d",&search);
    int index;
    index=binary_search(arr,0,N-1,search); //callling of binary search 

    if(index==-1)
    {
        puts("Element not found\n");
    }
    else
    {
        printf("Element foud at index : %d\n",index);
    }

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

//function for printing array
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
    int itr,i;

    for(itr=1;itr<N;itr++)
    {
        int flag=0;
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

//binary search function

int binary_search(int* arr,int low,int high,int search)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]==search)
            return mid;

        if(search<arr[mid])
        {
            return binary_search(arr,low,mid-1,search);
        }
        if(search>arr[mid])
        {
            return binary_search(arr,mid+1,high,search);
        }
    }
    else
    {
        return -1;
    }
}