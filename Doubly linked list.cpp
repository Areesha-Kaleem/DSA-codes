#include<iostream>
#include<conio.h>
using namespace std;
struct Dnode
{
	int data;
	struct Dnode* next;  
	struct 	Dnode* prev;
};
void Traversal(struct Dnode* head,struct Dnode* tail)
{
	int opt;
	if(head==NULL)
	{
		cout<<"Can't traverse Linked list is empty"<<endl;
	}
	else
	{
		cout<<"1)Traverse forward \n2)Traverse backward \n"<<endl;
		cin>>opt;
		if(opt == 1)
		{
			cout<<"Traversing..."<<endl;
			while(head->next != NULL)
			{
			cout<<head->data<<endl;
			head = head->next;
			}
			cout<<head->data<<endl;			
		}
		else if(opt == 2)
		{
			cout<<"Traversing..."<<endl;
			while(tail->prev != NULL)
			{
			cout<<tail->data<<endl;
			tail = tail->prev;
			}
			cout<<tail->data<<endl;	
		}
		else
		{
			cout<<"Wrong option!!"<<endl;
		}
	}
}
struct Dnode* insert_atStart(struct Dnode* head)
{
	if(head==NULL)
	{
		head = new Dnode;
		cout<<"Enter the data: ";
		cin>>head->data;
		head->next = NULL;
		head->prev = NULL;
		return head;
	}
	else
	{
		struct Dnode* temp;
		temp = new Dnode;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next=head;
		temp->prev = NULL;
		head->prev = temp;
		return temp;
	}
}
struct Dnode* delete_head(struct Dnode* head)
{	
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else if(head->next==NULL){
		delete head;
		head = NULL;
		return head;
	}
	else
	{
		struct Dnode* temp = head->next;
		delete head;
		temp->prev = NULL;
		cout<<"Head Deleted"<<endl;
		return temp;
	}
}
struct Dnode* insert_atEnd(struct Dnode* head,struct Dnode* tail)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
//	else if(tail==NULL)
//	{
//		while(true)
//		{
//			if(head->next==NULL)
//			{
//				struct Dnode* temp = new Dnode;
//				cout<<"Enter the data: ";
//				cin>>temp->data;
//				temp->next= NULL;
//				temp->prev = head;
//				head->next = temp;
//				tail = temp;
//				break;
//			}
//			head = head->next;
//		}
//		return tail;
//	}
	else
	{
		if(tail->next==NULL)
		{
			struct Dnode* temp = new Dnode;
			cout<<"Enter the data: ";
			cin>>temp->data;
			temp->next= NULL;
			temp->prev = tail;
			tail->next = temp;
			return temp;
		}
	}	
}
struct Dnode* delete_tail(struct Dnode* head,struct Dnode* tail)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else if(tail->prev==NULL){
		delete tail;
		tail = NULL;
		return tail;
	}
	else
	{
		struct Dnode* temp = tail->prev;
		delete tail;
		cout<<"Tail Deleted\n";
		temp->next=NULL;
		return temp;
	}
}
void insert_atPosition(struct Dnode* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{	
		int index;
		cout<<"Enter node no: ";
		cin>>index;
		int counter;
		while(counter < index-1)
		{
			head=head->next;
			counter++;
		}
		struct Dnode* temp = new Dnode;
		cout<<"Enter the data: ";
		cin>>temp->data;
		struct Dnode* fnext = head->next;
		temp->next = head->next;
		head->next = temp;
		temp->prev = head;
		fnext->prev = temp;
	}
}
void delete_atPosition(struct Dnode* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		int index;
		cout<<"Enter the node no: ";
		cin>>index;
		int counter;
		while(counter < index-1)
		{
			head=head->next;
			counter++;
		}
		struct Dnode* todel = head->next;
		head->next = todel->next;
		struct Dnode* link = todel->next;
		link->prev = head;
		delete todel;
	}
}
void search(struct Dnode* head)
{
	int value,ind;
	cout<<"Enter the data to search: ";
	cin>>value;
	while(head->next!=NULL)
	{
		ind++;
		if(head->data==value){
			ind--;
			cout<<value<<" found at node "<<ind<<endl;
		}
		head=head->next;
	}
}
int main()
{
	struct Dnode* head = NULL;
	struct Dnode* tail = NULL;
	int opt;
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Insert at head \n 2)Insert at tail \n 3)Insert at provided position \n 4)Delete at head \n 5)Delete at tail \n 6)Delete at provided position \n 7)Traversal \n 8)Search \n 9)Exit \n Choose: ";	
		cin>>opt;
		if(opt == 1)
		{
			if(head==NULL){
				head = insert_atStart(head);
				tail = head;
				Traversal(head,tail);
			}
			else{
				head = insert_atStart(head);
				Traversal(head,tail);
			}
		}
		else if(opt == 2)
		{
			tail = insert_atEnd(head,tail);
			Traversal(head,tail);
		}
		else if(opt == 3)
		{
			insert_atPosition(head);
			Traversal(head,tail);
		}
		else if(opt == 4)
		{
			if(head->next==NULL){
				head = delete_head(head);
				tail = head;
				Traversal(head,tail);
			}
			else{
				head = delete_head(head);
				Traversal(head,tail);
			}
			
		}
		else if(opt == 5)
		{
			if(tail->prev==NULL){
				tail = delete_tail(head,tail);
				head = tail;
				Traversal(head,tail);
			}
			else{
				tail = delete_tail(head,tail);
				Traversal(head,tail);
			}
		}
		else if(opt == 6)
		{
			delete_atPosition(head);
			Traversal(head,tail);
		}
		else if(opt == 7)
		{
			Traversal(head,tail);
		}
		else if(opt == 8)
		{
			search(head);
		}
		else if(opt == 9)
		{
			break;
		}
	}
	return 0;
}
