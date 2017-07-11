#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x){
    if (top == MAX_SIZE-1){
        printf("Stack Overflow. Can't push.");
        return;
        }
    A[++top]=x;
    }

int pop(){
    if (top == -1){
        printf("Empty stack.");
        return -1;
        }
    return A[top--];
    }

void print(){
    printf("\nStack is: ");
    for (int i=0; i<=top; i++)
        printf("%d ", A[i]);
    printf("\n");
    }

int main(){
    push(2);
    print();
    push(4);
    print();
    push(6);
    print();
    push(8);
    print();
    printf("\n%d", pop());
    printf("\n%d", pop());
    push(10);
    print();
    printf("\n%d", pop());
    print();

    }
