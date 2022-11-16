#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int val){
      data=val;
      left=NULL;
      right=NULL;
  }
};

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheigh=heightOfTree(root->left);
        int rheigh=heightOfTree(root->right);

        if(lheigh>rheigh){
            return lheigh+1;
        }
        else{
            return rheigh+1;
        }
    }
}
int main(){
    int nodes,value,p=1;
    cout<<"Enter the number of nodes:";
    cin>>nodes;
    
    
    Node* root=NULL;
    while(nodes--){
        cout<<"Enter the value of "<<p++<<" Node is:";
        cin>>value;
        if(root==NULL){
            root=new Node(value);
        }
        else{
            Node* ptr=root;
            Node* ptr1=NULL;
            
            while(ptr!=NULL){
                if(ptr->data<=value){
                    ptr1=ptr;
                    ptr=ptr->right;
                    if(ptr==NULL){
                        ptr1->right=new Node(value);
                    }
                    
                }
                else{
                    ptr1=ptr;
                    ptr=ptr->left;
                    if(ptr==NULL){
                        ptr1->left=new Node(value);
                    }
                }
            }
            
            
            
        }
    }
   cout<<"Height of the tree is :"<<heightOfTree(root)-1<<endl;
    
    return 0;
}
