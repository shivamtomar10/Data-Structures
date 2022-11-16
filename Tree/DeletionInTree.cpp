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


void print(Node* root){
    while(root!=NULL){
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
        return ;
    }
    return ;
}

int childCase(Node* node,Node* root){
    int data=node->data,p=1;
    if(node==root){
        cout<<"Deletion of root is there we are deleted root of the tree"<<endl;
        root=NULL;
        return -1;
    }
    Node* ptr=NULL;
    if(node->left!=NULL && node->right!=NULL){
        // cout<<node->data<<" "<<node->left->data<<" "<<node->right->data<<endl;
        int p=0;
        Node* ptr1=node->left;
        Node* ptr2=node;
        while(ptr1->right!=NULL){
            p=1;
            ptr2=ptr1;
            ptr1=ptr1->right;
        }
        if(p==1)
            cout<<"Inside"<<endl;

        node->data=ptr1->data;
        if(ptr1->left!=NULL && p==1){
            // cout<<"1stif else"<<endl;
            ptr2->right=ptr1->left;
        }
        else if(ptr1->left==NULL && p==1){
            ptr2->right=NULL;
        }

        if(ptr1->left!=NULL && p==0){
            // cout<<"2ndif else"<<endl;
            ptr2->left=ptr1->left;
        }
        else if(ptr1->left==NULL && p==0){
            ptr2->left=NULL;
        }
        // cout<<bool(ptr2==node)<<endl;
        // cout<<ptr2->data<< "  "<<ptr2->right<<" " <<node->right<<endl;
        delete(ptr1);
        
        // cout<<"HII"<<endl;
        return 0;

    }
    else if(node->left==NULL && node->right==NULL){

            while(root!=NULL){
                if(root->data==data){
                    if(ptr!=NULL && ptr->left==root){
                        delete(root);
                        ptr->left=NULL;
                    }
                    else if(ptr!=NULL && ptr->right==root){
                        delete(root);
                        ptr->right=NULL;
                    }
                    
                    p=0;
                    break;
                }
                else if(root->data<data){
                    ptr=root;
                    root=root->right;
                }
                else{
                    ptr=root;
                    root=root->left;
                }
               
            }
            return p;
            
    }
    else{
         while(root!=NULL){
                if(root->data==data){
                    break;
                }
                else if(root->data<data){
                    ptr=root;
                    root=root->right;
                }
                else{
                    ptr=root;
                    root=root->left;
                }
               
            }
            if(root->left!=NULL){
                ptr->right=root->left;
                return 0;
            }
            else if(root->right!=NULL){
                ptr->right=root->right;
                return 0;
            }
            return 1;
    }
}

int deletionFromTree(Node* root,int del_val){
    Node* root1=root;
    while(root!=NULL){
        if(root->data==del_val){
            return childCase(root,root1);
        }
        else if(root->data<del_val){
            root=root->right;
        }
        else{
            root=root->left;
        }

    }
    return 1;
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

    print(root);


    int del_val,user_input=1;
    while(user_input==1){
    cout<<"Enter the value you want to delete from tree:";
    cin>>del_val;
    int response=deletionFromTree(root,del_val);

    if(response==0){
        cout<<"Deletion of Node is successfull"<<endl;

    }
    else if(response==-1){
        cout<<"Root is deleted"<<endl;
    }
    else{
        cout<<"Node not found"<<endl;
    }
    cout<<"Tree elements in inorder fashion is:"<<endl;
    print(root);

    cout<<"User_input for deletion:";
    cin>>user_input;
    }


    return 0;
}