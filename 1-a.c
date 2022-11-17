
#include <stdio.h>

void basicFizzBuzz(int x)
{
    int fizzcheck1, fizzcheck2, fizzcheck, buzzcheck1, buzzcheck2, buzzcheck;
    fizzcheck1= x % 3;
    fizzcheck2= x % 5;
    if (fizzcheck1== 0 || fizzcheck2== 0){fizzcheck=1;} //something similiar to OR logic gate
    
    buzzcheck1= x % 11;
    buzzcheck2= x % 13;
    if (buzzcheck1== 0 || buzzcheck2== 0){buzzcheck=1;} //something similiar to OR logic gate
    
    if (fizzcheck == 1 && buzzcheck== 1){printf("fizzbuzz");}
    else if (fizzcheck == 1){printf("fizz");}
    else if (buzzcheck == 1){printf("buzz");}
    else {printf("%d", x);}
    
}

int main(){
    int x;
    printf("Enter any number : ");
    scanf("%d",&x);
    basicFizzBuzz(x);
    return 0;
}