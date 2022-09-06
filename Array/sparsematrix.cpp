#include<iostream>
using namespace std;





int main(){

    int r,c;
    cout<<"Enter the row and column for the sparse matrix"<<endl;
    cout<<"Enter the row:";
    cin>>r;
    cout<<"Enter the column:";
    cin>>c;

    if(r>0 && c>0 ){
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter the element at positions["<<i<<"]["<<j<<"] is:";
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"The elements at the position ["<<i<<"]["<<j<<"] is:"<<arr[i][j]<<endl;
        }
    }
    int countofrows=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0){
                countofrows++;
            }
        }
    }
    int t=0,p=0;
    int arrnew[countofrows][3];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0){
                arrnew[t][p]=i;
                arrnew[t][p+1]=j;
                arrnew[t][p+2]=arr[i][j];
                t++;
            }
        }
    }

    //printing of the matrix after removing zeros
    cout<<"After making new matrix"<<endl;
    for(int i=0;i<countofrows;i++){
        for(int j=0;j<3;j++){
            cout<<"The elements at the position ["<<i<<"]["<<j<<"] is:"<<arrnew[i][j]<<endl;
        }
    }

    }
    else{
        cout<<"Row or column shouldnot be zero or negative!"<<endl;
    }
    return 0;
}