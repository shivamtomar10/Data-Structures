#include<iostream>
using namespace std;

static int rear=-1;

class Priorityqueue{
    public:
    int data;
    int priority;
};

void insertionOfData(int data,int priority,Priorityqueue arr[],int size){
    
    if(rear<size){
        rear++;
        arr[rear].data=data;
        arr[rear].priority=priority;
    }
    else{
        cout<<"Priorityqueue is full!"<<endl;
    }

}

int peek(Priorityqueue arr[]){
    int highestprior=INT_MIN;
    int ind=-1;
    for(int i=0;i<=rear;i++){
        if(highestprior<arr[i].priority && ind>-1 && arr[ind].data<arr[i].data){
            highestprior=arr[i].priority;
            ind=i;
        }
        else if(highestprior<arr[i].priority){
            highestprior=arr[i].priority;
            ind=i;
        }
        
    }
    return ind;
}

void deletionOfData(Priorityqueue arr[]){

    int ind=peek(arr);

    for(int i=ind;i<rear;i++){
        arr[i]=arr[i+1];
    }
    rear--;
}

void display(Priorityqueue arr[]){
    for(int i=0;i<=rear;i++){
        cout<<arr[i].data<<"<--";
    }

}
int main(){

    cout<<"Enter the size of the priorityqueue:";
    int size;
    cin>>size;

    if(size<=0){
        cout<<"Size of queue cannot be negative or zero!"<<endl;
    }
    else{

        Priorityqueue prio_queue[size];

        char ch='y';
        while(ch=='y' || ch=='Y'){
        cout<<"Enter 1 for insertion into priortiyqueue"<<endl;
        cout<<"Enter 2 for deletion into priorityqueue"<<endl;
        cout<<"Enter 3 for display of priorityqueue"<<endl;
        cout<<"Enter 4 for exit "<<endl;
        
        cout<<"Enter the choice:"<<endl; 
        int choice ;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter the data:";
            int data;
            cin>>data;

            cout<<"Enter data's priority:";
            int prior;
            cin>>prior;

            insertionOfData(data,prior,prio_queue,size);

            break;
            case 2:

            deletionOfData(prio_queue);
            break;
            case 3:
            display(prio_queue);
            break;
            case 4:
            cout<<"Exit"<<endl;
            break;

            default:
            cout<<"Invalid output"<<endl;

        }

        if(choice!=4){
            cout<<"Do you want to continue. Enter y or Y for it or press any other key to quit! :"<<endl;
            cin>>ch;
        }
        else{
            ch='n';
        }
        
        }    

    }

    return 0;
}