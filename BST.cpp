#include<iostream>
#include<conio.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};
//Function to insert
node* insert(node* root) {
    int data;
    if (root == NULL) {
        root = new node;
        cout << "Enter the data: ";
        cin >> root->data;
        root->left = root->right = NULL;
        cout << "Node inserted in tree" << endl;
        return root;
    }
    else {
        cout << "Enter the data: ";
        cin >> data;
        int n;
        node* temp;
        do {
            if (data > root->data) {
                temp = root;
                root = root->right;
                n = 1;
            }
            else if(data<root->data){
                temp = root;
                root = root->left;
                n = 2;
            }
            else if(data == root->data)
            {
            	cout<<"Node with this value already exists. \n";
            	return temp;
			}
        } while (root != NULL);
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        if (n == 1) {
            temp->right = root;
        }
        else {
            temp->left = root;
        }
        cout << "Node inserted in tree" << endl;
        return temp;
    }
}
// Functions to traverse
void traverse_InOrder(node* root) {
	if (root != NULL) {
        traverse_InOrder(root->left);
        cout << root->data << " ";
        traverse_InOrder(root->right);
	}	
}
void traverse_PreOrder(node* root){
	if(root != NULL){
		cout << root->data << " ";
		traverse_PreOrder(root->left);
		traverse_PreOrder(root->right);
	}
}
void traverse_PostOrder(node* root){
	if(root != NULL){
		traverse_PostOrder(root->left);
		traverse_PostOrder(root->right);
		cout<< root->data << " ";
	}
}
// Function to Search
int search(node* root){
	int tosearch;
	int level = 0;
	if(root==NULL){
		cout<<"Insert in Tree First"<<endl;
		return -1;
	}
	else{
		cout<<"Enter the data to search: ";
		cin>>tosearch;
		if(root->data==tosearch){
			return level;
		}
		else{
			do{
				level++;
				if(tosearch>root->data){
					root= root->right;
				}
				else{
					root = root->left;
				}
				if(root->data==tosearch){
					return level;
				}
			}
			while(root!=NULL);
			return -1;
		}
	}
}
// Function to find Minimum of tree
int Min(node* root) {
	if(root == NULL){
		cout<<"Tree is empty"<<endl;
	}
    while (root && root->left != NULL){
        root = root->left;
	}
    return root->data;
}
struct node* minimum(struct node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
// Function to find Maximum of tree
int Max(node* root){
	if(root == NULL){
		cout<<"Tree is empty"<<endl;
		return NULL;
	}
    while (root && root->right != NULL){
        root = root->right;
	}
    return root->data;
}

// Function to find the predecessor of a node in a BST
int Predecessor(node* root, int target) {
    int predecessor = 0; 
    while (root != NULL) {
        if (target == root->data) {
            if (root->left != NULL) {
                root = root->left;
                return Max(root);
            }
            break; 
        } else if (target > root->data) {
            predecessor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return predecessor;
}

// Function to find the successor of a node in a BST
int Successor(node* root, int target) {
    int successor = 0; 
    while (root != NULL) {
        if (target == root->data) {
            if (root->right != NULL) {
                root = root->right;
                return Min(root);
            }
            break; 
        } else if (target < root->data) {
            successor = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return successor;
}
// Function to delete a node from the BST
struct node* deleteNode(node*& root, int key) {
     if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get inorder successor (smallest in the right subtree)
        struct node* temp = minimum(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
cout << "************************************************" << endl;
cout << "*              Welcome to BST manipulations                *" << endl;
cout << "*                  Made by Areesha Kaleem                     *" << endl;
cout << "*                    Roll no: 2022-CE-15                          *" << endl;
cout << "* This code can perform the following functions on BST *" << endl;
cout << "*     1) Insert                                                  *" << endl;
cout << "*     2) Traverse                                             *" << endl;
cout << "*     3) Search                                                 *" << endl;
cout << "*     4) Minimum In Tree                                 *" << endl;
cout << "*     5) Maximum In Tree                                *" << endl;
cout << "*     6) Predecessor of node                          *" << endl;
cout << "*     7) Successor of node                              *" << endl;
cout << "*     8) Delete a node                                        *" << endl;
cout << "************************************************" << endl;

    node* root = NULL;
    node* temp = NULL;
    int option;
    int level;
    int target;
    int p;
    int s;
    int max;
    int min;
    while (true) {
        cout << "Menu:\n 1)Insert\n 2)Traverse\n 3)Search\n 4)Minimum In Tree\n 5)Maximum In Tree\n 6)Predecessor of node\n 7)Successor of node\n 8)Delete a node\n 9)Exit\nChoose: ";
        cin >> option;
        if (option == 1) {
            temp = insert(root);
            if(root == NULL){
            	root = temp;
			}
        }
        else if (option == 2) {
        	int opt;
        	if(root==NULL){
        		cout<<"Insert In Tree First"<<endl;
			}
			else{
				cout<<"Traversal in order:\n 1)In-Order\n 2)Pre-Order\n 3)Post-Order\nChoose one: ";
				cin>>opt;
				if(opt == 1){
			        cout << "In-order traversal: ";
			        traverse_InOrder(root);
			        cout << endl;
			    }
			    else if(opt == 2){
			    	cout << "Pre-order traversal: ";
			        traverse_PreOrder(root);
			        cout << endl;
				}
				else if(opt == 3){
					cout << "Post-order traversal: ";
			        traverse_PostOrder(root);
			        cout << endl;
				}
				else{
					cout<<"Invalid Option"<<endl;
				}
        	}
        }
        else if (option == 3) {
            level = search(root);
            if(level == -1){
            	cout<<"Not Found"<<endl;
			}
			else{
            	cout<<"Found at level = "<<level<<endl;
            }
        }
        else if(option == 4){
        	min = Min(root);
        	cout<<"Minimum data value in Tree is "<<min<<endl;
		}
		else if(option == 5){
			max = Max(root);
			cout<<"Maximum data value in Tree is "<<max<<endl;
		}
		else if(option == 6){
			cout<<"Enter the node data: ";
			cin>>target;
			p = Predecessor(root,target);
			cout<<"Predecessor of "<<target<<" is "<<p<<endl;
		}
		else if(option == 7){
			cout<<"Enter the node data: ";
			cin>>target;
			s = Successor(root,target);
			cout<<"Successor of "<<target<<" is "<<s<<endl;
		}
		else if(option == 8){
			cout << "Enter the node data to delete: ";
            cin >> target;
            root = deleteNode(root, target);
//            break;
			if(root==NULL){
				cout<<"Tree is empty"<<endl;
			}
			else{
				cout<<"Node deleted"<<endl;
			}
		}
		else if (option == 9){
			break;
		}
    }
    return 0;
}
