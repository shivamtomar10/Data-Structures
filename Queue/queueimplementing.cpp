#include<iostream>
using namespace std;

static int rear=0,front=0;
class LinkedList{
    public:
    int data;
    LinkedList* next;
};

void makingOfNode(LinkedList* ptr,int data){
    ptr->data=data;
    ptr->next=NULL;
}


LinkedList* insertingOfNode(int data,int capacity){
    if(rear!=capacity){
        LinkedList* ptr=new LinkedList();
        makingOfNode(ptr,data);
        rear++;
        return ptr;
    }
    else{
        cout<<"Queue is FUll"<<endl;
        return NULL;
    }
}

LinkedList* deletionOfNode(LinkedList* head){
    if(front==rear){
        cout<<"Queue is Empty!"<<endl;
    }
    else{
        head=head->next;
        cout<<"Deletion happen"<<endl;
        return head;
    }
    return NULL;
}
void displayOfNode(LinkedList* head){
    while(head!=NULL){
        cout<<head->data<<"<--";
        head=head->next;
    }
    
}
int main(){

    cout<<"Enter the capacity for your queue:";
    int capacity;
    cin>>capacity;

    char ch='y';
    int p=1;
    LinkedList* head=NULL;
    LinkedList* ptr1=NULL;
    LinkedList* ptr2=NULL;
    while(ch=='y' || ch=='Y'){
    cout<<"Enter the choice 1 for insert 2 for delete 3 for display 4 for exit:";
    int choice ;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter the value for entering into the queue:";
        int data;
        cin>>data;

        if(p==1){
            head=insertingOfNode(data,capacity);
            // cout<<1<<endl;
            ptr1=head;
            ptr2=head;
            p++;
        } 
        else{

        LinkedList* ptr=insertingOfNode(data,capacity);

        ptr1->next=ptr;

        ptr1=ptr;
        }

        break;
        case 2:
        ptr2=deletionOfNode(head);
        head=ptr2;
        break;
        case 3:
        if(ptr2!=NULL){
        displayOfNode(head);
        }
        else{
            cout<<"Nothing to display!"<<endl;
        }
        break;
        case 4:
        cout<<"Exit"<<endl;
        break;
        default:
        cout<<"Invalid choice"<<endl;
    }
    if(choice!=4){
    cout<<"Do you want to continue. Enter y or Y for it else press any to quit:";
    cin>>ch;
    }
    else{
        ch='n';
    }
    }
     return 0;
}