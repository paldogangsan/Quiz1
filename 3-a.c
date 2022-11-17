#include <stdio.h>
#include <stdlib.h>

//node
struct node{
    int val;
    struct node* leftchild;
    struct node* rightchild;
};
typedef struct node* TreeNode;

TreeNode newNode(int data)
{
    TreeNode node = (TreeNode)malloc(sizeof(TreeNode));
    node->val = data;
    node->leftchild = NULL;
    node->rightchild = NULL;
 
    return node;
}

//quicksort code copied from my git repo
void quicksort(int *a,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);

   }
}


//mirror the bst
TreeNode invert(TreeNode root){
    if (root==NULL){return NULL;}
    
    TreeNode tempstore= root->rightchild;
    root->rightchild=root->leftchild;
    root->leftchild=tempstore;
    invert(root->leftchild);
    invert(root->rightchild);
    
    return root;
}


//code to convert array to reverse bst
TreeNode arrayToReverseBST(int a[], int first, int last){
    
    int mid= (first+last)/2;
    
    if (first>last){return NULL;}

    TreeNode root= newNode(a[mid]);

    //recursive left sub branch
    root->leftchild= arrayToReverseBST(a,first, mid-1 );

    //recursive right sub branch
    root->rightchild= arrayToReverseBST(a,mid+1, last );

    root=invert(root);

    return root;
}


//print bst code
void prefixPrint(TreeNode node)
{
    if (node == NULL){return;}
    printf("%d ", node->val);
    prefixPrint(node->leftchild);
    prefixPrint(node->rightchild);
}

int main(){
    int a[] = {78, 89, 8, 7, 34, 6, 11, 189, 76};
    int n = sizeof(a)/sizeof(a[0]);
    
    //sorting the array to give as input for reverse binary tree
    quicksort(a, 0, n);

    //converting array to reverse bst
    TreeNode rooty = arrayToReverseBST(a, 0, n);
    
    
    //printf("Prefix order Traversal of the constructed reverse BST ");
    prefixPrint(rooty);
 
    return 0;
}

