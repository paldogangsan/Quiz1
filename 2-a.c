//start of code ADITI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//creating the node
struct node {
    int val;
    struct node * next;
    struct node * next2;

};
typedef struct node * NodeAddress;



//creating a function to print the linked list
void PrintLinkedList (NodeAddress head) {
    NodeAddress a;
    printf("Linked List= ");
    for (a= head; a!= NULL; a=a->next) {
        printf( a==head? "%d" : " -> %d", a->val);
    }
} 


//creating a function to generate an array
int * generateArray(int n) {
    int * t = malloc( n * sizeof(int) );
    if (t) {
        for( int i=0; i<n; i++) {t[i]=i;}
    }
    return t;
}


//creating a function to convert array into a linked list with pointers next and next2
NodeAddress arrayToLLWithNext2 (int * a, int n) {
    int i;
    NodeAddress head = NULL;
    NodeAddress head2 = NULL;
    NodeAddress temp = NULL;
    NodeAddress last1 = NULL;
    NodeAddress last2 = NULL;

    if (n==1) {
        head= malloc(sizeof(struct node));
        head->val= a[0];
        head->next= NULL;
        head->next2= NULL;
        temp = head;
    }
    if (n>1) {
        head = malloc(sizeof( struct node));
        head->val= a[0];
        temp = malloc(sizeof( struct node));
        head->next = temp;
        head->next2 = NULL;
        temp->val=a[1];
        temp->next=NULL;
        temp->next2=NULL;
        last1=temp;
        last2= head;
        
    }
    
    for (i=2; i<n; i++) {
            temp = malloc(sizeof( struct node));
            last1->next=temp;
            last2->next2=temp;
            temp->val = a[i];
            temp->next = NULL;
            temp->next2 = NULL;
            last2=last1;
            last1=temp;
    }
return head;}


// FREEING THE SPACE, PREVENTING MEMORY LEAKS
void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}



// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


//driver code
int main(int argc, char **argv) {
    
    int n=7;
    int* a;
    NodeAddress listy;
    a = generateArray(n);
	listy = arrayToLLWithNext2(a,n);
    PrintLinkedList(listy);

	free(a);
	freeLinkedList(listy);
    return 0;
}

//end of code ADITI