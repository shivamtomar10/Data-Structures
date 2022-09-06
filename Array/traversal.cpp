#include<iostream>
using namespace std;
// #include<stdexcept>

void printElementOfArray(int arr[],int n);
int TraversalOfArray(int arr[],int n,int x);

int main(){

    exception obj1;
    try{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    if(n<=0){
        throw ("Either the entered size is negative or zero");
    }
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the element at position "<<i<<":";
        try{
        cin>>arr[i];

        }
        catch(...){
            cout<<"error in input";
        }
    }

    int x;
    cout<<"\nEnter the element to be search:";
    cin>>x;

    int returnValue=TraversalOfArray(arr,n,x);
    if(returnValue==-1){
        cout<<"Entered value is not there in the Array";
    }
    else{
        cout<<"The value is found ay index in Array at position:"<<returnValue;
    }


    //printing elemeny=ts of the array
    printElementOfArray(arr,n);
    }
    catch(string e){
        cout<<e;
    }
    catch(...){
        cout<<"some inputmismatch error is there";
    }



    return 0;
}
// printing the array
void printElementOfArray(int arr [],int n){
    
    cout<<"\nThe element of the array are:\n";
    for(int h=0;h<n;h++){
        cout<<"The element at position is:"<<arr[h]<<endl;
    }
    
}

int TraversalOfArray(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }

    }
    return -1;
}