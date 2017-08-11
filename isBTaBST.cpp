#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    };

node* getNewNode(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
    }

node* insert(int data, node* root){
    if (root == NULL){
        root = getNewNode(data);
        }
    else if (data <= root->data) root->left = insert(data, root->left);
    else root->right = insert(data, root->right);
    return root;
    }

void traverse(node* root){
    if (root == NULL) return;
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        node* current = Q.front();
        cout<<current->data<<" ";
        if (current->left != NULL) Q.push(current->left);
        if (current->right != NULL) Q.push(current->right);
        Q.pop();
        }
    cout<<endl;
    }

bool checkBST(node* root, int minVal, int maxVal){
    if (root == NULL) return true;

    if (root->data > minVal && root->data < maxVal && checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal))
        return true;
    else
        return false;
    }

bool isBinarySearchTree(node* root){
    return checkBST(root, INT_MIN, INT_MAX);
    }

int main(){
    //Construction
    node* root = NULL;
    root = insert(5,root);
    root = insert(10,root);
    root = insert(15,root);
    root = insert(12,root);
    root = insert(8,root);
    root = insert(7,root);
    root = insert(18,root);
    root = insert(1,root);

    traverse(root);
    if (isBinarySearchTree(root)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }

