#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    };
node* head;

void create_list(){
    for (int i=0; i<10; i++){
        node* temp = new node();
        temp->data = i+1;
        temp->next = NULL;

        if (head == NULL){
            head = temp;
            continue;
            }
        node* temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
            }
        temp1->next = temp;
        }
    }

//Traditional printing
void print(){
node* temp = head;
while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
    cout<<endl;
}

//Reverse printing
/*
void reverse_print(node* p){
if (p==NULL){
    return;
    }
reverse_print(p->next);
cout<<p->data<<" ";
}
*/

//Reversing the list using recursion
void reverse(node* p){
    if(p->next == NULL){
        head = p;
        return;
    }
    reverse(p->next);

    node* q = p->next;
    q->next = p;
    p->next = NULL;
    //Above 3 lines can also be written as
    //p->next->next = p
}

int main(){
  head = NULL;
  create_list();
  print();
  //reverse_print(head);
  reverse(head);
  print();
    }
