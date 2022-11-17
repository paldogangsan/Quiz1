#include <stdio.h>
#include <stdlib.h>

//node
struct node{
    int val;
    struct node* leftchild;
    struct node* rightchild;
};
typedef struct node* TreeNode;


/////////////////////////////////////////////////////////////////////////////////////////////////////
/*FILLER CODE FOR A REVERSE BINARY TREE CREATION FROM THE PREVIOUS QUESTION*/
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

    return invert(root);
}


/*END OF FILLER CODE, START OF CODE FOR THIS QUESTION*/
///////////////////////////////////////////////////////////////////////////////////////////////////


//Binary Tree Search for reverse BST
TreeNode BTS( TreeNode root, int k)
{
 
    if(root== NULL){return NULL;}

    if (k< root->val){return BTS(root->rightchild , k);}
    else if ( k > root->val ) {return BTS(root->leftchild, k);}
    else{return root;}
}

//function to find minimum val along the right branches of K
TreeNode minval(TreeNode temp)
{
    TreeNode curr= temp;

    while (curr->rightchild != NULL)
    {
        curr= curr->rightchild;
    }
    return curr;
}

//successor code without the use of parent pointer
TreeNode successorReverseBST(TreeNode root, int k){
    TreeNode KNode;
    TreeNode curr;
    
    //creating a node for successor
    TreeNode Ksucc = NULL;
    
    KNode = BTS(root, k);
    if (KNode=NULL){printf("Pudding "); exit;}
    
    curr = KNode->rightchild;
    
    //if left child of KNode != NULL, recursively call minvalue function.
    if (curr != NULL)
    {
        return minval(curr->leftchild);
    }
    else if (curr == NULL){

        //start from root, to search for successor while going downwards
        while (root != NULL){
            if (root->val < KNode->val)
        {
            root=root->leftchild;
        }
        else if (root->val > KNode->val)
        {
            Ksucc=root;
            root=root->rightchild;
        }
        else break;

        }
    }
    return Ksucc;
}   



int main(){
    int a[] = {78, 89, 8, 7, 34, 6, 11, 189, 76};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n);
    TreeNode rooty = arrayToReverseBST(a, 0, n);
    TreeNode Ksucc= successorReverseBST(rooty, 6);
    if (Ksucc==NULL){ printf("Hamburger ");}
    else {printf("The successor of 6 is %d. ", Ksucc->val);}
    return 0;

}

