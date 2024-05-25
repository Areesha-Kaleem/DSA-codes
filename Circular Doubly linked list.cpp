#include<iostream>
#include<conio.h>
using namespace std;
struct CDnode
{
	int data;
	struct CDnode* next;  
	struct 	CDnode* prev;
};
void Traversal(struct CDnode* head,struct CDnode* tail)
{
	int opt;
	if(head==NULL)
	{
		cout<<"Can't traverse Linked list is empty"<<endl;
	}
	else
	{
		cout<<"1)Move Forward \n2)Move Backward \n"<<endl;
		cin>>opt;
		struct CDnode* Ht = head;
		struct CDnode* Tt = tail;
		if(opt == 1)
		{
			cout<<"Traversing..."<<endl;
			while(Ht->next != head)
			{
			cout<<Ht->data<<endl;
			Ht = Ht->next;
			}
			cout<<Ht->data<<endl;			
		}
		else if(opt == 2)
		{
			cout<<"Traversing..."<<endl;
			while(Tt->prev != tail)
			{
			cout<<Tt->data<<endl;
			Tt = Tt->prev;
			}
			cout<<Tt->data<<endl;	
		}
		else
		{
			cout<<"Wrong option!!"<<endl;
		}
	}
}
struct CDnode* insert_atStart(struct CDnode* head)
{
	if(head==NULL)
	{
		head = new CDnode;
		cout<<"Enter the data: ";
		cin>>head->data;
		head->next = head;
		head->prev = head;
		return head;
	}
	else
	{
		struct CDnode* temp;
		temp = new CDnode;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->prev = head->prev;
		struct CDnode* hp = head->prev;
		hp->next = temp;
		temp->next=head;
		head->prev = temp;
		return temp;
	}
}
struct CDnode* delete_head(struct CDnode* head)
{	
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else if(head->next==head){
		delete head;
		head = NULL;
		return head;
	}
	else
	{
		struct CDnode* temp = head->next;
		struct CDnode* hp = head->prev;
		hp->next = temp;
		temp->prev = head->prev;
		delete head;
		cout<<"Head Deleted"<<endl;
		return temp;
	}
}
struct CDnode* insert_atEnd(struct CDnode* head,struct CDnode* tail)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		if(tail->next==head)
		{
			struct CDnode* temp = new CDnode;
			cout<<"Enter the data: ";
			cin>>temp->data;
			temp->prev = tail;
			head->prev = temp;
			temp->next= tail->next;
			tail->next = temp;
			return temp;
		}
	}	
}
struct CDnode* delete_tail(struct CDnode* head,struct CDnode* tail)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else if(tail->prev==tail){
		delete tail;
		tail = NULL;
		return tail;
	}
	else
	{
		struct CDnode* temp = tail->prev;
		delete tail;
		cout<<"Tail Deleted\n";
		temp->next=head;
		head->prev=temp;
		return temp;
	}
}
void insert_atPosition(struct CDnode* head)
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
		struct CDnode* temp = new CDnode;
		cout<<"Enter the data: ";
		cin>>temp->data;
		struct CDnode* fnext = head->next;
		temp->next = head->next;
		head->next = temp;
		temp->prev = head;
		fnext->prev = temp;
	}
}
void delete_atPosition(struct CDnode* head)
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
		struct CDnode* todel = head->next;
		head->next = todel->next;
		struct CDnode* link = todel->next;
		link->prev = head;
		delete todel;
	}
}
void search(struct CDnode* head)
{
	int value,ind;
	cout<<"Enter the data to search: ";
	cin>>value;
	while(true)
	{
		ind++;
		if(head->data==value){
			ind--;
			cout<<value<<" found at node "<<ind<<endl;
			break;
		}
		head=head->next;
	}
}
void sort(struct CDnode* head)
{
	if(head == NULL)
	{
		cout<<"Linked List is empty. \n";
	}
	else
	{
	struct CDnode* reset = head;
	int check = 1;
		while(true)
		{
			if(check == 1)
			{
				check = 0;
				while(head->next!=reset)
				{
					if(head->data>head->next->data)
					{
						int temp = head->data;
						head->data = head->next->data;
						head->next->data=temp;
						check = 1;
						
					}
					head = head->next;
				}
				head = reset;
			}
			else
			{
				cout<<"Sorted. \n";
				break;
			}
		}
	}	
}

int main()
{
	struct CDnode* head = NULL;
	struct CDnode* tail = NULL;
	int opt;
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Insert at head \n 2)Insert at tail \n 3)Insert at provided position \n 4)Delete at head \n 5)Delete at tail \n 6)Delete at provided position \n 7)Traversal \n 8)Search \n 9)Sort \n 10)Exit \n Choose: ";	
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
			if(head->next==head){
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
			if(tail->prev==tail){
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
			sort(head);
			Traversal(head,tail);	
		}
		else if(opt == 10)
		{
			break;
		}
	}
	return 0;
}
