#include<iostream>
using namespace std;



class LinkedList{
    public:
    int data;
    LinkedList* next;
};

// void makingOfNode(LinkedList* node,int value){
//     node->data=value;
//     node->next=NULL;
// }

void displayOfLinkedList(LinkedList* node){
    
    int p=1;
    while(node!=NULL){
        cout<<"The element of "<<p<<"node"<<node->data<<endl;
        p++;
        node=node->next;
    }
}

int main(){

    int n;
    cout<<"Enter the number of nodes you want to make:";
    cin>>n;

    if(n<=0){
        cout<<"The nodes cannot be negative or zero"<<endl;
    }
    else{
        int p=1,data;
        LinkedList* head=new LinkedList();
        LinkedList* ptr=head;
        while(n--){
            cout<<"Enter the value of "<<p<<" node:";
            cin>>data;
            ptr->data=data;

            if(n>0){
                LinkedList* ptr1=new LinkedList();
                ptr->next=ptr1;
                ptr=ptr1;
            }
            p++;
        }

        displayOfLinkedList(head);

    }

       
    
    return 0;
}