#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node* left;
    node* right;
    };

node* insert(node* root, char data){
    if (root == NULL){
        root = new node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        }
    else if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
    }

void preorder(node* root){
    if (root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    }

void inorder(node* root){
    if (root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }

void postorder(node* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    }

int main(){
    //Creating the tree
    node* root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');
/*              M
 *             / \
 *            B   Q
 *           / \   \
 *          A   C   Z
*/
    cout<<"Preorder traversal of BST: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal of BST: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal of BST: ";
    postorder(root);
    cout<<endl;
    }
