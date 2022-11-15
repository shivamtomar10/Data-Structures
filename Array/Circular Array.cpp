#include<iostream>
using namespace std;

//This program is for circular Array

class CircularArray{
  public :
  int rear=-1,front=-1;
  int size;
  int *arr=new int[size];
  
  void addition_Array(int data);
  void deletion_Array();          
  
}obj;

void CircularArray::addition_Array(int data){
    if((rear+1)%size==front){
        cout<<"Addition cannot happen due to :Array is Full"<<endl;
    }
    else{
        arr[(rear+1)%size]=data;
        rear=(rear+1)%size;
        if(front==-1){
            front++;
        }
        cout<<"Addition Successfull"<<endl;
    }
}

void CircularArray::deletion_Array(){
    if(front==-1){
        cout<<"Deletion cannot happen as Array is Empty"<<endl;
    }
    else{
        
        if(front==rear){
            arr[front%size]=-1;
            front=-1;
            rear=-1;
        }   
        else{
            arr[front%size]=-1;
            front=(front+1)%size;
        }
        
        cout<<"Deletion Successfull"<<endl;
    }  
        
    
}
int main(){
    
    
    cout<<"Enter the size of your Circular Array:";
    cin>>obj.size;
   
    char ch='y';
    while(ch=='y' || ch=='Y'){
        
        cout<<"1. For Addition into the array"<<endl;
        cout<<"2. For Deletion from the array"<<endl;
        
        int choice,data;
        cout<<"Enter 1 or 2 for operation number to be done:";
        cin>>choice;
        
        switch(choice){
            case 1:
            cout<<"Enter the data for addition:";
            cin>>data;
            obj.addition_Array(data);
            break;
            case 2:
            obj.deletion_Array();
            break;
            default:
            cout<<"Your Enter operation is incorrect!"<<endl;
        }
        
        cout<<"Do you want to continue.Enter y or Y for it or press any key to quit:";
        cin>>ch;
    }
    return 0;
}
