#include<iostream>
using namespace std;


class DoublyLinkedList{
  public:
  int data;
  
  DoublyLinkedList* next;
  DoublyLinkedList* prev;
  
  DoublyLinkedList(int data){
      this->data=data;
      next=NULL;
      prev=NULL;
      
  }
};

void printNodeElement(DoublyLinkedList* head){
    cout<<"The List Elements are as follows:"<<endl;
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    
    cout<<"This program is to store node elements in sorted fashion in Doubly linkedList"<<endl;
    
    cout<<"How many nodes do you want to make:";
    int node_number,p=1;
    cin>>node_number;
    
    DoublyLinkedList* head=NULL;
    while(node_number--){
        int value;
        cout<<"Enter the value of "<<p++<<" Node is:";
        cin>>value;
        if(head==NULL){
            head=new DoublyLinkedList(value);
        }
        else{
            DoublyLinkedList* ptr=head;
            DoublyLinkedList* ptr2=NULL;
            while(ptr!=NULL && ptr->data<value){
                ptr2=ptr;
                ptr=ptr->next;
            }
            
            if(ptr==head){
                DoublyLinkedList* ptr1=new DoublyLinkedList(value);
                ptr1->next=ptr;
                ptr->prev=ptr1;
                head=ptr1;
            }
            else{
                if(ptr!=NULL){
                    DoublyLinkedList* ptr1=new DoublyLinkedList(value);
                    ptr->prev->next=ptr1;
                    ptr1->prev=ptr->prev;
                    ptr1->next=ptr;
                    ptr->prev=ptr1;
                    
                }
                else{
                    DoublyLinkedList* ptr1=new DoublyLinkedList(value);
                    ptr2->next=ptr1;
                    ptr1->prev=ptr2;
                }
            }
        }
    }
    
    printNodeElement(head);
    return 0;
}
