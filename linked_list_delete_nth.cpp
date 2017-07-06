# include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    };

node* head;

void create_list(){

for(int i=0; i<5; i++){
    node* temp = new node();
    temp->data = i+1;
    temp->next=head;
    head=temp;
}
node* temp = head;
//Traversal and printing the list
cout<<"List is: ";
while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
cout<<endl;
}
//Deleting an element from nth pos

int main(){
    head = NULL;
    create_list();
    return 0;
    }
