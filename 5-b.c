#include <stdio.h>
#include <stdlib.h>


//swap function
void swap(int* a, int i, int minpos)
{
  int minnum = a[i];
  a[i]= a[minpos];
  a[minpos] = minnum;
}

//prints the smallest element from segment j to n in the list
void getsmol(int* a, int j, int n){
    int minnum=a[j];
    int minpos=j;
    for (int c = j; c<n; c++){
        if ((c+1)%3 != 0){
            if (a[c]< a[minpos]){
                swap(a, c, minpos);
            }
        }
    }
    minnum= a[minpos];
    printf("%d ",minnum);
    return;
}


//main function which prints out the k smallest elements.
void kSmallestAmongUntouched(int* a, int k, int n){
    if (k>n){
        printf("Chosen K value is out of bounds, choose another.");
        exit;
    }
    if (n<3){
        printf("\nThe K-many smallest elements of the array are: ");
        if (k<=n){
            for (int j=0; j<=k+(k/3); j++){if ((j+1)%3 != 0) { getsmol(a, j, n); }}
        }
    }
    if (n>=3){
        if (k=n){printf("Chosen K value is out of bounds, choose another."); return 0;}
        printf("\nThe K-many smallest elements of the array are: ");
        for (int j=0; j<=k+(k/3); j++){
            if ((j+1)%3 != 0) {getsmol(a, j, n);}
        }
    }
    
    
}
    
 
//driver function
void main(){
    int a[] = {78, 89, 8, 7, 34, 6, 11, 189, 76, 99, 80, 1, 22, 12, 31, 100, 18};
    int n = sizeof(a)/sizeof(a[0]);
    int k;
    printf("Enter K value : ");
    scanf("%d", &k);
    kSmallestAmongUntouched(a, k, n);
}