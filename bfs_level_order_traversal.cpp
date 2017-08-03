#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node *left;
    node *right;
    };


void LevelOrderTraversal(node* root){
    cout<<"Level order traversal of BST is: ";
    if (root == NULL) return;
    //Using queue from STL
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

int main(){
    //Creating the tree
    node* root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');
/*             M
 *            / \
 *           B   Q
 *          / \   \
 *         A   C   Z
*/
    //Print nodes in level order
    LevelOrderTraversal(root);
    }
