#include<iostream>
using namespace std;

class linkedSparsematrix{
    public:
    int row,column;
    int value;
    linkedSparsematrix* next;
};

void display(linkedSparsematrix* head){
    while(head!=NULL){
        cout<<"The element is at row:"<<head->row<<" , column:"<<head->column<<" , value is:"<<head->value<<endl;
        head=head->next;
    }
}
int main(){

    int r,c;
    cout<<"Enter the rows and columns"<<endl;
    cout<<"Enter the row:";
    cin>>r;
    cout<<"Enter the columns:";
    cin>>c;

    if(r>0 && c>0){
        int arr[r][c];
        linkedSparsematrix* head=new linkedSparsematrix();
        linkedSparsematrix* ptr=head;
        int p=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<"Enter the element at the position ["<<i<<"]["<<j<<"] is:";
                cin>>arr[i][j];
                if(arr[i][j]!=0){
                    if(p){
                        
                        linkedSparsematrix* node2=new linkedSparsematrix();
                        ptr->next=node2;
                        ptr=node2;
                    }
                    ptr->row=i;
                    ptr->column=j;
                    ptr->value=arr[i][j];
                    p++;
                }
            }
        }

        display(head);
        
    }
    else{
        cout<<"rows and columns should not be zero or negative!"<<endl;
    }
    return 0;

}