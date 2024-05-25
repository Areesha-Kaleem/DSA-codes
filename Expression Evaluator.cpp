#include<iostream>
#include<conio.h>
#include<string>
#include<stack>
using namespace std;
struct Stack{
	int top;
	int size;
	char* arr;
};
void create(int l, struct Stack* s){
	s->size = l;
	s->arr = new char[s->size];
	s->top = -1;
}
int check_exp_len(string str){
	int c = 0;
	for(int i = 0;i<str.length();i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			c++;
		}
	}
	return c;
}
bool IsEmpty(struct Stack* s){
	if(s->top==-1){
		return true;
	}
	else{
		return false;
	}
}
bool IsFull(struct Stack* s){
	if(s->top==s->size-1){
		return true;
	}
	else{
		return false;
	}
}
void push(struct Stack* s,char bar){
	if(IsFull(s)){
		cout<<"Can't push anything in stack"<<endl;
		return;
	}
	s->top++;
	s->arr[s->top]=bar;
}
char pop(struct Stack* s){
	if(IsEmpty(s)){
		cout<<"Nothing to pop anymore"<<endl;
	}
	else{
	char a = s->arr[s->top];
	s->top--;
	return a;
	}
}
bool fill_stack(struct Stack* s,string str,int l){
	char b;
	bool flag = false;
	int loop_i = 0;
	for(int i = 0;i<str.length();i++){
		if(str[i]=='[' || str[i]=='{' || str[i]=='('){
			push(s,str[i]);
		}
		else if(str[i]==']' || str[i]=='}' || str[i]==')'){
			if(l!=0){
				b = pop(s);
				if((b=='(' && str[i]==')') || (b=='{' && str[i]=='}') || (b=='[' && str[i]==']')) {
					l--;
					loop_i = i;
				}
				else{
					flag = true;
					loop_i = i;
					cout<<"Bracket "<<str[i]<<" miss placed!!"<<endl;
					cout<<"At index "<<loop_i<<endl;
					break;
				}
			}
		}
		else if(isdigit(str[i])){
			continue;
		}
	}
	if(l==0 && flag == false){
		cout<<"Balanced expression"<<endl;
		cout<<"No Syntax error"<<endl;
		flag = true;
		return flag;
	}
	else{
		cout<<"Syntax Error!"<<endl;
		cout<<"Brackets Imbalance"<<endl;
		flag = false;
		return flag;
	}
}
bool bracketSeq(string str){
	int bar = 0;
	int curly = 0;
	int Round = 0;
	bool flagg = false;
	for(int i = 0;i<str.length();i++){
		if(bar==0 && curly==0 && Round==0 && str[i]=='['){
			bar++;
		}
		else if(bar==0 && curly==0 && Round==0 && str[i]=='{'){
			curly++;
		}
		else if(bar==1 && curly==0 && Round==0 && str[i]=='{'){
			curly++;
		}
		else if(bar==0 && curly==0 && Round>=0 && str[i]=='('){
			Round++;
		}
		else if(bar==1 && curly==1 && Round>=0 && str[i]=='('){
			Round++;
		}
		else if(bar==0 && curly==1 && Round>=0 && str[i]=='('){
			Round++;
		}
		else if(str[i]==']'){
			bar--;
		}
		else if(str[i]==')'){
			Round--;
		}
		else if(str[i]=='}'){
			curly--;
		}
		else{
			continue;
		}
	}
	if(bar==0 && curly==0 && Round==0){
		cout<<"Expression is perfectly fine"<<endl;
		flagg = true;
	}
	else{
		cout<<"Math Error!"<<endl;
		cout<<"Brackets not in sequence"<<endl;
	}
	return flagg;
}
int pull_weight(struct Stack* exp){
	char data;
	int weight;
	data = pop(exp);
	if(data=='+' || data == '-'){
		weight = 1;
	}
	else if(data=='*' || data == '/'){
		weight = 2;
	}
	else if(data=='(' || data=='{' || data=='['){
		weight = 3;
	}
	push(exp,data);
	return weight;
}
string postfix(struct Stack* exp,string str){
	char arr[str.length()];
	int w;
	char d;
	int count = 0;
	for(int i = 0;i<str.length();i++){
		if(!IsEmpty(exp)){
			if(str[i]=='+' || str[i]=='-'){
				w = pull_weight(exp);
				if(w==3){
					push(exp,str[i]);
				}
				else{
					while(!IsEmpty(exp)){
						d = pop(exp);
						if(d!='(' && d!='{' && d!='['){
							arr[count]=d;
							count++;
						}
					}
					push(exp,str[i]);
				}
			}
			else if(str[i]=='*' || str[i]=='/'){
				w = pull_weight(exp);
				if(w==2){
					d = pop(exp);
					arr[count]=d;
					count++;
					push(exp,str[i]);
				}
				else{
					push(exp,str[i]);
				}	
			}
			else if(str[i]=='('){
				push(exp,str[i]);
			}
			else if(str[i]==')'){
				do{
					d = pop(exp);
					if(d!='('){
						arr[count]=d;
						count++;
					}
				}
				while(d!='(' && !IsEmpty(exp));
			}
			else if(str[i]=='{'){
				push(exp,str[i]);
			}
			else if(str[i]=='}'){
				do{
					d = pop(exp);
					if(d!='{'){
						arr[count]=d;
						count++;
					}
				}
				while(d!='{' && !IsEmpty(exp));
			}
			else if(str[i]=='['){
				push(exp,str[i]);
			}
			else if(str[i]==']'){
				do{
					d = pop(exp);
					if(d!='['){
						arr[count]=d;
						count++;
					}
				}
				while(d!='[' && !IsEmpty(exp));
			}
			else{
				arr[count] = str[i];
				count++;
			}
		}
		else if(IsEmpty(exp)){
			if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='(' || str[i]=='{' || str[i]=='['){
				push(exp,str[i]);
			}
			else{
				arr[count] = str[i];
				count++;
			}	
		}
	}
	while(!IsEmpty(exp)){
		d = pop(exp);
		arr[count]=d;
		count++;
	}
//	char num[10]={'0','1','2','3','4','5','6','7','8','9'};
//	bool digitc;
	string s = "";
	cout<<"Postfix form of given expression is ready!"<<endl;
	for(int k = 0;k<count;k++){
//		for(int l = 0;l<10;l++){
//			if(arr[k]==num[l]){
//				digitc=true;
//			}
//		}
//		if(digitc){
//			cout<<arr[k]<<"";
//			digitc = false;
//		}
//		else{
			s+=arr[k];
			cout<<arr[k]<<"";
//		}
	}
	cout<<endl;
	return s;
}
int evaluation(string s){
	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch(s[i]){
				case'+':
					st.push(op1+op2);
					break;	
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case'/':
					st.push(op1/op2);
					break;
			}
		}
	}
	return st.top();
}
int main(){
	cout<<"				Expression Evaluator Here :)								"<<endl;
	cout<<" 			Intro: Made by Areesha Kaleem (2022-CE-15) and\n 			I can convert infix containing any number of digits to postfix\n 			but can evaluate numerical answer for only single digit expressions moye moye)'"<<endl;
	string str;
	int length;
	int opt;
	bool pass = false;
	string es;
	struct Stack* exp = new Stack;
	while(true){
		cout<<"Enter the expression(to exit enter E): ";
		cin>>str;
		if(str=="E"){
			break;
		}
		else{
			length = check_exp_len(str);
			if(length!=0){
				create(length,exp);
				pass = fill_stack(exp,str,length);
				if(pass){
					cout<<"Now checking for sequence"<<endl;
					pass = bracketSeq(str);
				}
				if(pass){
					create(str.length(),exp);
					cout<<"What form you wanna convert your expression in\n 1)Postfix\n 2)Exit\nchoose one: ";
					cin>>opt;
					if(opt==1){
						es = postfix(exp,str);
						cout<<"Result: ";
						cout<<evaluation(es)<<endl;
					}
					else if(opt==2){
						break;
					}
					else{
						cout<<"Oo Invalid Input Entered!!"<<endl;
					}
				}	
			}
			else{
				create(str.length(),exp);
				cout<<"What form you wanna convert your expression in\n 1)Postfix\n 2)Exit\nchoose one: ";
				cin>>opt;
				if(opt==1){
					es = postfix(exp,str);
					cout<<"Result: ";
					cout<<evaluation(es)<<endl;
				}
				else if(opt==2){
					break;
				}
				else{
					cout<<"Oo Invalid Input Entered!!"<<endl;
				}
			}
		}
	}
	delete[] exp->arr;
	return 0;
}
