#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int*,int);
void show(int*,int,const char*);
void merge_sort(int*,int,int);
void merge_proc(int*,int,int,int);
 int main(void)
 {
    int N;
    int* arr=NULL;
    puts("Enter the value of N :\n");
    scanf("%d",&N);
    if(N<=0)
    {
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }

    arr=(int*)malloc(N*sizeof(int));
    if(arr==NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    input(arr,N);
    show(arr,N,"Before Sorting");
    int s_time=time(0);
    merge_sort(arr,0,N-1);
    int e_time=time(0);
    show(arr,N,"\nAfter Sorting\n");

    int deltatime=e_time-s_time;
    printf("Total Time required : %d",deltatime);

    free(arr);
    exit(EXIT_SUCCESS);

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
    if(msg)
    {
        puts(msg);
    }

    for(int i=0;i<N;i++)
    {
        printf("arr[%d]=>%d\n",i,arr[i]);
    }
 }

 void merge_sort(int* arr,int low,int high)
 {
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(arr,low,mid); //for left side
        merge_sort(arr,mid+1,high);  //for right side
        merge_proc(arr,low,mid,high);
    }
 }

 void merge_proc(int* arr,int low,int mid,int high)
 {
    int i,j,k;
    int N1,N2;
    N1=mid-low+1;
    N2=high-mid;
    int* a1=NULL;
    int* a2=NULL;

    a1=(int*)malloc(N1*sizeof(int));
    if(a1==NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);
    }
    a2=(int*)malloc(N2*sizeof(int));
    if(a2==NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<N1;i++)
    {
        a1[i]=arr[low+i];
    }
    for(i=0;i<N2;i++)
    {
        a2[i]=arr[mid+1+i];
    }

    i=0;
    j=0;
    k=0;
    while ( i < N1 && j < N2)
    {
        if(a1[i]<a2[j])
        {
            arr[low+k]=a1[i];
            i++;
            k++;
        }
        else
        {
            arr[low+k]=a2[j];
            j++;
            k++;
        }
    }
    while (i<N1)
    {
        arr[low+k]=a1[i];
        i++;
        k++;
    }

    while (j<N2)
    {
        arr[low+k]=a2[j];
        i++;
        j++;
    }
     free(a1);
     free(a2);
    
 }
 