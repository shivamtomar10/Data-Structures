/*This Program is of circular LinkedList Inserion At begin and end */

#include<iostream>
using namespace std;

class CircularLinkedList{
  public:
  int data;
  CircularLinkedList* next;
  
  
  CircularLinkedList(int data){
      this->data=data;
      next=NULL;
  }
};

CircularLinkedList* addAtBegin(CircularLinkedList* head,int data){
    if(head==NULL){
        head=new CircularLinkedList(data);
        head->next=head;
        cout<<"Insertion at Begin Successful"<<endl;
        return head;
    }
    else{
        CircularLinkedList* ptr=new CircularLinkedList(data);
        ptr->next=head;
        CircularLinkedList* ptr1=head;
        while(ptr1->next!=head){
            ptr1=ptr1->next;
        }
        ptr1->next=ptr;
        
        cout<<"Insertion at Begin Successful"<<endl;
        return ptr;
    }
}

CircularLinkedList* addAtEnd(CircularLinkedList* head, int data){
    if(head==NULL){
        cout<<"However List is Empty but we are adding your node at first"<<endl;
        head=new CircularLinkedList(data);
        head->next=head;
        cout<<"Insertion at end Successful"<<endl;
    }
    else{
        CircularLinkedList* ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        CircularLinkedList* ptr1=new CircularLinkedList(data);
        ptr->next=ptr1;
        ptr1->next=head;
        cout<<"Insertion at end Successful"<<endl;
    }
    return head;
}


void printingOfNodes(CircularLinkedList* head){
    cout<<"List Elements are as follows:"<<endl;
    if(head==NULL){
        cout<<"List Is empty"<<endl;
    }
    else{
        CircularLinkedList* ptr=head;
    do{
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }while(ptr!=head);
        cout<<"NULL"<<endl;
    }
}
int main(){
    
    
    cout<<"This program is to insertion of the nodes  at the begin or at the end , fashion into the Circular LinkedList"<<endl;
    
    cout<<"Enter the number of nodes you want to make:";
    int nodes,p=1;
    cin>>nodes;
    
    CircularLinkedList* head=NULL;
    
    while(nodes--){
        
        cout<<"1. For adding at begin"<<endl;
        cout<<"2.For adding at end"<<endl;
        
        int operation,value;
        cout<<"Enter the operation 1 or 2:";
        cin>>operation;
        switch(operation){
            case 1:
                cout<<"Enter the value for the "<<p++<<" insertion at begin is:";
                cin>>value;
                head=addAtBegin(head,value);
                // printingOfNodes(head);
            break;
            case 2:
                cout<<"Enter the value for "<<p++<<" insertion at end is:";
                cin>>value;
                head=addAtEnd(head,value);
                // printingOfNodes(head);
            break;
            
            default:
            cout<<"Your Operation is invalid!"<<endl;
            nodes++;
            
        }
        
        
    }
    cout<<"Your all Nodes accord to your node number has been made"<<endl;
    printingOfNodes(head);
    return 0;
}
    
