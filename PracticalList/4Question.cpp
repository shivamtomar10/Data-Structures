#include<iostream>
using namespace std;



//4 Question

class Node{
  public:
  int data;
  Node* next;
  
  Node(int val){
      this->data=val;
      next=NULL;
  }
};

class LinkedList{
  public:
  Node* head=NULL;
  
  void creationOfNode(){
      cout<<"Enter the number of nodes you want in your LinkedList:";
      int nodes,value,p=1;
      cin>>nodes;
      
      while(nodes--){
          cout<<"Enter the value of your "<<p++<<" Node is:";
          cin>>value;
          if(head==NULL){
              head=new Node(value);
          }
          else{
              Node* ptr=head;
              while(ptr->next!=NULL){
                  ptr=ptr->next;
              }
              
              ptr->next=new Node(value);
          }
      }
  }
  
  void separationOfList(){
      Node* ptr=this->head;
      int i=1;
      LinkedList obj,obj1;
      while(ptr!=NULL){
          if(i%2==0){
               if(obj.head==NULL){
                  obj.head=ptr;
                  ptr=ptr->next;
                  obj.head->next=NULL;
              }
              else{
                  Node* ptr1=obj.head;
                  while(ptr1->next!=NULL){
                      ptr1=ptr1->next;
                  }
                  ptr1->next=ptr;
                  Node* ptr2=ptr;
                  ptr=ptr->next;
                  ptr2->next=NULL;
              }
          }
          else{
              if(obj1.head==NULL){
                  obj1.head=ptr;
                  ptr=ptr->next;
                  obj1.head->next=NULL;
              }
              else{
                  Node* ptr1=obj1.head;
                  while(ptr1->next!=NULL){
                      ptr1=ptr1->next;
                  }
                  ptr1->next=ptr;
                  Node* ptr2=ptr;
                  ptr=ptr->next;
                  ptr2->next=NULL;
              }
          }
              i++;
              
      }
         cout<<"1 List as:"<<endl;
         obj.printOfNodes();
         cout<<"2 List as :"<<endl;
         obj1.printOfNodes();
     
  }
  
  void printOfNodes(){
      Node* ptr=head;
      while(ptr!=NULL){
          cout<<ptr->data<<"->";
          ptr=ptr->next;
          
      }
      cout<<"NULL"<<endl;
  }
  
};
int main(){
    
    LinkedList obj1;
    
    obj1.creationOfNode(); // creating LinkedList
    
    cout<<"Original List is :"<<endl;
    obj1.printOfNodes();
    
    obj1.separationOfList();
    
    return 0;
}