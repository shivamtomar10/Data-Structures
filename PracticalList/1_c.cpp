#include<iostream>
using namespace std;
void print(char ch){
    cout<<ch;
    for(int i=65;i<int(ch);i++){
        print(i);
    }
}

void funcLoop(char ch,char ch1='A'){
    for(int i=65;i<=int(ch);i++){
        print(char(i));
    }
}
int main(){

    funcLoop('D');
    return 0;
}