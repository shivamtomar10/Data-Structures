#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n);
void insertionSort(int arr[],int n);
void mergeSort(int arr[],int n);
void selectionSort(int arr[],int n);
void printOfArray(int arr[],int n);
void insertionMethod(int arr[],int n,int pos,int element,int posofelement);

int main(){

    try{
        int n;
        cout<<"Enter the size of the array:";
        cin>>n;

        if(n<=0){
            throw "size of the array cannot be negative or zero!";
        }
        int arr[n];
        cout<<"Enter the elements in the array\n";
        for(int i=0;i<n;i++){
            cout<<"Enter the elements at the index"<<i<<":";
            cin>>arr[i];
        }

        // bubbleSort(arr,n);
        // printOfArray(arr,n);
        insertionSort(arr,n);
        printOfArray(arr,n);
        // mergeSort(arr,n);
        // printOfArray(arr,n);
        // selectionSort(arr,n);
        // printOfArray(arr,n);


    }
    catch(string s){
        cout<<s<<endl;
    }
    catch(...){
        cout<<"some error of inputmismatch occured!";
    }
    

    return 0;
}

void printOfArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"Elements found at index "<<i<<"is:"<<arr[i]<<endl;
    }
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[],int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                insertionMethod(arr,n,j-1,arr[i],i);
            }
        }
    }
}
void insertionMethod(int arr[],int n,int pos,int element,int posofelement){
    int arr1[n+2]{0};
    for(int i=0;i<pos;i++){
        arr1[i]=arr[i];
    }
    arr1[pos]=element;
    
    for(int i=pos+1;posofelement<n;i++){
        arr1[i]=arr[posofelement++];
    }


    for(int i=0;i<n;i++){
        arr[i]=arr1[i];
    }
}