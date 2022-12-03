#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

int precedence(char op){
    if(op=='+' || op=='-'){
        return 1;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    else {
        return 0;
    }
}

int eval(int v1,int v2, char op){
    switch(op){
        case '+': return v1+v2;
        case '-': return v1-v2;
        case '*': return v1*v2;
        case '/': return v1/v2;
    }
    return 0;
}

int expSeparate(string exp){
    stack<int> values;
    stack<char> opr;

    for(int i=0;i<exp.length();i++){
        if(exp[i]==' '){
            continue;
        }
        else if(exp[i]=='('){
            opr.push('(');
        }
        else if(isdigit(exp[i])){
            int val=0;

            while(i<exp.length() && isdigit(exp[i])){
                val=val*10+(exp[i]-'0');
                i++;
            }

            values.push(val);
            i--;
        }
        else if(exp[i]==')'){

            while(!opr.empty() && opr.top()!='('){
                int val2=values.top();
                values.pop();

                int val1=values.top();
                values.pop();

                char op=opr.top();
                opr.pop();

                values.push(eval(val1,val2,op));
            }
        }
        else {
            while(!opr.empty() && precedence(opr.top())>=precedence(exp[i])){
                int val2=values.top();
                values.pop();

                int val1=values.top();
                values.pop();

                char op=opr.top();
                opr.pop();

                values.push(eval(val1,val2,op));
            }
            opr.push(exp[i]);
        }
    }
    while(!opr.empty()){
		int val2 = values.top();
		values.pop();
				
		int val1 = values.top();
		values.pop();
				
		char op = opr.top();
		opr.pop();
				
		values.push(eval(val1, val2, op));
	}
    return values.top();

}

int main(int argc,char** argv[]){

    if(argc>1){
        fstream obj;
        string name=*argv[0];
        obj.open(name);
        if(!obj){
            cout<<"error in opening file"<<endl;
            return -1;
        }
        string a;
        cout<<a<<endl;
        while(getline(obj,a)){
            cout<<expSeparate(a);
        }
    }

   
    return 0;
}