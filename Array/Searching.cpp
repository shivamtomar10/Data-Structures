#include<iostream>
using namespace std;


int linearSearch(int arr[],int n,int s);
int binarySearch(int arr[],int start,int end,int s);

int main(){

    try{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;

    if(n<=0){
        throw "size shouldnot be zero or negative!";
    }

    int arr[n];
    cout<<"Enter the values into the array"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the value at position "<<i<<":";
        cin>>arr[i];
    }


    cout<<"Enter the element for the search:";
    int search;
    cin>>search;

    int linear_result=linearSearch(arr,n,search);
    int binary_result=binarySearch(arr,0,n-1,search);

    if(linear_result>=0){

        cout<<"The linearSearch result is that value found at position (index of the array)"<<linear_result<<endl;
    }
    else{
        cout<<"The element not found during linearsearch"<<endl;
    }

    if(binary_result>=0){
        cout<<"The BinarySearch result is that value found at position (index of the array)"<<binary_result<<endl;
    }
    else{
        cout<<"The element not found during binarysearch"<<endl;
    }

    }
    catch(string d){
        cout<<d<<endl;
    }
    catch(...){
        cout<<"Some Inputmismatch error occured!";
    }


    return 0;
}

int linearSearch(int arr[],int n,int s){

    for(int i=0;i<n;i++){
        if(arr[i]==s){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int start,int end,int s){

    int mid;
    if(start<=end){
        mid=(start+end)/2;
    }

    if(arr[mid]==s){
        return mid;
    }

    else if(arr[mid]>s){
        return binarySearch(arr,start,mid-1,s);
    }

    else if(arr[mid]<s){
        return binarySearch(arr,mid+1,end,s);
    }

    return -1;
}