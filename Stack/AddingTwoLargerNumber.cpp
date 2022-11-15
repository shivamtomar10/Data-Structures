#include<iostream>
using namespace std;

class Stack{
  public:
  int top=-1,carry_indication=0;
  int arr[100]{0};
  
  void addIntoStack(int data){
      arr[++top]=data;
  }
  void printData(){
      while(top>=0){
          cout<<arr[top];
          top--;
      }
  }
  
  void addition(int n1,int n2){
      int sum=0;
      
     if(carry_indication==0){
         sum=arr[top]+arr[top-1];
         top-=2;
     }
     else{
         if(n1>0 && n2>0){
            sum=arr[top]+arr[top-1]+arr[top-2];
            top-=3;
         }
         else{
            sum=arr[top]+arr[top-1];
            top-=2;
         }
         carry_indication=0;
     }
     
     if(sum>=10){
         arr[++top]=sum%10;
         arr[++top]=sum/10;
         carry_indication=1;
     }
     else{
         arr[++top]=sum;
     }
  }
  
};



int main(){
    Stack obj1;
    int n1,n2;
    cout<<"Enter the first number:";
    cin>>n1;
    cout<<"Enter the second number:";
    cin>>n2;
    
    while(n1>0 && n2>0){
        obj1.addIntoStack(n1%10);
        obj1.addIntoStack(n2%10);
        obj1.addition(n1,n2);
        n1=n1/10;
        n2=n2/10;
    }
    
    while(n1>0){
        obj1.addIntoStack(n1%10);
        obj1.addition(n1,n2);
        n1=n1/10;
    }
    while(n2>0){
        obj1.addIntoStack(n2%10);
        obj1.addition(n1,n2);
        n2=n2/10;
    }
    
    obj1.printData();
    return 0;
}
