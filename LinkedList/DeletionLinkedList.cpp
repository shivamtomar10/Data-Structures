#include<iostream>
using namespace std;

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
    cout<<"List Elements are as follows:"<<endl;
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    
    cout<<"Until you press -1, Nodes will be making for you and connected in that order only"<<endl;
    int ch=0,value,p=1,val_del;
    
    Node* head=NULL;
    while(ch!=-1){
        cout<<"Enter the value for the "<<p++<<" Node is:";
        cin>>value;
        if(head==NULL){
            head=new Node(value);
        }
        else{
            Node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new Node(value);
        }
        
        cout<<"If You want to add more node, press any integer except -1:";
        cin>>ch;
    }
    
    cout<<"This program is to delete all nodes of the value mention by user for deletion of that value from the linked list"<<endl;
    
    cout<<"Enter the value for deletion:";
    cin>>val_del;
    
    Node* ptr=head;
    p=1;
    while(ptr!=NULL){
        Node* ptr1=NULL;
        while(ptr!=NULL && ptr->data!=val_del){
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL && p==1){
            cout<<"No data match in the linked List"<<endl;
        }
        if(ptr1!=NULL && ptr!=NULL){
            ptr1->next=ptr->next;
            delete(ptr);
            ptr=ptr1->next;
        }
        else if(ptr1==NULL){
            head=head->next;
            delete(ptr);
            ptr=head;
        }
        p++;
        
        
    }
    
    printNodeElements(head);
    return 0;
}
