# include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    };

node* head;

void create_list(){

for(int i=0; i<10; i++){
    node* temp = new node();
    temp->data = i+1;
    temp->next=head;
    head=temp;
  }
}
//Deleting an element from pos
void delete_element_from_pos(int pos){

node* temp1 = head;
//For deleting the first node
if (pos==1){
    head = temp1->next;
    delete temp1;
    return;
    }
//This logic will work when (n-1)th node will exist
for(int i=0; i<pos-2; i++){
    temp1=temp1->next;
    }
//temp1 points to (n-1)th node
node* temp2 = temp1->next; //temp2 pointing to nth node
temp1->next = temp2->next; //temp1 pointing from (n-1)th to (n+1)th node
delete temp2;
}

void print(){

node* temp = head;
cout<<"List is: ";
while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
cout<<endl;
}

int main(){
    head = NULL;
    create_list();
    print();
    cout<<"Enter pos(1-10) of element to delete: ";
    int pos;
    cin>>pos;
    delete_element_from_pos(pos);
    print();
    return 0;
    }
