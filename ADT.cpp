#include<iostream>
#include<conio.h>
using namespace std;

struct ADT
{
	int size;
	int noe;
	int* ptr;
};

void Traversal(struct ADT* ar)
{
	cout<<"Displaying the Array.\n";
	for(int i=0; i<ar->size;i++)
	{
		cout<<ar->ptr[i]<<" ";
	}
	cout<<endl;
}

void createArray(struct ADT* ar)
{
	cout<<"Enter the size of array you want to create: ";
	cin>>ar->size;
	ar->ptr=new int[ar->size];
	
}
void resize(struct ADT* ar,int c)
{
	int size = ar->size*2;
	int* p = new int[size];
	for(int i=0;i < c;i++)
	{
		p[i]=ar->ptr[i];
	}
	delete[] ar->ptr ;
	ar->ptr = p;
	ar->size = size;
	cout<<"Array resized to 2x its created size.\n";
}
void index_insertion(struct ADT* ar, int ind,int value,int counter){
	for (int i = counter + 1; i > ind; --i) 
		{
    		ar->ptr[i] = ar->ptr[i - 1];
		}
		ar->ptr[ind] = value;
}
int insert(struct ADT* ar,int c)
{
	bool flag;
	int counter = c;
	if(counter == 0)
	{
		cout<<"Enter the number of elements you want to add: \n";
		cin>>ar->noe;
		if(ar->noe > ar->size)
		{
			cout<<"Array Overflow\n";
			 flag = false;
		}
		else
		{
			flag = true;
			cout<<"Start Entering the Elements: \n";
			for(int i=0;i<ar->noe;i++)
			{
				cin>>ar->ptr[i];
				counter++;
				if(i==ar->size*0.7){
					resize(ar,counter);		
				}
			}
		}
	}	
	else
	{
		int value, ind;
		cout<<"What you want to insert in the array?\n";
		cin>>value;
		cout<<"At what index?\n";
		cin>>ind;
		if(ind>ar->size)
		{
			flag = false;
			cout<<"Index out of range.\n";
		}
		else if(ind>counter-1)
		{
			if(ar->ptr[ind]==0){
				ar->ptr[ind]=value;
				counter++;
				if(counter>=0.7*ar->size)
				{
				resize(ar,counter);
				}
				flag = true;
			}
			else{
				if(ar->ptr[ind-1]==0){
					ar->ptr[ind-1]=value;
					counter++;
					if(counter>=0.7*ar->size)
					{
					resize(ar,counter);
					}
					flag = true;
				}
				else if(ar->ptr[ind+1]==0){
					ar->ptr[ind+1]=value;
					counter++;
						if(counter>=0.7*ar->size)
						{
						resize(ar,counter);
						}
						flag = true;
				}
			}
		}
		else if(ind<counter)
		{
			index_insertion(ar,ind,value,counter);
			counter++;
			if(counter>=0.7*ar->size)
			{
			resize(ar,counter);
			}
			flag = true;	
		}
	}
	if(flag = true)
	{
		Traversal(ar);
	}
	return counter;
}
void update(struct ADT* ar,int counter)
{
	int value, ind;
	if(counter == 0)
	{
		cout<<"Updation feature is unavailable right now. Array is empty.\n";
	}
	else
	{
		cout<<"Up to "<<counter<<" is filled.";
		cout<<"Enter the index to update\n";
		cin>>ind;
		if(ind>counter)
		{
			cout<<"Invalid Index choosen.\n";
		}
		else
		{
			cout<<"Enter the updation you want\n";
			cin>>value;
			ar->ptr[ind]=value;
			Traversal(ar);
		}
	}
}
void del(struct ADT* ar,int counter){
	int d;
	if(counter == 0)
	{
		cout<<"Nothing can be deleted. Array is already empty.\n";
	}
	else if(d>=0 && d<counter-1)
	{
		cout<<"Enter the index you want to delete\n";
		cin>>d;
		for(int i=d;i<=counter-1;i++)
		{
			ar->ptr[i] = ar->ptr[i+1];
		}
		Traversal(ar);
		cout<<"Deletion process completed.\n";
	}
	else if(d==counter-1) 
	{
			ar->ptr[d]= 0;
			Traversal(ar);
			cout<<"Deletion process completed.\n";
	}
}
void reverse(struct ADT* ar,int counter)
{
	if(counter == 0)
	{
		cout<<"Array can\'t be reversed. It\'s empty.\n";
	}
	else
	{
		for(int i = 0;i<counter/2;i++)
		{
			int temp = ar->ptr[i];
			ar->ptr[i]=ar->ptr[counter-(i+1)];
			ar->ptr[counter-(i+1)]=temp;
		}
	Traversal(ar);
	}
}
void sort(struct ADT* ar,int counter)
{
	int pass = counter-1;
	int flag=0;
	if(counter == 0)
	{
		cout<<"Empty array can never be sorted. Sorry!\n";
	}
	else
	{
		for(int i=1;i<=pass;i++)
		{
			if(flag==0)
			{
				flag = 1;
				for(int j =0;j<counter-i;j++)
				{
					if(ar->ptr[j]>ar->ptr[j+1])
					{
						int temp = ar->ptr[j];
						ar->ptr[j]=ar->ptr[j+1];
						ar->ptr[j+1]=temp;
						flag = 0;
					}
				}
			}
			else
			{
				cout<< "List sorted!\n";
				break;
			}
		}	
	}
}
void search(struct ADT* ar,int counter){
	string option;
	int tosearch;
	bool flag= false;
	if(counter == 0)
	{
		cout<<"Can't search through empty array.\n";
	}
	else
	{
		cout<<"Choose Algorithm\na. Linear\nb. Binary\n";
		cin>>option;
		if(option=="a")
		{
			cout<<"What you want to search?\n";
			cin>>tosearch;
			for(int i=0;i<counter;i++)
			{
				if(ar->ptr[i]==tosearch)
				{
					cout<<tosearch<<" Found at index "<<i<<endl;
					flag = true;
					break;
				}
			}
			if(flag=false)
			{
				cout<<tosearch<<" not found in given array."<<endl;
			}
		}
		else if (option == "b")
		{
    		sort(ar, counter);
    		cout << "What you want to search?\n";
    		cin >> tosearch;
    		int start = 0;
    		int end = counter - 1;
    		for(int i=start;i<=end;i++) 
			{
        		int mid = start + (end - start) / 2;
        		if (ar->ptr[mid] == tosearch)
				{
        			flag = true;
            		cout << tosearch << " found at index " << mid << " after sorting.\n";
            		break;
        		}
				else if (ar->ptr[mid] < tosearch)
				{
            		start = mid + 1; 
        		} 
				else 
				{
            		end = mid - 1; 
        		}
    		}
   			if(flag=false)
			{
				cout<<tosearch<<" not found in given array."<<endl;
			}
		}
		else
		{
			cout<<"Invalid option taken."<<endl;
		}
	}
}
void max(struct ADT* ar, int counter)
{
	sort(ar,counter);
	cout<<"Maximum Element of Array is "<<ar->ptr[counter-1]<<endl;
	
}
void min(struct ADT* ar,int counter)
{
	sort(ar,counter);
	cout<<"Minimum Element of Array is "<<ar->ptr[0]<<endl;
}

int main ()
{
	int opt;
	int counter = 0;
	struct ADT arr;
	createArray(&arr);
	while(true)
	{
		cout<<"Choose What You Want To Do:\n 1)Insert Elements \n 2)Update Array \n 3)Delete Elements \n 4)Display Array \n 5)Sort Array\n 6)Search Element\n 7)Reverse Array\n 8)Maximum Element\n 9)Minimum Element\n 10)Exit\n";	
		cin>>opt;
		
		if (opt == 1)
		{
			counter = insert(&arr,counter);	
		} 
		else if(opt == 2)
		{
			update(&arr,counter);
		}
		else if(opt == 3)
		{
			del(&arr,counter);
		}
		else if(opt == 4)
		{
			Traversal(&arr);
		}
		else if(opt == 5)
		{
			sort(&arr,counter);
			Traversal(&arr);
		}
		else if(opt == 6)
		{
			search(&arr,counter);
		}
		else if(opt == 7)
		{
			reverse(&arr,counter);	
		}
		else if(opt == 8)
		{
			max(&arr,counter);
		}
		else if(opt == 9)
		{
			min(&arr, counter);
		}
		else if(opt == 10)
		{
			delete[] arr.ptr;
			break;
		}	
	}
	return 0;
}
