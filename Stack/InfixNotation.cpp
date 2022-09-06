#include<iostream>
using namespace std;

char stack[100];
int top=-1,size=100;

void pushIntoStack(char value){
    if(top!=size){
        top++;
        stack[top]=value;
        // cout<<"stack[top]"<<stack[top]<<endl;

    }
    else{
        cout<<"Stack is full"<<endl;
    }
}

void display(){
    for(int i=0;i<=top;i++){
        cout<<"The elements at position "<<i<<"is:"<<stack[i]<<endl;
    }
}
int main(){

    string s="";
    cout<<"Enter the expression in infix notation:";
    getline(cin,s);

    int len=s.length();
    for(int i=0;i<len;i++){
        char h=s[i];
        // cout<<"h="<<h<<endl;
        pushIntoStack(h);
    }

    display();

    return 0;
}