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
    
    cout<<"This program is used to insert elements into the Circular Linked List in sorted order"<<endl;
    cout<<"Enter number of nodes you want to make:";
    int nodes,value,p=1;
    cin>>nodes;
    
    CircularLinkedList* head=NULL;
    while(nodes--){
        cout<<"Enter the value for your "<<p++<<" Node is:";
        int value;
        cin>>value;
        
        if(head==NULL){
            head=new CircularLinkedList(value);
            head->next=head;
        }
        else{
             CircularLinkedList* ptr=head;
             CircularLinkedList* ptr2=NULL;
             while(ptr->data<value && ptr->next!=head){
                 ptr2=ptr;
                 ptr=ptr->next;
             }
            CircularLinkedList* ptr1=new CircularLinkedList(value);
           
             if(ptr->next==head && ptr!=head){
                 if(ptr->next->data<value){
                    ptr->next=ptr1;
                    ptr1->next=head;
                 }
                 else{
                     ptr2->next=ptr1;
                     ptr1->next=ptr;
                 }
                 
             }
             else if(ptr==head){
              
                 ptr1->next=head;
                 
                 while(ptr->next!=head){
                 ptr=ptr->next;
                }
                ptr->next=ptr1;
                head=ptr1;
                
             }
             else{
                 ptr2->next=ptr1;
                 ptr1->next=ptr;
             }
        }
        
    }
    cout<<"Your all Nodes accord to your node number has been made"<<endl;
    printingOfNodes(head);
    return 0;
}
