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

// printing Node Elements
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
    
    cout<<"This program is to add Nodes values in sort order"<<endl;
    cout<<"Until You press -1 this will ask you for new node value for inserting into the list "<<endl;
    int choice;
    cout<<"Press 0 for node making or -1 for against it:";
    cin>>choice;
    int p=1;
    
    Node* head=NULL;
    while(choice==0){
        int value;
        cout<<"Enter the value for the "<<p++<<" node is:";
        cin>>value;
        
        if(head==NULL){
            head=new Node(value);
        }
        else{
            Node* ptr=head;
            Node* ptr1=NULL;
            while(ptr!=NULL && ptr->data<value  ){
                ptr1=ptr;
                ptr=ptr->next;
            }
            if(ptr1!=NULL){
                ptr1->next=new Node(value);
                ptr1->next->next=ptr;
            }
            else{
                head=new Node(value);
                head->next=ptr;
            }
        }
        
        cout<<"Enter -1(for exit) or 0(making Nodes):";
        cin>>choice;
    }
    cout<<"The List Elements are as follows:"<<endl;
    printNodeElements(head);
    
    return 0;
}
