#include<iostream>
using namespace std;
#include <ios> //boolalpha

bool gameWinOrNot(int no_of_bears){
    if(no_of_bears==42){
        return true;
    }
    if(no_of_bears>42){
        if(no_of_bears%2==0){
            return gameWinOrNot(no_of_bears/2);
        }
        else if(no_of_bears%3==0 || no_of_bears%4==0){
            int p=no_of_bears%10;
            int q=(no_of_bears%100)/10;
            return gameWinOrNot(no_of_bears-p*q);
        }
        else if(no_of_bears%5==0){
            return gameWinOrNot(no_of_bears-42);
        }
    }
    return false;
    
}
int main(){
    int no_of_bears;
    cout<<"Enter the number of bears:";
    cin>>no_of_bears;
    
    cout<<"The possibility to left with 42 bears is :"<<boolalpha<<gameWinOrNot(no_of_bears);
    return 0;
}