#include<iostream>
#include<conio.h>
#include<string>
#include<cctype>
#include<sstream>
using namespace std;
int stringToInt(string str) {
    int result = 0;
    for (int i = 0;i<str.length();i++) {
        // Check if the character is a digit
        if (isdigit(str[i])) {
            // Convert character to integer and accumulate the result
            result = result * 10 + (str[i] - '0');
        } else {
            // Handle error: non-digit character found
            cout << "Error: Non-digit character '" << str[i] << "' found in string." << endl;
            return 0; // Return 0 or handle error as appropriate
        }
    }
    return result;
}
int string_converter(string str) {
    int sum = 0;
    if (isdigit(str[0])) {
    	sum = stringToInt(str);
    	cout<<"Value of string = "<<sum<<endl;
    } else {
        for (int i=0;i<str.length();i++) {
            sum += static_cast<int>(str[i]);
        }
        cout<<"Value of string = "<<sum<<endl;
    }
    return sum;
}
int LinearProbing(int hash_ind,int probe,int hash_size){
	return (hash_ind+probe)%hash_size;
}
int quadraticProbing(int hash_ind,int probe,int hash_size){
	return (hash_ind+(probe*probe))%hash_size;
}
int doubleHashing(int hash_ind,int probe,int value,int hash_size){
	int hx2 = 7-(value%7);
	return (hash_ind+(probe*hx2))%hash_size;
}
double loadFactor(int noe, int size) {
    return double(noe) / size * 100;
}
int insert(string hashtable[], int hash_size, int index, string value, int x, int opt) {
    int p = 0;
    while (p < hash_size) { 
        if (index < hash_size && hashtable[index].empty()) {
            p++;
            hashtable[index] = value;
            cout << "Value inserted at slot = " << index << endl;
            break;
        } else {
            p++;
            // Handle collision resolution techniques
            if (opt == 1) {
                index = LinearProbing(index, p,hash_size);
            } else if (opt == 2) {
                index = quadraticProbing(index, p,hash_size);
            } else if (opt == 3) {
                index = doubleHashing(index, p, x,hash_size);
            }
        }
    }
    return p;
}
int Hfunc1(int x,int n){
	int hx = 0;
	hx = x % n;
	return hx;
}
int Hfunc2(int x) {
    int sq = x * x; 
    stringstream ss;
    ss << sq; // Convert int to string using stringstream
    string mid_sq = ss.str();
    int mid = mid_sq.length() / 2;
    return mid;
}
int modfunc(string arr[],int size,string hashtable[],int hash_size,int n){
	int x;
	int ind;
	int probes = 0;
	int opt;
	cout<<"If collision occurs which technique you wanna use to do insertion\n 1)Linear Probing\n 2)Quadratic Probing\n 3)Double Hashing\n choose one: ";
	cin>>opt;
	for(int i = 0;i<size;i++){
			x = string_converter(arr[i]);
			ind = Hfunc1(x,n);
			probes = insert(hashtable,hash_size,ind,arr[i],x,opt);
			cout<<"Value inserted in probes = "<<probes<<endl;
			cout << "Load Factor = " << loadFactor(i + 1, hash_size) << endl;
	}
	return opt;
}
int midsqfunc(string arr[],int size,string hashtable[],int hash_size){
	int x;
	int ind;
	int probe = 0;
	int opt;
	cout<<"If collision occurs which technique you wanna use to do insertion\n 1)Linear Probing\n 2)Quadratic Probing\n 3)Double Hashing\n choose one: ";
	cin>>opt;
	for(int i = 0;i<size;i++){
		x = string_converter(arr[i]);
		ind = Hfunc2(x);
		probe = insert(hashtable,hash_size,ind,arr[i],x,opt);
		cout<<"Value inserted in probes = "<<probe<<endl;
		cout << "Load Factor = " << loadFactor(i + 1, hash_size) << endl;
	}
	return opt;
}
void search(string hashtable[], int hash_size, int tofindvalue, int ind, string tofind, int tech) {
    int p = 0;
    while (p < hash_size && ind < hash_size) {
        if (hashtable[ind] == tofind) {
            cout << tofind << " found at " << ind << " in " << (p + 1) << " probes" << endl;
            return;
        } else {
            p++;
            if (tech == 1) {
                ind = LinearProbing(ind, p, hash_size);
            } else if (tech == 2) {
                ind = quadraticProbing(ind, p, hash_size);
            } else if (tech == 3) {
                ind = doubleHashing(ind, p, tofindvalue, hash_size);
            }
        }
    }
    // If element is not found after probing entire hash table
    cout << tofind << " not found in the hash table." << endl;
}
void SearchByModFunction(string hashtable[],int hash_size,int n,string tofind,int tech){
	int x;
	int ind;
	x = string_converter(tofind);
	ind = Hfunc1(x,n);
	search(hashtable,hash_size,x,ind,tofind,tech);	
}
void SearchByMidSqFunction(string hashtable[],int hash_size,string tofind,int tech){
	int x;
	int ind;
	x = string_converter(tofind);
	ind = Hfunc2(x);
	search(hashtable,hash_size,x,ind,tofind,tech);
}
int main()
{
	cout << "************************************" << endl;
	cout << "*  Welcome to Hashing Program      *" << endl;
	cout << "*  Made by Areesha Kaleem          *" << endl;
	cout << "*  Roll no: 2022-CE-15             *" << endl;
	cout << "*  Using Two Hash Functions        *" << endl;
	cout << "*     (Mod and Mid square)         *" << endl;
	cout << "*  Implementing Three Techniques   *" << endl;
	cout << "*  for Insertion and Search        *" << endl;
	cout << "************************************" << endl;

	int size = 10;
	string arr[size]={"10","22","54","OK","BYE","Hi","124","3","Arsh","102"};
	int opt;
	bool flag1 = false;
	bool flag2 = false;
	int techno1 = 0;
	int techno2 = 0;
	string tofind;
	string HT_1[size+1];
	string HT_2[size+1];
	while(true){
		cout<<"1)Insert\n2)Search\n3)Exit\nChoose one: ";
		cin>>opt;
		if(opt==2){
			if(flag1==true){
				cout<<"Enter the string to search: ";
				cin>>tofind;
				cout<<"By Mod Function"<<endl;
				SearchByModFunction(HT_1,size+1,11,tofind,techno1);
			}
			if(flag2==true){
				cout<<"Enter the string to search: ";
				cin>>tofind;
				cout<<"By Mid Square Function"<<endl;
				SearchByMidSqFunction(HT_2,size+1,tofind,techno2);
			}
			else{
				cout<<"First do insertion please!"<<endl;
			}
		}
		else if(opt==1){
			string table1[size+1];
            string table2[size+1];
            cout<<"Hashing using\n 1)Mod function\n 2)Mid square function\n 3)Both\nchoose: ";
            cin>>opt;
            if(opt == 1){
                techno1 = modfunc(arr, size, table1, size+1, 11);
                flag1 = true;
                // Copy the data from table1 to HT_1
                for(int i = 0; i < size+1; i++){
                    HT_1[i] = table1[i];
                }
            }
            else if(opt == 2){
                techno2 = midsqfunc(arr, size, table2, size+1);
                flag2 = true;
                // Copy the data from table2 to HT_2
                for(int i = 0; i < size+1; i++){
                    HT_2[i] = table2[i];
                }
            }
            else if(opt == 3){
                techno1 = modfunc(arr, size, table1, size+1, 11);
                flag1 = true;
                // Copy the data from table1 to HT_1
                for(int i = 0; i < size+1; i++){
                    HT_1[i] = table1[i];
                }
                
                techno2 = midsqfunc(arr, size, table2, size+1);
                flag2 = true;
                // Copy the data from table2 to HT_2
                for(int i = 0; i < size+1; i++){
                    HT_2[i] = table2[i];
                }
            }
			else{
				cout<<"Invalid option choosen!"<<endl;
			}
		}
		else if(opt==3){
			break;
		}
		else{
			cout<<"Invalid option!"<<endl;
		}
	}
	return 0;
}
