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

//Iterative method to find min in BST
int min(node* root){
    if (root == NULL){
        cout<<"Empty tree."<<endl;
        return -1;
        }
    while(root->left != NULL){
        root = root->left;
        }
    return root->data;
    }

//Recursive method to find max in BST
int max(node* root){
    if (root == NULL){
        cout<<"Empty tree."<<endl;
        return -1;
        }
    else if (root->right == NULL){
        return root->data;
        }
    //Search in right subtree
    return max(root->right);
    }

int height(node* root){
    if (root == NULL){
        return -1;
        }
    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
    }

int main(){
node* root = NULL;
root = insert(root, 15);
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 18);
root = insert(root, 30);
root = insert(root, 25);

int minimum = min(root);
int maximum = max(root);

int h = height(root);

cout<<"Min element: "<<minimum<<endl;
cout<<"Max element: "<<maximum<<endl;
cout<<"Height of BST: "<<h<<endl;

int number;
cout<<"Enter number to search in BST: ";
cin>>number;
if (search(root, number) == true) cout<<"Found\n";
else cout<<"Not Found\n";
}

