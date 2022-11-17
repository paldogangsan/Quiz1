#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int i, int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}


int * sortEveryThirdElement(int * a, int n){

    if (n<=5){return a;}

    for (int i=2; i+3<n; i=i+3){
        for (int k=1; i+(3*k)<n; k++){
            int j= i+(3*k);
            if (a[i]>a[j]){swap(a, i, j);}

        }

    }

    return a;

}

void main(){
    int list[] = {78, 89, 8, 7, 34, 6, 11, 189, 76};
    int n = sizeof(list)/sizeof(list[0]);
    printf("Unsorted List: "); 
    for (int i=0; i<n; i++){printf("%d ", list[i]);}
    printf("\n");
    int* newlist= sortEveryThirdElement(list, n);
    printf("Every Third Element Sorted List: ");
    for (int i=0; i<n; i++){printf("%d ", newlist[i]);}
return;
}