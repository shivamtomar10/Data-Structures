#include<iostream>
using namespace std;

class Stack{
  public:
  int top=-1;
  int* arr=new int[100]; 
  
  void push(int val){
      if(top+1<100){
          arr[++top]=val;
          cout<<"Insertion in Stack Successfull"<<endl;
      }
      else{
          cout<<"Insertion is Stack is not Succesfull"<<endl;
      }
  }
  
  int pop(){
      if(top!=-1){
          int t=arr[top];
          top--;
          cout<<"Deletion from Stack is Successfull"<<endl;
          return t; 
          
      }
      else{
          cout<<"Deletion from Stack is not Successfull"<<endl;
           return -1;
      }
  }
  
//   void printingStack(){
//       cout<<"Stack Elements are as follows:"<<endl;
//       for(int i=0;i<=top;i++){
//           cout<<arr[top]<<" ";
//       }
//       cout<<endl;
//   }
}st;

class Q1{
  public:
  int front=-1,rear=-1;
  int* arr=new int[100];
  void enqueue(int val){
      if(rear+1<100){
          arr[++rear]=val;
          if(front==-1){
              front++;
          }
        //   cout<<"Enqueue at Q1 is Successfull"<<endl;
          
      }
    //   else{
        //   cout<<"Enqueue at Q1 is not Successfull"<<endl;
    //   }
      
  }
  
  int dequeue(){
      
      if(rear!=-1){
          int t=arr[front];
          for(int i=0;i<rear;i++){
              arr[i]=arr[i+1];
          }
          rear--;
          cout<<"Dequeue from Q1 is Successfull"<<endl;
          if(rear==-1){
              front=-1;
          }
          return t;
      }
      else{
          cout<<"Dequeue from Q1 is not Successfull"<<endl;
          return -1;
      }
      
  }
//   void printingQueueQ1(){
//       cout<<"The Q1 elements are as follows:"<<endl;
//       for(int i=0;i<=rear;i++){
//           cout<<arr[i]<<" ";
//       }
//       cout<<endl;
//   }

    
  
}q1;

class Q2{
    public:
     int front=-1,rear=-1;
    int* arr=new int[100];
    void enqueue(int val){
        if(rear+1<100){
            arr[++rear]=val;
            if(front==-1){
                front++;
            }
            cout<<"Enqueue at Q2 is Successfull"<<endl;
          
        }
        else{
            cout<<"Enqueue at Q2 is not Successfull"<<endl;
        }
      
    }
  
    int dequeue(){
      
        if(rear!=-1){
            int t=arr[front];
            for(int i=0;i<rear;i++){
                arr[i]=arr[i+1];
            }
            rear--;
            cout<<"Dequeue from Q2 is Successfull"<<endl;
            if(rear==-1){
                front=-1;
            }
            return t;
        }
        else{
            cout<<"Dequeue from Q2 is not Successfull"<<endl;
            return 1;
        }
      
    }
     void printingQueueQ2(){
      cout<<"The Q2 elements are as follows:"<<endl;
      for(int i=0;i<=rear;i++){
          cout<<arr[i]<<" ";
      }
      cout<<endl;
  }
}q2;

int checkStatus(int arr[],int size){
    
   
    for(int i=0;i<size;i++){
        
        if(q2.dequeue()!=arr[i]){
         
            return 1;
        }
               
    }
    return 0;
}
int checkingStackPermutation(int arr[],int size){
   
        int i=0;
        while(q1.rear>-1){
            int t=q1.dequeue();
            
            if(t==arr[i]){
                q2.enqueue(t);
            }
            else if(t<arr[i]){
                while(t!=arr[i] && t!=-1){
                    st.push(t);
                    t=q1.dequeue();
                }
                if(t!=-1){
                q2.enqueue(t);
                }
            }
            else{
               while(t>arr[i]){
                   q2.enqueue(st.pop());
                   i++;
               }
               if(t!=-1){
                q2.enqueue(t);
                }
            }
            i++;
    }
    
    while(st.top>-1){
        q2.enqueue(st.pop());
        st.top--;
    }
    q2.printingQueueQ2();
    
    return checkStatus(arr,size);
}
int main(){
    
    cout<<"Enter the n :";
    int n,p=1;
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the Stack permutation:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<p++<<" number :";
        cin>>arr[i];
    }
    
    for(int i=1;i<=n;i++){
        q1.enqueue(i);
    }
    int response=checkingStackPermutation(arr,n);
    if(response==1){
        cout<<"This Input Stack permutation is not possible"<<endl;
    }
    else{
    cout<<"The Stack permutation is : True"<<endl;
        
    }
    return 0;
}