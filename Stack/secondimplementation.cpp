#include<iostream>
using namespace std;

int stack[100],top=-1,size=100;



void pushIntoStack(int value){
    if(size!=top){
        top++;
        stack[top]=value;

    }
    else{
        cout<<"Stack is full"<<endl;
    }
}
void display(){
    for(int i=0;i<=top;i++){
        cout<<"The element at the position "<<i<<":"<<stack[i]<<endl;
    }
}

void popFromStack(){
    if(top!=-1){
        cout<<"The pop element is:"<<stack[top]<<endl;
        top--;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}

int main(){

    cout<<"1. Push the element into the stack"<<endl;
    cout<<"2. Pop the element from the stack"<<endl;
    cout<<"3. Display the array"<<endl;
    cout<<"4. Exit"<<endl;

    int x;
    cout<<"Enter the choice to perform:";
    cin>>x;
    switch(x){
        case 1:
        cout<<"Enter the element to be push into the stack:";
        int value;
        cin>>value;
        pushIntoStack(value);
        break;

        case 2:
        popFromStack();
        break;

        case 3:
        display();
        break;

        case 4:
        cout<<"Exit"<<endl;
        break;

        default:

        cout<<"Invalid input!"<<endl;

    }

    cout<<"Do you want to continue: press y or Y for continue"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y'){
        main();
    }
    return 0;
}