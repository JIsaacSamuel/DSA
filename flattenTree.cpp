/*
Question:
Flatten a given tree into a linked list.

LOGIC:
The flattened tree is built recursively just as any other tree. The point to note is that when the pointer reaches a leaf node (both right and left child are NULL) in the given tree, the function returns the address of the node of the tree not the flattened tree.
*/
#include<bits/stdc++.h>
using namespace std;

//This will be our class
class TreeNode{
    public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;

    TreeNode(int val){
        data = val;
        lchild = NULL;
        rchild = NULL;
    }
};

//Inserting nodes (Just an ideal case of taking elements from array and building the tree.)
//Receives an array of elements, a counter, and the number of elements in array.
TreeNode* insertNodes(int arr[], int i, int n){
    
    TreeNode* root = NULL;

    if(i < n){
        if(arr[i] == 0){return root;}

        root = new TreeNode(arr[i]);

        root->lchild = insertNodes(arr, 2*i + 1, n);
        root->rchild = insertNodes(arr, 2*i + 2, n);
    }

    return root;
}

//Function that will be flattening the given binary tree. Notice all elements go to the right child and left child 
//remains NULL by default.
TreeNode* flattenTree(TreeNode* root){
    TreeNode* flat = NULL;
    
    if(root != NULL){
        flat = new TreeNode(root->data);

        flat->rchild = flattenTree(root->lchild);
        flat->rchild = flattenTree(root->rchild);

        return root;
    }

    return flat;
}


//Regular preorder function
void preorder (TreeNode* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->lchild);
    preorder(root->rchild);

    return;
}

int main(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7}; // array with elements to be inserted
    TreeNode* root = insertNodes(arr, 0, 7);
    /*
    Tree built
                        1
                       / \
                      2   3
                     / \ / \ 
                    4  5 6  7
        Preorder: 1, 2, 4, 5, 3, 6, 7
    */
    TreeNode* flat = flattenTree(root); // flat will be the pointer to the root node of our flattened tree
    preorder(flat); cout << endl;

    return 0;
}