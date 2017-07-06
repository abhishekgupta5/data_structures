#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    };

//Here we are not declaring the head as a global variable.
//Instead it is declared as local in main. So, we'll have to
//pass it in function as argument and the function should return it
//after modifying which could be collected in main for further use
//in print function.

node* create_list(node* head){
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
    return head;
    }

//Traditional printing via iteration
void print(node* head){
    cout<<"List is: ";
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
        }
    cout<<endl;
    }

//Reverse printing
void reverse_print(node* head){
if (head==NULL){
    return;
    }
reverse_print(head->next);
cout<<head->data<<" ";
}

int main(){
  node* head = NULL;
  head = create_list(head);
    //Here, instead of returning the head pointer from create_list
    //function, we could also have done it like, we could have passed
    //reference to head as an argument (create_list(&head)), in this
    //case, definition of create_head func should be like
    //{create_head(node** pointerToHead)}
    //and inside the func, in place of 'head', we could have
    //dereferenced and use '*pointerToHead'
  cout<<"This is reverse print: ";
  reverse_print(head);
  cout<<endl;
  cout<<"This is traditional print: ";
  print(head);
    }
