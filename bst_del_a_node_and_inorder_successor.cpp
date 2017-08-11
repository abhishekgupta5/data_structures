# include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    };


node* find(node* root, int data){ //O(h)
    if (root == NULL) return NULL;
    else if (root->data == data) return root;
    else if (root->data < data) return find(root->right, data);
    else return find(root->left, data);
    }


node* findMin(node* root){ //O(h)
    if (root == NULL) return NULL;
    while(root->left != NULL)
        root = root->left;
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


node* getSuccessor(node* root, int data){ //O(h)
    //Search a node in BST is O(h)
    node* current = find(root, data);
    if (current == NULL){
        return NULL;
        }
    //Case 1: Node has right sub tree
    if (current->right != NULL){
        return findMin(current->right);
        }
    //Case 2: No right subtree
    else{
        node* successor = NULL;
        node* ancestor = root;
        while(ancestor != current){
            if (current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
                }
            else
                ancestor = ancestor->right;
            }
        return successor;
        }
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

    cout<<"Inorder successor of 1: "<<getSuccessor(root, 1)->data<<endl;
    cout<<"Inorder successor of 3: "<<getSuccessor(root, 3)->data<<endl;
    cout<<"Inorder successor of 4: "<<getSuccessor(root, 4)->data<<endl;
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
