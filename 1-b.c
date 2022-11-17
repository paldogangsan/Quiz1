#include <stdio.h>

int i, j, check, buzzcheck=0, fizzcheck=0;

void advancedFizzBuzz(int* a, int m, int* b, int nb, int* f, int nf){
    
    for (i=0; i<m; i++){
        
        // check in array f
        for (j=0; j<nf; j++){
            fizzcheck=0;
            check=a[i] % f[j];
            if (check==0){
                fizzcheck=1;
                break;
            } 
        }

        //check in array b
        for (j=0; j<nb; j++){
            buzzcheck=0;
            check=a[i] % b[j];
            if (check==0){
                buzzcheck=1;
                break;
            }
        }
        if (fizzcheck == 1 && buzzcheck== 1){printf("fizzbuzz ");}
        else if (fizzcheck == 1){printf("fizz ");}
        else if (buzzcheck == 1){printf("buzz ");}
        else {printf("%d ", a[i]);}
    }

}

int main(){
    int m, nf, nb;
    
    printf("Enter length of array a: ");
    scanf("%d", &m);
    int a[m];
    printf("Enter the %d elements of the array 'a':", m);
    for (int counter=0; counter<m; ++counter){
        scanf("%d", &a[counter]);
    }
    
    printf("Enter length of array f: ");
    scanf("%d", &nf);
    int f[nf];
    printf("Enter the %d elements of the array 'f':", nf);
    for (int counter=0; counter<nf; ++counter){
        scanf("%d", &f[counter]);
    }
    
    
    printf("Enter length of array b: ");
    scanf("%d", &nb);
    int b[nb];
    printf("Enter the %d elements of the array 'b':", nb);
    for (int counter=0; counter<nb; ++counter){
        scanf("%d", &b[counter]);
    }

    advancedFizzBuzz(a, m, f, nf, b, nb);
    return 0;
}