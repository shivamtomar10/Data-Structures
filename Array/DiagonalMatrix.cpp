#include<iostream>
using namespace std;


class DiagonalMatrix{
  
  public:
  int rows,column;
  int* arr=new int[rows];
  
  int get(int i,int j);
  void set(int i,int j,int value);
};


int DiagonalMatrix :: get(int i,int j){
    if(i==j && i>=0 && j>=0){
        return arr[i];
        
    }
    else if(i>=0 && j>=0){
        return 0;
    }
    else{
        return -1;
    }
}

void  DiagonalMatrix :: set(int i,int j, int value){
        arr[i]=value;
        cout<<"Value has been set"<<endl;
}
int main(){
    
    DiagonalMatrix obj1;
    cout<<"This Program is for special sparse matrix for diagonal matrix category"<<endl;
    cout<<"Enter the dimensions of the diagonal matrix"<<endl;
    cout<<"NOTE: Rows and Column should be same for Diagonal Matrix"<<endl;
    cout<<"We here taking both values from user (rows, column) and expected to be them as same "<<endl;
    
    
    cout<<"Enter the rows:";
    cin>>obj1.rows;
    
    cout<<"Enter the column:";
    cin>>obj1.column;
    
    int arr1[obj1.rows][obj1.column],p=0;
    
    for(int i=0;i<obj1.rows;i++){
        for(int j=0;j<obj1.column;j++){
            cout<<"Enter the value at index ["<<i<<"]["<<j<<"]:";
            cin>>arr1[i][j];
            if(arr1[i][j]!=0){
                obj1.arr[p++]=arr1[i][j];
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
          cout<<"The index out of bound exception!"<<endl;
        }
        break;
        case 2:
        cout<<"Enter the i index:";
        cin>>i;
        cout<<"Enter the j index:";
        cin>>j;
        if(i<=obj1.rows && j<=obj1.column){
        if(i==j && i>=0 && j>=0){
            cout<<"Enter the value for changing at["<<i<<"]["<<j<<"]:";
            cin>>value;
            obj1.set(i,j,value);
        }
        else{
            cout<<"The specified index for changing value in matrix is invalid! "<<endl;
            cout<<"Please Enter both i and j index as equal and greater than zero for diagonal matrix property"<<endl;
        }
        }
        else{
          cout<<"The index out of bound exception!"<<endl;
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
