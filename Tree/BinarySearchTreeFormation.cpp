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

void inorder(Node* root){
   
    while(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        return;
    }
    return ;
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
    cout<<"Trees nodes in inorder traversal is :";
    inorder(root);
    return 0;
}
