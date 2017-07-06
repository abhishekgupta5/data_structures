# include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
    };
struct node* head;

struct node* getNewNode(int x){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int x){
    struct node* newNode = getNewNode(x);
    if (head == NULL){
        head = newNode;
        return;
        }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void print(){
    struct node* temp = head;
    printf("Forward: ");
    while (temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
        }
    printf("\n");
}

void reverse_print(){
    struct node* temp = head;
    if (temp == NULL) return; //Empty list
    //Go to last node
    while(temp->next != NULL){
        temp = temp->next;
        }
    // Traversing backwards using prev
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->prev;
        }
    printf("\n");
}

int main(){
head = NULL;

insertAtHead(2);
print();
reverse_print();
insertAtHead(4);
print();
reverse_print();
insertAtHead(6);
print();
reverse_print();
}

