#include<bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    int data;
    };

node* head;

void create_list(){
    for (int i=0; i<10; i++){
        node* temp = new node();
        temp->data = i+1;
        temp->next = NULL;

// Inserting at the end
        if (head == NULL){
            head = temp;
            continue;
            }
        node * temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
            }
        temp1->next = temp;
        }
    }

void print(){
    node* temp = head;
    cout<<"List is: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        }
    cout<<endl;
    }


//Reversing using explixit stack
void reverse_using_explicit_stack(){
    if (head == NULL) return;

    //Using stack from STL
    stack<struct node*> S;

    node* temp = head;
    //Pushing all the addresses on stack S
    while(temp != NULL){
        S.push(temp);
        temp=temp->next;
        }

    //Poping all addresses and printing from stack S
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
            temp->next = S.top();
            S.pop();
            temp=temp->next;
        }
    temp->next = NULL;
    }


int main(){
    head=NULL;
    create_list();
    print();
    reverse_using_explicit_stack();
    cout<<"After reversal: "<<endl;
    print();
    }
