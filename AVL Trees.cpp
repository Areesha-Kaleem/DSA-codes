#include<iostream>
#include<conio.h>
using namespace std;
//struct for node in AVL trees
struct node
{
	int key;
	node* left;
	node* right;
	int height;		
};
//Code to generate new node
node* newNode(int key)
{
	node* n=new node();
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	n->height=1;
}
//To find height of node
int height(node* N)
{
	if(N==NULL)
	{
		return 0;
	}
	return N->height;
}
//To calculate balancing factor of node
int Balance_factor(node* N)
{
	if (N==NULL)
	{
		return 0;
	}
	return height(N->left)-height(N->right);
}
//max of levels = height of node
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
//Right rotation
node* right_rotation(node* p)
{
	node* c=p->left;
	node* T2=c->right;
	c->right=p;
	p->left=T2;
	
	p->height=max(height(p->left),height(p->right))+1;
	c->height=max(height(c->left),height(c->right))+1;
	cout<<"Right Rotation done"<<endl;
	return c;
}
//left rotation
node* left_rotation(node* p){
	node* c = p->right;
	node* T2 = c->left;
	c->left = p;
	p->right = T2;
	
	p->height=max(height(p->left),height(p->right))+1;
	c->height=max(height(c->left),height(c->right))+1;
	cout<<"Left Rotation done"<<endl;
	return c;
}
//Insert a node and check 4 cases of rotation
node* insert_Node(node* N, int key)
{
	if(N==NULL)
	{
		return(newNode(key));
	}
	if(key<N->key)
	{
		N->left=insert_Node(N->left,key);
	}
	else if(key>N->key)
	{
		N->right=insert_Node(N->right,key);
	}
	//height updated
	N->height = 1 + max(height(N->left),height(N->right));
	//balancing factor checked
	
	int BF = Balance_factor(N);
	//4 cases for rotation
	if(BF>1)
	{
		if(key<N->left->key)
		{
			return right_rotation(N);
		}
		else if(key>N->left->key)
		{
			N->left = left_rotation(N->left);
			return right_rotation(N);
		}
	}
	if(BF<-1)
	{
		if(key<N->right->key)
		{
			N->right = right_rotation(N->right);
			return left_rotation(N);
		}
		else if(key>N->right->key)
		{
			return left_rotation(N);
		}
	}
	return N;
}
//search node address of the specific key
node* search(node* N, int key)
{
	bool flag = false;
	while(N != NULL)
	{
		if(key == N->key)
		{
			return N;	
		}
		else if(N->key > key)
		{
			N = N->left;
		}
		else if(N->key < key)
		{
			N = N->right;
		}
	}
	flag = true;
	if(flag)
	{
		cout<<"Key doesn't exist in the tree. \n";
		return NULL;
	}
}
//minimum of tree 
node* minimum(node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
//delete a node and check 4 cases of rotation
node* delete_node(node* N, int key) {
    if (N == NULL)
        return N;

    if (key < N->key)
        N->left = delete_node(N->left, key);
    else if (key > N->key)
        N->right = delete_node(N->right, key);
    else {
        if (N->left == NULL) {
            node* temp = N->right;
            delete N;
            return temp;
        }
        else if (N->right == NULL) {
            node* temp = N->left;
            delete N;
            return temp;
        }
        node* temp = minimum(N->right);
        N->key = temp->key;
        N->right = delete_node(N->right, temp->key);
    }

    // Update height of the current node
    N->height = 1 + max(height(N->left), height(N->right));

    // Calculate balance factor of the current node
    int BF = Balance_factor(N);

    // Balance the tree if needed
    if (BF > 1 && Balance_factor(N->left) >= 0)
        return right_rotation(N);
    
    if (BF < -1 && Balance_factor(N->right) <= 0)
        return left_rotation(N);
    
    if (BF > 1 && Balance_factor(N->left) < 0) {
        N->left = left_rotation(N->left);
        return right_rotation(N);
    }

    if (BF < -1 && Balance_factor(N->right) > 0) {
        N->right = right_rotation(N->right);
        return left_rotation(N);
    }

    return N;
}

// Functions to traverse
void traverse_InOrder(node* root) {
	if (root != NULL) {
        traverse_InOrder(root->left);
        cout << root->key << " ";
        traverse_InOrder(root->right);
	}	
}
void traverse_PreOrder(node* root){
	if(root != NULL){
		cout << root->key << " ";
		traverse_PreOrder(root->left);
		traverse_PreOrder(root->right);
	}
}
void traverse_PostOrder(node* root){
	if(root != NULL){
		traverse_PostOrder(root->left);
		traverse_PostOrder(root->right);
		cout<< root->key << " ";
	}
}
int main()
{
	cout << "*************************************************" << endl;
cout << "*              Welcome to AVL TREES               *" << endl;
cout << "*              Made by Areesha Kaleem              *" << endl;
cout << "*              Roll no: 2022-CE-15                    *" << endl;
cout << "* This code can perform the following AVL Trees functions.*" << endl;
cout << "*     1) Insert                                               *" << endl;
cout << "*     2) Traverse                                          *" << endl;
cout << "*     3) Delete a node                                  *" << endl;
cout << "*     4) All type of rotations                       *" << endl;
cout << "*     5) Height of node                            *" << endl;
cout << "*     6) Balancing fcator of node                   *" << endl;
cout << "*     7) Search a node address by key value           *" << endl;
cout << "*     8) Minimum of tree                                *" << endl;
cout << "*******************************************************" << endl;
	node* N = NULL;
	int opt;
	int key;
	node* root; 
	while(true){
		cout<<"Menu:\n 1)Insert\n 2)Height of subtree\n 3)Balance Factor of any node\n 4)Delete Node\n 5)Traverse\n 6)Exit\n Choose one: ";
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"Enter the value to insert: ";
				cin>>key;
				N = insert_Node(N,key);
				cout<<"Inserted"<<endl;	
				break;
			case 2:
				if(N!=NULL){
					cout<<"Enter the value of root node of subtree: ";
					cin>>key;	
					root = search(N,key); 
					if(root != NULL) {
						int h;
						h = height(root);
						cout<<"Height of "<<key<<" = "<<h<<endl;
					}
				}
				else{
					cout<<"Insert in tree first"<<endl;
				}
				break;
			case 3:
				if(N!=NULL){
					cout<<"Enter the value of node: ";
					cin>>key;	
					root = search(N,key);
					if(root != NULL) {
						int b;
						b = Balance_factor(root);
						cout<<"Balance factor of "<<key<<" = "<<b<<endl;
					}
				}
				else{
					cout<<"Insert in tree first"<<endl;
				}
				break;
			case 4:
				int key;
				cout << "Enter the node value to delete: ";
	            cin >>key;
	            N = delete_node(N, key);
				break;
			case 5:
				int op;
				cout<<"Traversal in order:\n 1)In-Order\n 2)Pre-Order\n 3)Post-Order\nChoose one: ";
				cin>>op;
				if(op == 1){
			        cout << "In-order traversal: ";
			        traverse_InOrder(N);
			        cout << endl;
			    }
			    else if(op == 2){
			    	cout << "Pre-order traversal: ";
			        traverse_PreOrder(N);
			        cout << endl;
				}
				else if(op == 3){
					cout << "Post-order traversal: ";
			        traverse_PostOrder(N);
			        cout << endl;
				}
				else{
					cout<<"Invalid Option"<<endl;
				}
				break;	
			case 6:
				return 0;	
		}
	}
}
