#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    };

node* getNewNode(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
    }

node* insert(node* root, int data){
    if (root == NULL){
        root = getNewNode(data);
        }
    else if (data <= root->data){
        root->left = insert(root->left, data);
        }
    else {
        root->right = insert(root->right, data);
        }
    return root;
    }

bool search(node* root, int data){
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
    }

int main(){
node* root = NULL;
root = insert(root, 15);
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 18);
root = insert(root, 30);
root = insert(root, 25);
int number;
cout<<"Enter number to search in BST: ";
cin>>number;
if (search(root, number) == true) cout<<"Found\n";
else cout<<"Not Found\n";
}

