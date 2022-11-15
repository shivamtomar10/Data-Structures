#include<iostream>
using namespace std;



template<typename a>

class Node{
    public:
        a data;
        Node* next;
        
        Node(a data){
            this->data=data;
            next=NULL;
           
        }
};



template<typename a>

class LinkedList{
    public:
        
    Node<a>* head=NULL;
    int p=1;
    void creationOfList(int nodes){
        while(nodes--){
        a value;
        cout<<"Enter the value of your "<<p++<<" Node is:";
        cin>>value;
        
        
        if(head==NULL){
            head=new Node<a>(value);
        }
        else{
            Node<a>* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            
            ptr->next=new Node<a>(value);
        }
        
        
    }
    
    cout<<"The Nodes Creation of your LinkedList is successful"<<endl;
    }
    
// through a function->concatenation
    void concat(LinkedList obj){
        Node<a>* ptr=this->head;
        
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=obj.head;
        
        obj.head=NULL;
        
        cout<<"Both List get concatenated"<<endl;
    }
    // through operator overloading 
    Node<a>* operator+(LinkedList obj){
        Node<a>* ptr=this->head;
        
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=obj.head;
        
        obj.head=NULL;
        
        cout<<"Both List get concatenated"<<endl;
        return head;
        
    }
    //printing of node elements 
    void print(){
        
        Node<a>* ptr=this->head;
        cout<<"List Elements are as follows:";
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }
};


int main(){
    
    LinkedList <string> obj1,obj2;
    
    cout<<"Enter the number of nodes you want into your 1 LinkedList:";
    int nodes_1;
    cin>>nodes_1;
    
    obj1.creationOfList(nodes_1);
    
    cout<<"Enter the number of nodes you want into your 2 LinkedList:";
    int nodes_2;
    cin>>nodes_2;
    
    obj2.creationOfList(nodes_2);
    
    //obj1.concat(obj2);
    
    Node<string>* head=obj1+obj2;
    obj1.print();
    
    return 0;
}
