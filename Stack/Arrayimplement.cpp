#include<iostream>
using namespace std;


int  pushIntoStack(int arr[],int top,int size){
    if(top!=size){
        top++;
        cout<<"Enter the element for the push operation:";
        int x;
        cin>>x;
        arr[top]=x;
        return top;
    }
    return top;
}

int popFromStack(int arr[],int top){
    if(top!=-1){
        arr[top]=(int)NULL;
        top--;
        return top;
    }
    return top;
}

void printStack(int arr[],int n){
    cout<<"The array elements are as below:\n";
    for(int i=0;i<n;i++){
        cout<<"The element at position "<<i<<arr[i];
    }
}

static int top=-1;

int main(){

    try{
    int n;
    cout<<"Enter the size of the stack:";
    cin>>n;

    if(n<=0){
        throw "negative or zero size cannot be handled!";
    }
    int arr[n];
    char ch='y';
    while(ch=='y' ||ch=='Y'){
    cout<<"Enter the choice as 1 for push ,2 for pop:";
    int x;
    cin>>x;
    switch(x){
        case 1:
        int get1=pushIntoStack(arr,top,n);
        if(get1==top){
            cout<<"Pushing is not possible\n Stack is Full!"<<endl;
        }
        else{
            top++;
            printStack(arr,n);
        }
        break;

        case 2:
        int get2=popFromStack(arr,top);
        if(get2==top){
            cout<<"pop operation not happen\n Stack is Empty!"<<endl;
        }
        else{
            top--;
            printStack(arr,n);
        }
        break;

        default:
            cout<<"Enter choice is wrong";

    }
    
    cout<<"Do you want to continue.Enter the y or Y for continue:";
    cin>>ch;
    }
    }
    catch(string s){
        cout<<s<<endl;
    }
    catch(...){
        cout<<"some error occured!"<<endl;
    }
    return 0;
}