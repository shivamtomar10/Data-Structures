#include<iostream>
using namespace std;

class INnode{
  public:
  int data;
  INnode* next;
  
  INnode(int val){
      data=val;
      next=NULL;
  }
};

class OUTnode{
    public:
    
    int data;
    OUTnode* next;
    
    OUTnode(int val){
        data=val;
        next=NULL;
    }
};

class LinkedList{
  public:
  
  INnode* head=NULL;
  OUTnode* head1=NULL;
  
  void creationINnode(int nodes){
      int value,p=1;
      while(nodes--){
          cout<<"Enter the value for your "<<p++<<" Node is:";
          cin>>value;
      if(head==NULL){
          head=new INnode(value);
      }
      else{
          INnode* ptr=head;
          while(ptr->next!=NULL){
              ptr=ptr->next;
          }
          ptr->next=new INnode(value);
      }
          
      }
  }
  
  void creationOutNode(){
      int sumNodeValue=0,i=1,p=0;;
      INnode* ptr=head;
      while(ptr!=NULL){
          ptr=head;
          p++;
          while(i>0 && ptr!=NULL){
            sumNodeValue+=ptr->data;
            ptr=ptr->next;
            i--;
          }
          if(head1==NULL){
              head1=new OUTnode(sumNodeValue);
          }
          else{
              OUTnode* ptr1=head1;
              while(ptr1->next!=NULL){
                  ptr1=ptr1->next;
              }
              ptr1->next=new OUTnode(sumNodeValue);
          }
          sumNodeValue=0;
          i+=p+1;
      }
  }
  
  void printINnode(){
      INnode* ptr=head;
      while(ptr!=NULL){
          cout<<ptr->data<<"->";
          ptr=ptr->next;
      }
      cout<<"NULL"<<endl;
  }
  
  void printOutNode(){
      OUTnode* ptr=head1;
      while(ptr!=NULL){
          cout<<ptr->data<<"->";
          ptr=ptr->next;
      }
      cout<<"NULL"<<endl;
    }
}obj1;
int main(){
    
    cout<<"Enter the number of nodes you want in your IN LinkedList:";
    int nodes;
    cin>>nodes;
    
    obj1.creationINnode(nodes);
    obj1.creationOutNode();
    
    cout<<"The IN LinkedList is as follows:";
    obj1.printINnode();
    
    cout<<"The OUT LinkedList is as follows:";
    obj1.printOutNode();
    
    return 0;
}