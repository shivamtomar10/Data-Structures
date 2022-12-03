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
      cout<<"Enter the course code:";
      cin>>crs_code;
      cout<<"Enter the grade of student:";
      cin>>grade;

      if(head==NULL){
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

  void deleteNode(){
      cout<<"Enter the first name :";
      cin>>f_name;
      cout<<"Enter the last name :";
      cin>>l_name;

      Node* ptr=head;
      Node* ptr1=NULL;
      if(ptr==NULL){
        cout<<"Nothing Is there in Linked List"<<endl;
      }
      else{
        while(ptr!=NULL && (ptr->first_name!=f_name || ptr->last_name!=l_name)){
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr==head){
            head=ptr->next;
            delete(ptr);
            cout<<"Deletion Happens Successfully"<<endl;
        }
        else if(ptr==NULL){
            cout<<"Input Record Not Found in Database for deletion"<<endl;
        }
        else{
            ptr1->next=ptr->next;
            delete(ptr);
            cout<<"Deletion Happens Successfully"<<endl;
        }
      }

  }
  int searchDatabase(){
        cout<<"Enter the last name :";
        cin>>l_name;

        Node* ptr=head;

        while(ptr!=NULL && ptr->last_name!=l_name){
            ptr=ptr->next;
            if(ptr==NULL){
                return 1;
            }
        }
        return 0;

  }

  void printDatabase(){
    Node* ptr=head;

    while(ptr!=NULL){
        cout<<"Name :"<<ptr->first_name<<" "<<ptr->last_name<<endl;
        cout<<"Course Code:"<<ptr->course_code<<endl;
        cout<<"Grade :"<<ptr->grade<<endl;

        cout<<endl;

        ptr=ptr->next;
    }
  }

  void classAvg(){
        cout<<"Enter the course code:";
        cin>>crs_code;

        int sum=0,count=0;
        Node* ptr=head;

        while(ptr!=NULL){
            if(ptr->course_code==crs_code){
                count++;
                sum+=ptr->grade;
            }
            ptr=ptr->next;
        }

        cout<<"The Number of Students for the input course is:"<<count<<endl;
        cout<<"The Average of the Students is:"<<sum/count<<endl;
  }

}obj;

int main(){


    cout<<"This program is used to Record Student Database Through LinkedList"<<endl;
    char ch='y';
    while(ch=='y' || ch=='Y'){
    cout<<"1. For Adding a Record in Database"<<endl;
    cout<<"2. To Delete a Record From The Database"<<endl;
    cout<<"3. To Search a record in Database"<<endl;
    cout<<"4. To Print Records of Database"<<endl;
    cout<<"5.Finding Average of class for a particular course"<<endl;
    cout<<"6. For Quit"<<endl;

    cout<<"Enter the operation You Want to Perform:";
    int option,response;
    cin>>option;

    switch(option){
        case 1:
        obj.addingNode();
        break;
        case 2:
        obj.deleteNode();
        break;
        case 3:
        response=obj.searchDatabase();
        if(response==0){
            cout<<"The Search Record is in there in Database"<<endl;
        }
        else{
            cout<<"Search Record Not Found in Database"<<endl;
        }
        break;
        case 4:
        obj.printDatabase();
        break;
        case 5:
        obj.classAvg();
        break;
        case 6:
        ch='n';
        break;
        default:
        cout<<"Enter Operation is Wrong! please Enter Valid Op_code"<<endl;


    }
    }
    cout<<"Quit Done"<<endl;
   

    return 0;
}