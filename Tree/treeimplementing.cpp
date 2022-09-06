#include<iostream>
using namespace std;


class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
};

void makingOfNode(Tree* ptr,int data){
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
}



int preorderTraversal(Tree* root){
    while(root!=NULL){
        cout<<root->data<<"->";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return 0;
    }
    return 1;
}

int postorderTraversal(Tree* root){
    while(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<"->";
        return 0;
    }
    return 1; 
}

int inorderTraversal(Tree* root){
      while(root!=NULL){
        inorderTraversal(root->left);
        cout<<root->data<<"->";
        inorderTraversal(root->right);
        return 0;
    }
    return 1; 
}
int main(){

   
    Tree* root=new Tree();
    Tree* p1=new Tree();
    Tree* p2=new Tree();    
    Tree* p3=new Tree();
    Tree* p4=new Tree();
    Tree* p5=new Tree();
    Tree* p6=new Tree();
   
    makingOfNode(root,5);
    makingOfNode(p1,4);
    makingOfNode(p2,1);
    makingOfNode(p3,2);
    makingOfNode(p4,3);
    makingOfNode(p5,7);
    makingOfNode(p6,6);    
    
/*       5
       /  \
      4    3
     / \  / \
    1  2  7  6 */
    root->left=p1;
    root->right=p4;
    p1->left=p2;
    p1->right=p3;
    p4->left=p5;
    p4->right=p6;

    cout<<"The preorderTraversal of the defalut tree is:"<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"The postorder Traversal of the default tree is:"<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<"The inorderTraversal of the default tree is :"<<endl;
    inorderTraversal(root);
    cout<<endl;

    return 0;

}