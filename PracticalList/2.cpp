#include<iostream>
using namespace std;

//Through array Implementation
class Stack1{
  public:
  int top=-1;
  int* arr=new int[100];
  
  void push(int val){
       if(top+1<100){
      arr[++top]=val;
      cout<<"Insertion SuccessFull"<<endl;
      }
      else{
          cout<<"Insertion Failed"<<endl;
      }
  }
  void pop(){
      if(top!=-1){
      top--;
      cout<<"Deletion SuccessFull"<<endl;
      }
      else{
          cout<<"Deletion Failed"<<endl;
      }
  }
  void printing(){
    
      for(int i=0;i<=top;i++){
          cout<<arr[i]<<" ";
      }
    if(top==-1){
        cout<<"Queue is Empty"<<endl;
    }  
  }
  int popElement(){
      if(top!=-1){
       return arr[top];
      }
  }
}s1;


class Stack2{
  public:
  int top=-1;
  int* arr=new int[100];
  
  void push(int val){
      if(top+1<100){
      arr[++top]=val;
      cout<<"Insertion SuccessFull"<<endl;
      }
      else{
          cout<<"Insertion Failed"<<endl;
      }
      
  }
  void pop(){
      if(top!=-1){
      top--;
      }
  }
  int popElement(){
      if(top!=-1){
       return arr[top];
      }
  }
}s2;
int main(){
    
    cout<<"This program is Used to Perform opeartion of Queue using Two Stacks "<<endl;
    
    cout<<"operation:1 for enqueue\n operation:2 for dequeue\n operation:3 for queue Elements priting "<<endl;
    
    
    char ch='y';
    int value;
    while(ch=='y'|| ch=='Y'){
    cout<<"Enter the operation code:";
    int op_code;
    cin>>op_code;
    switch(op_code){
        case 1: 
        cout<<"Enter the value for enqueue:";
        cin>>value;
        
        s1.push(value);
        break;
        case 2:
        if(s1.top!=-1){
            while(s1.top>-1){
                s2.push(s1.popElement());
                s1.pop();
            }
            s2.popElement();
            s2.pop();
            
            while(s2.top>-1){
                s1.push(s2.popElement());
                s2.pop();
            }
        
        }
        else{
            cout<<"Queue is Empty"<<endl;
        }
        break;
        case 3:
        cout<<"Queue Elemets are as follows:";
        s1.printing();
        break;
        default:
        cout<<"Op code is Invalid! Enter Right op code"<<endl;
    }
    
    cout<<"Do You Want To Continue , Enter y or Y for it:";
    cin>>ch;
    }
    
    return 0;
}
