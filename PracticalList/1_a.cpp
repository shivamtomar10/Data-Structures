#include<iostream>
using namespace std;

void patternPrinting(int max,int min){
    int p=min;
    int no_of_lines=2*(max-min+1);
    for(int i=1;i<=no_of_lines;i++){
        for(int j=0;j<min && min<=max;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
        min++;
        if(min>max){
            for(int k=0;k<max && max>=p;k++){
                cout<<"*"<<" ";
            }
            max--;
        }
    }

    //2 method

    // for(int i=0;i<no_of_lines/2;i++){
    //     for(int j=0;j<min;j++){
    //         cout<<"*"<<" ";
    //     }
    //     min++;
    //     cout<<endl;
    // }

    // for(int i=0;i<no_of_lines/2;i++){
    //     for(int j=0;j<max;j++){
    //         cout<<"*"<<" ";
    //     }
    //     max--;
    //     cout<<endl;
    // }
}
int main(){
    
    int n,m;
    cout<<"Enter the number of asterisks(m's value) you want in your first line of your pattern:";
    cin>>m;
    cout<<"Enter the max. number of asterisks(n's value) you want in your pattern :";
    cin>>n;
    if(n>=m){
    cout<<"Your Pattern is :"<<endl;
    patternPrinting(n,m);
    }
    else{
        cout<<"Max(n's value) value Cannot Be Smaller than first line asteriks value(m's value) "<<endl;
    }
    return 0;
}