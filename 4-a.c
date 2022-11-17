#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *b;
    *b=*a;
    *a=temp;
}

void maxheapify(int* a, int n, int i)
{
    int big = i ;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<n && a[l]>a[big]){big=l;}

    if (r < n && a[r] > a[big]){big=r;}

    if (big != i){swap(&a[i], &a[big]); maxheapify(a,n,big);}
}

int extractmax(int arr[], int n)
 {
     int max;
     if(n < 1){return 0;}
     max = arr[0];
     n = n - 1;
     maxheapify(arr, n, 1);
     return max;
 }

 int thirdLargestNum(int* maxHeap, int n){
    if (n<3)
    {
        return 0;
    }

    for (int i=1; i<=3; i++)
    {
        int big= extractmax(maxHeap, n);
        if (i==3){printf("The third biggest element is: %d", big);}
    }
    
 }

 int main()
 {
    int maxHeap[]={50, 30, 15, 19, 20, 10, 5, 2};
    int n = sizeof(maxHeap)/sizeof(maxHeap[0]);
    thirdLargestNum(maxHeap, n);
 }