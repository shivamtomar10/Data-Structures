#include<iostream>
using  namespace std;

static int rear=0,front=0;
void insertionOfData(int arr[],int data,int size){
    if(rear!=size){
        arr[rear]=data;
        rear++;
    }
    else{
        cout<<"queue is full!"<<endl;
    }
}

void deletingOfData(int arr[]){
    if(front!=rear){
        for(int i=0;i<rear;i++){
            arr[i]=arr[i+1];
        }
        rear--;
    }
    else{
        cout<<"queue is empty!"<<endl;
    }
}

void display(int arr[]){
    if(rear!=front){
        for(int i=0;i<rear;i++){
            cout<<arr[i]<<"<--";
        }
    }
    else{
        cout<<"Nothing to display!"<<endl;
    }
}
int main(){

    cout<<"Enter the size of the queue:";
    int size;
    cin>>size;
    if(size<=0){
        cout<<"The size cannot be negative or zero!"<<endl;
    }
    else{
    int queue[size]; 
    char ch='y';
    while(ch=='y' || ch=='Y'){
    cout<<"Enter the operation you want to perform"<<endl;
    cout<<" 1 for insert"<<endl;            
    cout<<" 2 for delete"<<endl;                
    cout<<" 3 for display"<<endl;            
    cout<<" 4 for exit"<<endl;      

    cout<<"Enter the Choice:";
    int choice;
    cin>>choice;

    switch(choice){
        case 1:
        cout<<"Enter the data for insertion:";
        int data;
        cin>>data;
        insertionOfData(queue,data,size);

        break;
        case 2:
        deletingOfData(queue);
        break;
        case 3:
        display(queue);
        break;
        case 4:
        cout<<"Exit"<<endl;
        break;

    }     
    if(choice!=4){      
    cout<<"Do you want to continue. Enter y or Y for continue or press any key to quit:";
    cin>>ch;
    }
    else{
        ch='n';
    }
    }
    }
    return 0;
}