#include <stddef.h>
#include <stdio.h>
#include <math.h>

void returnSmallestNum(int maxHeap[], int n){
    int height = log(n);
    int NumLeafNodes= pow(2, height);
    int min= maxHeap[n-1];
    for (int i=n-1; i>=n-NumLeafNodes; i=i-1){
        if (maxHeap[i]<min){min=maxHeap[i];}
    }
    printf("The smallest element of this heap is: %d",min);
}

int main(){
    int maxHeap[]={50, 30, 15, 19, 20, 10, 5, 2};
    int n = sizeof(maxHeap)/sizeof(maxHeap[0]);
    returnSmallestNum(maxHeap, n);
}