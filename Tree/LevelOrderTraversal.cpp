#include<iostream>
using namespace std;


class Node{
  public:
  char ch;
  Node* left;
  Node* right;
  
  Node(char val){
      ch=val;
      left=NULL;
      right=NULL;
  }
  
    
};
Node* arr[100];
int front=-1,rear=-1;




void insertion(Node* root){
    if(rear<100){
    arr[++rear]=root;
    if(front==-1){
        front++;
    }
    }
}

int main(){
    
    Node* root=new Node('A');
    Node* p1=new Node('B');
    Node* p2=new Node('C');
    Node* p3=new Node('D');
    Node* p4=new Node('E');
    Node* p5=new Node('F');
    Node* p6=new Node('G');
    Node* p7=new Node('H');
    Node* p8=new Node('I');
    Node* p9=new Node('J');
    Node* p10=new Node('K');
    
    root->left=p1;
    root->right=p2;
    
    p1->left=p3;
    p1->right=p4;
    
    p2->left=p5;
    p2->right=p6;
    
    
    p3->left=p7;
    p4->right=p8;
    p6->left=p9;
    p6->right=p10;
    
    insertion(root);
    // cout<<arr[front]->left<<" "<<p1<<endl;
    
    while(rear!=-1){
        
        if(arr[front]->left!=NULL){
            insertion(arr[front]->left);
        }
        if(arr[front]->right!=NULL){
            insertion(arr[front]->right);
        }
        
        cout<<arr[front]->ch<<" ";
        
        for(int i=0;i<rear;i++){
            arr[i]=arr[i+1];
        }
        rear--;
        
    }
    
    
    
    
    return 0;
}
