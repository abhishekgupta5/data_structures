# include<bits/stdc++.h>
using namespace std;

void insert_in_beg(int);
void insert_at_end(int);
void print();

struct node{
    int data;
    node* next;
    };

node* head;

int main(){
head = NULL;
cout<<"How many numbers to insert in beg: ";

int n, x;
cin>>n;
for (int i=0; i<n; i++){
    cin>>x;
    insert_in_beg(x);
    print();
    }
cout<<endl<<"How many numbers to insert at the end: ";
cin>>n;
for(int i=0; i<n; i++){
    cin>>x;
    insert_at_end(x);
    print();
    }
}

void insert_in_beg(int x){

//Inserting at the beginning of the list
node* temp = new node();
temp->data = x; //Similar syntax... (*temp).data = 2;
temp->next = head;
head = temp;
}

void insert_at_end(int x){

//Inserting at the end of the list
node* temp = new node();
temp->data = x;
temp->next = NULL;
node* temp1 = head;
while (temp1->next != NULL){
    temp1 = temp1->next;
    }
temp1->next = temp;
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
/* temp = new node();
temp->data = 4;
temp->next = NULL;

node* temp1 = head;
while(temp1->next != NULL){
    cout<<temp1->data;
    temp1 = temp1->next;
    }
temp1->next = temp;
*/

