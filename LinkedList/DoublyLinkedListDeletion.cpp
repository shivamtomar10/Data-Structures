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

DoublyLinkedList* deletion(DoublyLinkedList* head,int value){
    if(head!=NULL){
        DoublyLinkedList* ptr=head;
        while(ptr!=NULL && ptr->data!=value){
            ptr=ptr->next;
        }
        if(ptr==head){
            if(head->next!=NULL){
                head=ptr->next;
                head->prev=NULL;
                delete(ptr);
                return head;
            }
            else{
                head=NULL;
                delete(ptr);
                return head;
            }
        }
        else{
            if(ptr!=NULL){
                ptr->prev->next=ptr->next;
                if(ptr->next!=NULL){
                    ptr->next->prev=ptr->prev;
                    
                }
                return head;
            }
            else{
                cout<<"Element Not found in the list"<<endl;
                return head;
            }
        }
    }
    else{
        cout<<"List is Empty"<<endl;
        return NULL;
    }
}

int main(){
    
   cout<<"This program is used to delete nodes from the list"<<endl;
   
   char ch='y';
   DoublyLinkedList* head=NULL;
   while(ch=='y' || ch=='Y'){
       
       cout<<"1. For adding at the begin"<<endl;
       cout<<"2. For adding at the end "<<endl;
       
       int choice,value;
       cout<<"Enter here:";
       cin>>choice;
       
       switch(choice){
           case 1:
           cout<<"Enter the value of the node for adding at the begin of the list:";
           cin>>value;
           if(head==NULL){
               cout<<"List is empty but we are adding your node at first"<<endl;
               head=new DoublyLinkedList(value);
           }
           else{
               DoublyLinkedList* ptr=new DoublyLinkedList(value);
               ptr->next=head;
               head->prev=ptr;
               head=ptr;
           }
           break;
           
           case 2:
           cout<<"Enter the value of the node for adding at the end of the list:";
           cin>>value;
           
           if(head==NULL){
               cout<<"Your list is empty but we are adding your node at the first"<<endl;
               
               head=new DoublyLinkedList(value);
           }
           else{
               DoublyLinkedList* ptr=head;
               while(ptr->next!=NULL){
                   ptr=ptr->next;
               }
               DoublyLinkedList* t=new DoublyLinkedList(value);
               ptr->next=t;
               t->prev=ptr;
               
           }
           break;
           
           default:
           cout<<"Your operation code is incorrect!"<<endl;
           
       }
       cout<<"Do you want to continue, Enter y or Y for it or press any key to quit "<<endl;
       cout<<"Enter here:";
       cin>>ch;
   }
    printNodeElement(head);
    
   char choice='y';
   while(choice=='y' || choice =='Y'){
       cout<<"Enter the node Element for deletion:";
       int value;
       cin>>value;
       
      head=deletion(head, value);
      
       cout<<"After deletion:"<<endl;
       printNodeElement(head);
       
       
       cout<<"Do you want to continue for deletion, enter y or Y for it or press any key for quit"<<endl;
       cout<<"Enter here:";
       cin>>choice;
   }
    
    return 0;
}
