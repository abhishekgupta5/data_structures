#include<bits/stdc++.h>
using namespace std;

void reverse(char c[], int n){
    stack <char> S;
    //Loop for push
    for(int i=0; i<n; i++){
        S.push(c[i]);
        }
    //Loop for pop
    for(int i=0; i<n; i++){
        c[i] = S.top();
        S.pop();
        }
    }
int main(){
    char arr[51];
    cout<<"Enter a string: ";
    cin.getline(arr, 51);
    reverse(arr, strlen(arr));
    printf("\nReverse is: %s\n", arr);

    }
