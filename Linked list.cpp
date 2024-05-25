#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	struct node* next;  //self refrencing pointer 
		
};
void Traversal(struct node* head)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
		while(head->next != NULL)
		{
			cout<<head->data<<endl;
			head = head->next;
		}
		cout<<head->data<<endl;
	}
}
struct node* insert_atStart(struct node* head)
{
	if(head==NULL)
	{
		head = new node;
		cout<<"Enter the data: ";
		cin>>head->data;
		head->next = NULL;
		return head;
	}
	else
	{
		struct node* temp;
		temp = new node;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next=head;
		return temp;
	}
}
struct node* delete_head(struct node* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		struct node* temp;
		temp = head->next;
		delete head;
		cout<<"Head Deleted. \n";
		Traversal(temp);
		return temp;
	}
}
void insert_atEnd(struct node* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		while(true)
		{
			if(head->next==NULL)
			{
				struct node* temp = new node;
				cout<<"Enter the data: ";
				cin>>temp->data;
				temp->next= NULL;
				head->next = temp;
				break;
			}
			head = head->next;
		}	
	}
}
struct node* delete_atEnd(struct node* head)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else if(head->next == NULL) 
	{
		delete head;
		head = NULL;
		cout<<"Tail Deleted. List is now empty.\n";
		return head;
	}
	else
	{
		struct node* temp = head;
		struct node* prev = NULL;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		delete temp;
		cout<<"Tail Deleted\n";
	}
}
void insert_atPosition(struct node* head)
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
		struct node* prv;
		while(counter < index)
		{
			prv = head;
			head=head->next;
			counter++;
		}
		struct node* temp = new node;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next = head;
		prv->next = temp;
	}
}
void delete_atPosition(struct node* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		struct node* pr;
		int index;
		cout<<"Enter the node no: ";
		cin>>index;
		int counter;
		while(counter != index)
		{
			pr = head;
			head=head->next;
			counter++;
		}
		pr->next = head->next;
		delete head;
		head = pr;
	}
}
void search(struct node* head)
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
	struct node* head = NULL;
	int opt;
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Insert at head \n 2)Insert at tail \n 3)Insert at provided position \n 4)Delete at head \n 5)Delete at tail \n 6)Delete at provided position \n 7)Traversal \n 8)Search \n 9)Exit \n Choose: ";	
		cin>>opt;
		if(opt == 1)
		{
			head = insert_atStart(head);
			Traversal(head);
		}
		else if(opt == 2)
		{
			insert_atEnd(head);
			Traversal(head);
		}
		else if(opt == 3)
		{
			insert_atPosition(head);
			Traversal(head);
		}
		else if(opt == 4)
		{
			head = delete_head(head);
		}
		else if(opt == 5)
		{
			head = delete_atEnd(head);
//			Traversal(head);
		}
		else if(opt == 6)
		{
			delete_atPosition(head);
			Traversal(head);
		}
		else if(opt == 7)
		{
			Traversal(head);
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
