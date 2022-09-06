#include<iostream>
using namespace std;


void insertionAtBegin(int arr[],int n);
void insertionAtEnd(int arr[],int n);
void insertionAtPosition(int arr[],int n);

void traversalOfArray(int arr[],int n);

int main(){

    try{
        int n;
        cout<<"Enter the size of the array:";
        cin>>n;

        if(n<0){
            throw "Size should not be negative";
        }
        int arr[n+2]{0};

        for(int i=0;i<n;i++){
            cout<<"Enter the element at position"<<i<<":";
            cin>>arr[i];
        }

        cout<<"Enter 1 for inserting element at begin"<<endl;
        cout<<"Enter 2 for inserting element at end"<<endl;
        cout<<"Enter 3 for inserting element at specific position"<<endl;


        int x;
        cout<<"Enter value of choice 1,2 or 3:";
        cin>>x;

        switch(x){


            case 1: 

            insertionAtBegin(arr,n);
            break;

            case 2:

            insertionAtEnd(arr,n);
            break;

            case 3:

            insertionAtPosition(arr,n);
            break;

            default:
            cout<<"Enter value is wrong";
            throw 505;
        }
        traversalOfArray(arr,n);


    }
    catch(string s){
        cout<<s;
    }
    catch(...){
        cout<<"Some error occured";
    }


    return 0;
}


void insertionAtBegin(int arr[],int n){


    cout<<"Enter the element for inserting at begin:";
    int x;
    cin>>x;
    int arr1[n+1];
    arr1[0]=x;
    for(int i=0;i<n;i++){
        arr1[i+1]=arr[i];
    }

    for(int i=0;i<n+1;i++){
        arr[i]=arr1[i];
    }

}

void insertionAtEnd(int arr[],int n){

    cout<<"Enter the elements at the end of the array:";
    int x;
    cin>>x;
    arr[n]=x;

}

void insertionAtPosition(int arr[],int n){


    cout<<"Enter the index of inserting element:";
    int index;
    cin>>index;
    if(index>=0 && index<=n+1){

        cout<<"Enter the element for inserting:";
        int x;
        cin>>x;
        int arr1[n+2];
        for(int i=0;i<index;i++){
            arr1[i]=arr[i];
        }
        arr1[index]=x;
        int j=index;
        for(int i=index+1;j<n;i++){
            arr1[i]=arr[j++];
        }
        for(int i=0;i<n+2;i++){
            arr[i]=arr1[i];
        }


    }
    else {
        cout<<"index cannot be negative";
    }
}

void traversalOfArray(int arr[],int n){

    cout<<"Elements of the Array are:\n";
    for(int i=0;i<n+1;i++){
        cout<<"Element at index"<<i<<"is:"<<arr[i]<<endl;
    }
    
}