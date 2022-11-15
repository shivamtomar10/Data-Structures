#include<iostream>
using namespace std;

// Node class
class Node{
  public:
  int data;
  Node* next;
  
  Node(int data){
      this->data=data;
      next=NULL;
  }
    
};


void printNodeElements(Node* head){
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
        if(head==NULL){
            cout<<"NULL"<<endl;
        }
    }
}
int main(){
    
    cout<<"This program is to add Node Element at begin and end Of Singly Linkedlist"<<endl;
    
    Node * head=NULL;
    char ch='y';
    
    
    while(ch=='y' || ch=='Y'){
    cout<<"1. For Adding at begin"<<endl;
    cout<<"2. For Adding at the end\n";
    
    int choice;
    cout<<"Enter 1 or 2 as operational code:";
    cin>>choice;
    
    int value;
    switch(choice){
        case 1:
        cout<<"Enter the value for adding at begin of the list:";
        cin>>value;
        if(head==NULL){
            head=new Node(value);
        }
        else{
            Node* ptr=new Node(value);
            ptr->next=head;
            head=ptr;
        }
        break;
        case 2:
         cout<<"Enter the value for adding at end of the list:";
        cin>>value;
        if(head==NULL){
            cout<<"However List is Empty but we are adding your node as starting head"<<endl;
            head=new Node(value);
        }
        else{
            Node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new Node(value);
            
        }
        break;
        
        default:
        cout<<"Opeartion code enter is invalid!"<<endl;
    }
    cout<<"Do you want to add elements press (y or Y) for it or press any key to quit or exit:";
    cin>>ch;
    }
    cout<<"The List Elements are as follows:"<<endl;
    printNodeElements(head);
    
    return 0;
}
