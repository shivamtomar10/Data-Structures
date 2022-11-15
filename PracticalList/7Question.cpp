#include<iostream>
using namespace std;

class Node{
  public:
  string first_name;
  string last_name;

  string course_code;
  int grade;
  Node* next;

  Node(string f_name,string l_name,string crs_code,int gd){
      first_name=f_name;
      last_name=l_name;
      course_code=crs_code;
      grade=gd;
      next=NULL;
  }
};


class LinkedList{
  public:
  Node* head=NULL;
  string f_name,l_name,crs_code;
  int grade;

  void addingNode(){
      cout<<"Enter the first name :";
      cin>>f_name;
      cout<<"Enter the last name :";
      cin>>l_name;
      cout<<"Enter the course code";
      cin>>crs_code;
      cout<<"Enter the grade of student:";
      cin>>grade;

      if(head==NULL{
          head=new Node(f_name,l_name,crs_code,grade);
      }
      else{
          Node* ptr=head;
          while(ptr->next!=NULL){
              ptr=ptr->next;
          }
          ptr->next=new Node(f_name,l_name,crs_code,grade);
      }

  }
  void deleteNode(string )

};

int main(){



    return 0;
}