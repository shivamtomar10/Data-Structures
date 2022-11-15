#include<iostream>
using namespace std;

// Node class
class Node{
  public:
  int coeff;
  int degree;
  Node* next;
  
  Node(int c,int d){
      coeff=c;
      degree=d;
      next=NULL;
  }
    
};


class LinkedList{
  public:
  Node* head=NULL;
  
   void insertion(int c,int d){
       if(head==NULL){
           head=new Node(c,d);
       }
       else{
           Node* ptr=head;
           while(ptr->next!=NULL){
               ptr=ptr->next;
           }
           ptr->next=new Node(c,d);
       }
   }
   void creation(int terms){
       int p=1;
        while(terms--){
            
        
        int coeff,degree;
        cout<<"Enter the coeff for the "<<p<<" node is:";
        cin>>coeff;
        cout<<"Enter the degree for the "<<p++<<" node is:";
        cin>>degree;
        
        if(head==NULL){
            head=new Node(coeff,degree);
        }
        else{
            Node* ptr=head;
            Node* ptr1=NULL;
            while(ptr!=NULL && ptr->degree<degree){
                ptr1=ptr;
                ptr=ptr->next;
            }
            Node* t=new Node(coeff,degree);
            if(ptr1!=NULL){
                ptr1->next=t;
                t->next=ptr;
            }
            else{
                t->next=head;
                head=t;
            }
        }
        }
       cout<<"List Creation is successfull"<<endl;
    }
    
    // printing Node Elements
    void print(){
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->coeff<<":"<<ptr->degree<<"->";
            ptr=ptr->next;
           
        }
        cout<<"NULL"<<endl;
    }
    
    LinkedList add(LinkedList obj){
        Node* ptr=head;
        Node* ptr1=obj.head;
        LinkedList obj3;
       while(ptr && ptr1){
            if(ptr->degree==ptr1->degree){
                obj3.insertion(ptr->coeff+ptr1->coeff,ptr->degree);
                ptr=ptr->next;
                ptr1=ptr1->next;
            }
            else if(ptr->degree<ptr1->degree){
                obj3.insertion(ptr->coeff,ptr->degree);
                ptr=ptr->next;
            }
            else{
                obj3.insertion(ptr1->coeff,ptr1->degree);
                ptr1=ptr1->next;
            }
        }
        while(ptr){
            obj3.insertion(ptr->coeff,ptr->degree);
            ptr=ptr->next;
        }
        while(ptr1){
            obj3.insertion(ptr1->coeff,ptr1->degree);
            ptr1=ptr1->next;
        }
        return obj3;
    }
};
int main(){
    
    cout<<"Enter the number of terms for 1 polynomial:";
    int terms_1;
    cin>>terms_1;
    
    LinkedList obj1,obj2;
    obj1.creation(terms_1);
    
    cout<<"The First polynomail coeff:degree is:"<<endl;
    obj1.print();
    
    cout<<"Enter the number of terms for 2 polynomial:";
    int terms_2;
    cin>>terms_2;
    
    obj2.creation(terms_2);
    
     cout<<"The second polynomail coeff:degree is:"<<endl;
     obj2.print();
    LinkedList obj3=obj1.add(obj2);
     cout<<"The adding polynomail coeff:degree is:"<<endl;
     obj3.print();
    return 0;
}
