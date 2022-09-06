#include<iostream>
using namespace std;

class BinarySearchTree{
    public:
    int data;
    BinarySearchTree* left;
    BinarySearchTree* right;
};



void makingOfNode(BinarySearchTree* ptr,int data){
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
}

BinarySearchTree* InsertionOfNode(BinarySearchTree* ptr,int value){
    if(!ptr){
        BinarySearchTree* ptr1=new BinarySearchTree();
        ptr=ptr1;
        makingOfNode(ptr,value);
    }

    if(value>ptr->data){
        ptr->right=InsertionOfNode(ptr->right,value);
    }
    else if(value<ptr->data){
        ptr->left=InsertionOfNode(ptr->left,value);
    }

    return ptr;
}

int inorderTraversal(BinarySearchTree* ptr){
    while(ptr!=NULL){
        inorderTraversal(ptr->left);
        cout<<ptr->data<<" ";
        inorderTraversal(ptr->right);
        return 1;
    }
    return 0;
}

int main(){





/*                  5
                   /  \
                  3    9
                 / \  / \
                4   2 8  10  */
               

        BinarySearchTree* root=new BinarySearchTree();    
        BinarySearchTree* p2=new BinarySearchTree();
        BinarySearchTree* p3=new BinarySearchTree();
        BinarySearchTree* p4=new BinarySearchTree();
        BinarySearchTree* p5=new BinarySearchTree();
        BinarySearchTree* p6=new BinarySearchTree();
        BinarySearchTree* p7=new BinarySearchTree();

        makingOfNode(root,5);
        makingOfNode(p2,3);  
        makingOfNode(p3,9);      
        makingOfNode(p4,4);
        makingOfNode(p5,2);
        makingOfNode(p6,8);
        makingOfNode(p7,10);

        root->left=p2;
        root->right=p3;
        p2->left=p4;
        p2->right=p5;
        p3->left=p6;
        p3->right=p7;


        cout<<"Enter the choice 1 for insertion 2 for deletion 3 for Recursive 4 for Iterative intervals:"<<endl;
        int x;
        cin>>x;

        switch(x){
            case 1:
            cout<<"Enter inserted Value: ";
            int value;
            cin>>value;
            InsertionOfNode(root,value);
            inorderTraversal(root);
           
        }


    return 0;
}