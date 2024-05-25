#include <iostream>
#include <conio.h>
#include <sstream>
using namespace std;

void traversal(int arr[],int size)
{
	for(int i = 0; i<size; i++)
	{
		cout<< "Index "<<i<<" = "<<arr[i]<<endl;
	}
}
void insertion(int arr[],int size)
{
	int value, ind;
	bool control = false;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==0){
			control = true;
			cout<<"What you want to insert in the array?\n";
			cin>>value;
			cout<<"At what index?\n";
			cin>>ind;
			if (arr[ind] == 0) 
			{
		        arr[ind] = value;
		        traversal(arr, size);
    		}
			else
			{
				if(ind==size-1)
				{
					int temp = arr[size-1];
					arr[size-1] = value;
					value = temp;
					for (int i = size - 2; i >=0 ; --i) 
						{
                			arr[i] = arr[i - 1];
            			}
					arr[0]=value;
					traversal(arr,size);
				}
				else
				{
					for (int i = size - 1; i > ind; --i) 
					{
                		arr[i] = arr[i - 1];
            		}
					arr[ind] = value;
					traversal(arr,size);
				}
			}
		}
		else
		{
			control = false;
		}
	}
	if(control == false){
		cout<<"Insertion can't be done, Array has no free index.\n";
	}
}
void del(int arr[],int size){
	int d;
	cout<<"Enter the index you want to delete\n";
	cin>>d;
	if(d==size-1){
		arr[size-1] = 0;
		traversal(arr,size);
	}
	else if(arr[d] == 0){
		cout<<"Index already empty\n";
		traversal(arr,size);
	}
	else if(d>=0 && d<size-1){
		for(int i=d;i<=size-1;i++){
			arr[i] = arr[i+1];
		}
		traversal(arr,size);
	}
}
void update(int arr[],int size){
	int value, ind;
	cout<<"Enter the index to update\n";
	cin>>ind;
	cout<<"Enter the updation you want\n";
	cin>>value;
	arr[ind]=value;
	traversal(arr,size);
}
void reverse(int arr[],int size){
	for(int i = 0;i<size/2;i++){
		int temp = arr[i];
		arr[i]=arr[size-(i+1)];
		arr[size-(i+1)]=temp;
	}
	traversal(arr,size);
}
void bubble_sort(int arr[],int size)
{
	int pass = size-1;
	int flag=0;
	for(int i=1;i<=pass;i++)
	{
		if(flag==0)
		{
flag = 1;
			for(int j =0;j<size-i;j++)
			{
				
				if(arr[j]>arr[j+1])
				{
					int temp = arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
					flag = 0;
				}
			}
//			cout<<"Pass"<<i<<endl; 
//			 for (int k = 0; k < size; k++) {
//            cout << arr[k] << " ";
//        }
//        cout << endl;
		}
		else
		{
			cout<< "List sorted!\n";
			break;
		}
	}
}
void search(int arr[],int size){
	string option;
	int tosearch;
	bool flag= false;
	cout<<"Choose Algorithm\na. Linear\nb. Binary\n";
	cin>>option;
	if(option=="a"){
		cout<<"What you want to search?\n";
		cin>>tosearch;
		for(int i=0;i<size;i++){
			if(arr[i]==tosearch){
				cout<<tosearch<<" Found at index "<<i<<endl;
				flag = true;
				break;
			}
		}
		if(flag=false){
			cout<<tosearch<<" not found in given array."<<endl;
		}
	}
else if (option == "b") {
    bubble_sort(arr, size);
    cout << "What you want to search?\n";
    cin >> tosearch;
    int start = 0;
    int end = size - 1;
    for(int i=start;i<=end;i++) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == tosearch) {
        	flag = true;
            cout << tosearch << " found at index " << mid << " after sorting.";
            break;;
        } else if (arr[mid] < tosearch) {
            start = mid + 1; 
        } else {
            end = mid - 1; 
        }
    }
   if(flag=false){
			cout<<tosearch<<" not found in given array."<<endl;
		}
}
	else{
		cout<<"Invalid option taken."<<endl;
	}
}
void max_subarray_sum(int arr[], int size) {
    int max_sum = arr[0];
    int current_sum ;
    int end_i;
    string current_arr;
    string max_arr;

    for (int i = 0; i < size; ++i) {
    	current_sum=arr[i];
    	stringstream ss;
    	ss << arr[i];
    	string s = ss.str();
    	current_arr = s+" ";
    	if(i==0){
    		end_i = size-1;
    	}
    	else{
    		end_i = size;
		}
    	for(int j=i+1;j<end_i;j++){
    		current_sum +=arr[j];
    		stringstream ss;
    		ss << arr[j];
    		string s = ss.str();
    		current_arr = current_arr+s+" ";
    		if(current_sum>max_sum){
    			max_sum = current_sum;
    			max_arr=current_arr;
			}
		}
	}
	cout<<"Max sum of subArray is "<<max_sum<<endl;
	cout<<"Max sub array is "<<max_arr;
}
int main(){
	int a = 5;
	int arr[a] = {9,7,0,0,2};
	cout<< "Take option\n1. Traversal\n2. Insertion\n3. Deletion\n4. Updation\n5. Reverse it\n6. Apply algorithm\n7. Max sub Array\n";
	int b;
	cin>>b;
	if(b==1){
		traversal(arr,a);
	}
	else if(b==2){
		insertion(arr,a);
	}
	else if(b==3){
		del(arr,a);
	}
	else if(b==4){
		update(arr,a);
	}
	else if(b==5){
		reverse(arr,a);
	}
	else if(b==6){
		search(arr,a);
	}
	else if(b==7){
		max_subarray_sum(arr,a);
	}
	else{
		cout<<"Invalid option taken."<<endl;
	}
	
	return 0;
}


