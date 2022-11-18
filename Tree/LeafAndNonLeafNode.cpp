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

int countLeafNode(Node* root){
    int count=0;
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            return ++count;
        }
        if(root->left){
            count+=countLeafNode(root->left);
        }
        if(root->right){
            count+=countLeafNode(root->right);
        }
        return count;
    }
    return 0;
}
int countNonLeafNode(Node* root){
    int count=0;
    if(root!=NULL){
        if(root->left || root->right){
            count++;
            if(root->left){
                count+=countNonLeafNode(root->left);
            }
            if(root->right){
                count+=countNonLeafNode(root->right);
            }
            return count;
        }
        return 0;
        
    }
    return 0;
}
int main(){
    int nodes,value,p=1;
    cout<<"Enter the number of nodes:";
    cin>>nodes;
    
    Node* root=NULL;
    while(nodes--){
        cout<<"Enter the value of "<<p<<" Node is:";
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
    cout<<endl;
    int count=countNonLeafNode(root);
    int count1=countLeafNode(root);
    
    cout<<"The respective tree has non leaf node as "<<count<<endl;
    cout<<"The respective tree has leaf node as :"<<count1<<endl;
    
    
    return 0;
    
}