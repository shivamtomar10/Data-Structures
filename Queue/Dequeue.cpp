#include<iostream>
using namespace std;

// array implementation

static int rear=0,front=0;

void insertionFromRear(int arr[],int data,int size){
    if(rear!=size){
        arr[rear++]=data;
        
    }
    else{
        cout<<"Dequeue is full"<<endl;
    }
}

void insertionFromFront(int arr[],int data,int size){
    if(rear<size){
        for(int i=rear;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=data;
        rear++;
    }
    else{
        cout<<"dequeue is full!"<<endl;
    }
}

void deletionFromRear(int arr[]){
    if(front!=rear){
        arr[rear]=0;
        rear--;
    }
    else{
        cout<<"Dequeue is empty"<<endl;
    }
}

void deletionFromFront(int arr[]){
    if(front!=rear){
        for(int i=0;i<rear;i++){
            arr[i]=arr[i+1];
        }
        rear--;
    }
}

void display(int arr[]){
    if(rear!=front){
        for(int i=0;i<rear;i++){
            cout<<arr[i]<<"<--";

        }

    }
    else{
        cout<<"Nothing to display"<<endl;
    }
}
int main(){

    cout<<"Enter the size of Dequeue:";
    int size;
    cin>>size;

    if(size<=0){
        cout<<"The size of the dequeue cannot be negative and zero:";
    }
    else{
        int dequeue[size]{0};
        char ch='y';
        while(ch=='y' || ch=='Y'){
        cout<<"Enter the opeartion code"<<endl;
        cout<<"1: insert from rear"<<endl;
        cout<<"2: insert from front"<<endl;
        cout<<"3: delete from rear"<<endl;
        cout<<"4: delete from front"<<endl;
        cout<<"5: display of the dequeue"<<endl;
        cout<<"6: exit"<<endl;

        int choice;
        cout<<"Enter the choice:";
        cin>>choice;

        int data;
        switch(choice){
            
            
          
            case 1:
            cout<<"Enter the value for rear insertion:";
            cin>>data;
            insertionFromRear(dequeue,data,size);
            break;
            case 2:
            cout<<"Enter the value for front insertion:";
            cin>>data;
            insertionFromFront(dequeue,data,size);
            break;
            case 3:
            deletionFromRear(dequeue);
            break;
            case 4:
            deletionFromFront(dequeue);
            break;
            case 5:
            display(dequeue);
            break;
            case 6:
            cout<<"Exit"<<endl;
            break;

            default:
            cout<<"Invalid output"<<endl;

        }
        if(choice!=6){
            cout<<"do you want to continue. Enter y or Y for continue or press any key to quit:";
            cin>>ch;
        }
    }
    }
    return 0;
}