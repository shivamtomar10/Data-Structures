#include<iostream>
using namespace std;

static int rear=0,front=0;

class LinkedListDequeue{
    public:
    int data;
    LinkedListDequeue* next;
};

void makingOfNode(LinkedListDequeue* ptr,int datavalue){
    if(ptr!=NULL){
        ptr->data=datavalue;
        ptr->next=NULL;
        
        rear++;
    }
    else{
        cout<<"The Pointer of node is pointing to NULL"<<endl;
        
    }
}

LinkedListDequeue* insertingFromFront(LinkedListDequeue* ptr,int data,int size,LinkedListDequeue* head){
    if(rear!=size && ptr!=head){
        makingOfNode(ptr,data);
        ptr->next=head;
        return ptr;
        

    }
    else{
        cout<<"Dequeue is full!"<<endl;
        return NULL;
    }
}

void insertingFromRear(LinkedListDequeue* ptr,int data,int size,LinkedListDequeue* head){
    if(rear!=size && ptr!=head){
        makingOfNode(ptr,data);
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=ptr;

    }
    else{
        cout<<"Dequeue is Full!"<<endl;
    }
}

LinkedListDequeue* deletingFromFront(LinkedListDequeue* head){
    if(head!=NULL && rear!=front){
    head=head->next;
    rear--;
    return head;
    }
    else{
        cout<<"There is nothing to delete"<<endl;
        return NULL;
    }
}

void deletingFromRear(LinkedListDequeue* head){
    if(head!=NULL && rear!=front){
    while(head->next->next!=NULL){
        head=head->next;
    }
    head->next=NULL;
    rear--;
    }
    else{
        cout<<"There is nothing to display!"<<endl;
    }
}

void displayOfdequeue(LinkedListDequeue* head){
    if(head!=NULL){
    while(head!=NULL){
        cout<<head->data<<"<--";
        head=head->next;
    }
    }
    else{
        cout<<"Nothing to display!"<<endl;
    }
}

int main(){


    cout<<"Enter size of the dequeue:";
    int size;
    cin>>size;
    if(size<=0){
        cout<<"The size cannot be zero or negative!"<<endl;
    }
    else{

    
    char ch='y';
    int p=1;
    LinkedListDequeue* head=new LinkedListDequeue();
    LinkedListDequeue* head1=NULL;
    // LinkedListDequeue* head2=NULL;
    while(ch=='y' || ch=='Y'){
    cout<<"1. inserting from rear"<<endl;
    cout<<"2. inserting from front"<<endl;
    cout<<"3. deleting from rear"<<endl;
    cout<<"4. deleting form front"<<endl;
    cout<<"5. display of the dequeue"<<endl;
    cout<<"6. exit"<<endl;




    cout<<"Enter the choice:";
    int choice;
    cin>>choice;

    int data=0;
    switch(choice){
        case 1:
        cout<<"Enter the data for the rear insertion:";
        cin>>data;
        if(p==1){
        head->data=data;
        head->next=NULL;
        p++;
        }
        else{
            LinkedListDequeue* ptr=new LinkedListDequeue();
            insertingFromRear(ptr,data,size,head);
        }

        break;

        case 2:
        cout<<"Enter the data for the front insertion:";
        cin>>data;
        if(p==1){
        head->data=data;
        head->next=NULL;   
        
        p++;
        }
        else{
            LinkedListDequeue* ptr=new LinkedListDequeue();
            if(head1==NULL){
            head1=insertingFromFront(ptr,data,size,head);

            }
            else{
                head1=insertingFromFront(ptr,data,size,head1);
            }
            
        }
        break;

        case 3:
       
        deletingFromRear(head);
        break;

        case 4:
        if(head1==NULL){
        head1=deletingFromFront(head);
        }
        else{
            head1=deletingFromFront(head1);
        }
        break;

        case 5:
        if(head1==NULL){
        displayOfdequeue(head);
        }
        else{
            displayOfdequeue(head1);
        }
        break;

        case 6:
        cout<<"Exit"<<endl;
        break;
    }
    if(choice!=6){
        cout<<"Do you want to continue. Enter Y or y for it or press any key to quit:";
        cin>>ch;
    }
    else{
        ch='n';
    }
    
    }
    }
    return 0;
}