#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  char alpha;
  Node* left;
  Node* right;
  
  Node(int val,char ch){
      data=val;
      alpha=ch;
      left=NULL;
      right=NULL;
  }
};
void mirror_image(Node* root){
    if(root!=NULL){
        if(root->left){
            mirror_image(root->left);
        }
        if(root->right){
            mirror_image(root->right);
        }
        Node* ptr=root->right;
        root->right=root->left;
        root->left=ptr;
        return ;
    }
    return ;
}
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
    
    char ch;
    Node* root=NULL;
    while(nodes--){
        cout<<"Enter the value of "<<p<<" Node is:";
        cin>>value;
        cout<<"Enter the character of "<<p++<<" Node is: ";
        cin>>ch;
        if(root==NULL){
            root=new Node(value,ch);
        }
        else{
            Node* ptr=root;
            Node* ptr1=NULL;
            
            while(ptr!=NULL){
                if(ptr->data<=value){
                    ptr1=ptr;
                    ptr=ptr->right;
                    if(ptr==NULL){
                        ptr1->right=new Node(value,ch);
                    }
                    
                }
                else{
                    ptr1=ptr;
                    ptr=ptr->left;
                    if(ptr==NULL){
                        ptr1->left=new Node(value,ch);
                    }
                }
            }
            
            
            
        }
    }
    cout<<"Original Tree nodes in inorder traversal is :";
    inorder(root);
    cout<<endl;
    cout<<"Mirror image inorder traversal"<<endl;
    mirror_image(root);
    inorder(root);
    return 0;
}