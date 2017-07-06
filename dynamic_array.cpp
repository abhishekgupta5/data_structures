# include<iostream>

int main(){

    int a; // goes to stack
    int *p;
    p = new int; //declared in dynamic memory(in heap)
    *p = 10;
    delete p;
    p = new int[20];
    delete p;
    }
