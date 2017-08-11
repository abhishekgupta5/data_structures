# include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    };

node* findMin(node *root){
    while(root->left != NULL){
        root = root->left;
        }
    return root;
    }

node* del(node* root, int data){

    if (root == NULL) return root;
    else if (data < root->data) root->left = del(root->left, data);
    else if (data > root->data) root->right = del(root->right, data);
    else{
        //Data to be deleted is current root node
        //Case 1: No child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            }
        //Case 2: 1 child
        else if (root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
            }
        else if (root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
            }
        //Case 3: 2 childs
        else{
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
            }
        }
    return root;
    }

//Function to visit tree in inorder
void inorder(node *root){
    if (root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }

//Function to insert node in BST
node* insert(node *root, int data){
    if (root == NULL){
        root = new node();
        root->data = data;
        root->left = root->right = NULL;
        }
    else if (root->data <= data){
        root->right = insert(root->right, data);
        }
    else root->left = insert(root->left, data);
    return root;
    }

main(){
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 11);
    /*
        5
       / \
      3   10
     / \    \
    1   4    11

    */

    cout<<"Inorder before deleting: ";
    inorder(root);
    cout<<endl;

    root = del(root, 10);
    cout<<"Inorder after deleting 10: ";
    inorder(root);
    cout<<endl;

    root = insert(root, 10);
    root = del(root, 5);
    cout<<"Inorder after inserting 10 and deleting 5: ";
    inorder(root);
    cout<<endl;

    }
