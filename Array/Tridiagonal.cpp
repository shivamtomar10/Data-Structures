#include<iostream>
using namespace std;


class Tridiagonal{
  public:
  int rows,column,set_length;
  int *arr=new int[set_length];
  
  int get(int i,int j);
  void set(int i,int j,int value);
    
};

int Tridiagonal :: get(int i,int j){
    if((2*i+j)<=set_length && i>=0 && j>=0){
        return arr[2*i+j];
    }
    else if(i>=0 && j>=0){
        return 0;
    }
    else{
        return -1;
    }
}
void  Tridiagonal :: set(int i,int j,int value){
    arr[2*i+j]=value;
    cout<<"Value has been set "<<endl;
}
int main(){
    Tridiagonal obj1;
    cout<<"This program is of Tridiagonal matrix (sparse type)"<<endl;
    cout<<"Enter the dimnesions of the matrix we are expecting same rows and column from user"<<endl;
    
    cout<<"Enter the rows:";
    cin>>obj1.rows;
    
    cout<<"Enter the column:";
    cin>>obj1.column;
    
    obj1.set_length=(3*obj1.rows)-2;
    int arr[obj1.rows][obj1.column],p=0;
    for(int i=0;i<obj1.rows;i++){
        for(int j=0;j<obj1.column;j++){
            cout<<"Enter the value at the index["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
            if(arr[i][j]!=0){
                obj1.arr[p++]=arr[i][j];
            }
        }
    }
    
    char ch='y';
    while(ch=='y'|| ch=='Y'){
    int choice,i,j,get,value;
    cout<<"Enter the operational code as mention Below:"<<endl;
    cout<<"1. For getting values from matrix"<<endl;
    cout<<"2 .For setting values in matrix"<<endl;
    
    cout<<"Enter your choice here:";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter the i index:";
        cin>>i;
        cout<<"Enter the j index:";
        cin>>j;
        if(i<=obj1.rows && j<=obj1.column){
        get=obj1.get(i,j);
        if(get!=-1){
        cout<<"The value at your specified index is:"<<get<<endl;
        }
        else{
          cout<<"Negative index are not allowed!"<<endl;
        }
        }
        else{
            cout<<"Index out of bound Exception!"<<endl;
        }
        break;
        case 2:
        cout<<"Enter the i index:";
        cin>>i;
        cout<<"Enter the j index:";
        cin>>j;
        if(i<=obj1.rows && j<=obj1.column){
        if((2*i+j)<=obj1.set_length && i>=0 && j>=0){
            cout<<"Enter the value for changing at["<<i<<"]["<<j<<"]:";
            cin>>value;
            obj1.set(i,j,value);
        }
        else{
            cout<<"The specified index for changing value in matrix is invalid! "<<endl;
            cout<<"Please Enter both i and j index as to get at one of its position at any of the three diagonal for Tridiagonal matrix property"<<endl;
        }
        }
        else{
            cout<<"Index out of bound Exception!"<<endl;
        }
        break;
        default:
        cout<<"Operation code is invalid!"<<endl;
        
    }
    cout<<"Do you want to continue.Enter y or Y for it, or press any key to quit:";
    cin>>ch;
    }
    
    return 0;
}
