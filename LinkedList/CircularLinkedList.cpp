#include<iostream>
using namespace std;

class CircularDoublyLinkedList{
    public:
    int data;
    CircularDoublyLinkedList* prev;
    CircularDoublyLinkedList* next;
};

class CircularSinglyLinkedList{
    public:
    int data;
    CircularSinglyLinkedList* next;
};

void displayOfNode(CircularDoublyLinkedList* head){
    CircularDoublyLinkedList* ptr=head;
    int p=1;
    while(head!=NULL && p<=4){
        cout<<p<<" : "<<head<<endl;
        // cout<<"The value of "<<p<<" Node is:"<<head->data<<endl;
        p++;
        head=head->next;
    }
    cout<<"head last:"<<head<<endl;

}
void displayOfNode(CircularSinglyLinkedList* head){
    int p=1;
    while(head!=NULL && p<=4){
        cout<<"Node is:"<<head<<endl;
        head=head->next;p++;
    }
}
int main(){

    int n;
    cout<<"Enter the number of nodes in the circular linked list:";
    cin>>n;

    if(n>0){
        int p=1,data,q=n;
        CircularDoublyLinkedList* head= new CircularDoublyLinkedList();
        CircularDoublyLinkedList* ptr=head;
        while(n--){
            cout<<"Enter the value of "<<p++<<"Node is:";
            cin>>data;
            ptr->data=data;

            if(ptr==head){
                ptr->prev=NULL;
            }

            if(n>0){

                CircularDoublyLinkedList* ptr1=new CircularDoublyLinkedList();
                ptr->next=ptr1;
                ptr1->prev=ptr;
                ptr=ptr1;
            }
            if(n==1){
                ptr->next=head;
                head->prev=ptr;

            }
            
        }
        displayOfNode(head);

            CircularSinglyLinkedList* head1=new CircularSinglyLinkedList();
            CircularSinglyLinkedList* ptr2=head1;
            int h=1,data1;

        while(q--){
            cout<<"Enter the value"<<h<<"Node is:";
            cin>>data1;
            ptr2->data=data1;
            if(q>0){
                CircularSinglyLinkedList* ptr1=new CircularSinglyLinkedList();
                ptr2->next=ptr1;
                ptr2=ptr1;
            }
            if(q==1){
                ptr2->next=head1;
            }

        }
        displayOfNode(head1);


    }
    else{
        cout<<"The number od nodes in Linked List cannot be zero or negative!"<<endl;
    }

    return 0;
}