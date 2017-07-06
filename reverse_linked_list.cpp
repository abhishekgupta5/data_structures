# include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* link;
    };

node* head;

void create_list(){
//cout<<"create_list func start";
for(int i=0; i<10; i++){
    node* temp = new node();
    temp->data = i+1;
    temp->link = NULL;

    if (head == NULL){ //If the list is empty
        head = temp;
        continue;
        }
    //If the list is not empty
    node* temp1 = head;
    while(temp1->link != NULL){
        temp1 = temp1->link;
        }
    temp1->link = temp;

  }
//cout<<"cl func end";
}

void print(){

node* temp = head;
cout<<"List is: ";
while(temp != NULL){
    cout<<temp->data<<" ";
    temp=temp->link;
    }
cout<<endl;
}


//Reversing the list (the iterative way)
//Works when list is only 1 element or empty
void reverse_by_iteration(){
    node *current, *prev, *next;
    prev = NULL;
    current = head;

    while(current != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
        }
    head = prev;
}


int main(){

//cout<<"main invoked";
head = NULL;

create_list();
print();

cout<<"List after reverse (iterative way): ";
reverse_by_iteration();
print();

}

