#include<iostream>
using namespace std;

class DoublyLinkedList{
    public:
    int data;
    DoublyLinkedList* prev;
    DoublyLinkedList* next;
};


void displayOfNode(DoublyLinkedList* head){
    int p=1;
    while(head!=NULL){
        cout<<"The value of "<<p<<"Node is:"<<head->data<<endl;
        head=head->next;
        p++;
    }
}
void display1(DoublyLinkedList* tail,int p){
    while(tail!=NULL){
        cout<<"The value of "<<--p<<"Node is:"<<tail->data<<endl;
        
        tail=tail->prev;
    }
}
int main(){

    int n;
    cout<<"Enter the number of nodes in Doubly linked list:";
    cin>>n;

    if(n>0){
        DoublyLinkedList* head=new DoublyLinkedList();
        DoublyLinkedList* ptr=head;
        int p=1,data;
        while(n--){
            cout<<"Enter the value of "<<p<<"node:";
            cin>>data;
            ptr->data=data;
           
            if(ptr==head){
                ptr->prev=NULL;
                
            }
            if(n>0){
                DoublyLinkedList* ptr1=new DoublyLinkedList();
                ptr->next=ptr1;
                ptr1->prev=ptr;

                ptr=ptr1;
            }
            p++;
        }

        displayOfNode(head);
        display1(ptr,p);

    }
    else{
        cout<<"The number of node cannot be zero or negative!"<<endl;
    }
    return 0;
}