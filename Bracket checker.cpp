#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct stack{
	int top;
	int size;
	char* arr;
};
void create(int l, struct stack* s){
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
bool IsEmpty(struct stack* s){
	if(s->top==-1){
		cout<<"Stack is empty"<<endl;
		return true;
	}
	else{
		return false;
	}
}
bool IsFull(struct stack* s){
	if(s->top==s->size-1){
		cout<<"Stack is full"<<endl;
		return true;
	}
	else{
		return false;
	}
}
void push(struct stack* s,char bar){
	if(IsFull(s)){
		cout<<"Can't push anything in stack"<<endl;
		return;
	}
	s->top++;
	s->arr[s->top]=bar;
}
char pop(struct stack* s){
	if(IsEmpty(s)){
		cout<<"Nothing to pop anymore"<<endl;
	}
	else{
	char a = s->arr[s->top];
	s->top--;
	return a;
	}
}
bool fill_stack(struct stack* s,string str,int l){
	char b;
	bool flag = false;
	int loop_i = 0;
	int open = l;
	int close = 0;
	for(int i = 0;i<str.length();i++){
		if(str[i]=='[' || str[i]=='{' || str[i]=='('){
			push(s,str[i]);
		}
		else if(str[i]==']' || str[i]=='}' || str[i]==')'){
			if(l!=0){
				b = pop(s);
				if((b=='(' && str[i]==')') || (b=='{' && str[i]=='}') || (b=='[' && str[i]==']')) {
					l--;
					close++;
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
			else{
				break;
			}
		}
	}
	if(l==0 && open!=close){
		cout<<"Syntax Error!"<<endl;
		cout<<"Brackets Imbalance"<<endl;
		flag = false;
		return flag;
	}
	else if(l==0 && flag == false && open == close && loop_i == str.length()-1){
		cout<<"Balanced expression"<<endl;
		cout<<"No Syntax error"<<endl;
		flag = true;
		return flag;
	}
	else if(l==0 && open == close && loop_i != str.length()-1 ){
		cout<<"Syntax Error!"<<endl;
		cout<<"Brackets Imbalance"<<endl;
		flag = false;
		return flag;
	}
}
void bracketSeq(string str){
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
			flagg = true;
			cout<<"Math Error!"<<endl;
			cout<<"Brackets not in sequence"<<endl;
			break;
		}
	}
	if(flagg == false){
	cout<<"Expression is perfectly fine"<<endl;}

}
int main(){
	string str;
	int length;
	bool pass = false;
	struct stack* exp = new stack;
	cout<<"Enter the expression: ";
	cin>>str;
	length = check_exp_len(str);
	create(length,exp);
	pass = fill_stack(exp,str,length);
	if(pass){
		cout<<"Now checking for sequence"<<endl;
		bracketSeq(str);
	}
	return 0;
}
