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

Node* reverseNodeElement(Node* head){
     if(head!=NULL){
            
            Node* ptr=head;
            Node* nextofNode=NULL;
            Node* ptr1=NULL;
            while(ptr!=NULL){
                nextofNode=ptr->next;
                ptr->next=ptr1;
                ptr1=ptr;
                ptr=nextofNode;
            }
            head=ptr1;
            
        }
        return head;
}

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
    
    cout<<"This program is to reverse Element of Singly Linkedlist"<<endl;
    
    Node * head=NULL;
    char ch='y';
    int p=1;
    while(ch=='y' || ch=='Y'){
        
        int value;
        cout<<"Enter the value of the "<<p++<<" node is:";
        cin>>value;
        
        if(head==NULL){
            head=new Node (value);
        }
        else{
            Node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new Node(value);
            
        }
    
        cout<<"Dou you want to add elements press (y or Y) for it or press any key to quit or exit:";
        cin>>ch;
    }
    
    cout<<"The List Elements are as follows:"<<endl;
    printNodeElements(head);
    
    
    cout<<"The List Elements after reversing the list are as follows:"<<endl;
    Node* head1=reverseNodeElement(head);
    printNodeElements(head1);
    
    return 0;
}
