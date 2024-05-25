#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct node {
    string data;
    int weight_of_word;
    struct node* right;    
    struct node* left;
};

struct node* node_creation(int w, string d) {
    struct node* temp = new node;
    temp->data = d;
    temp->weight_of_word = w;
    temp->right = temp->left = NULL;
    return temp;
}

struct node* insert(struct node* root, int key, string word) {
    if (root == NULL) {
    	cout<<"Added to Dictionary"<<endl;
        return node_creation(key, word);
    }
    if (key < root->weight_of_word) {
        root->left = insert(root->left, key, word);
    } else if (key > root->weight_of_word) {
        root->right = insert(root->right, key, word);
    } else {
    	cout<<root->data<<" = "<<root->weight_of_word<<endl;
    	cout<<word<<" = "<<key<<endl;
        cout << "No insertion due to duplication." << endl;
    }
    return root;
}

void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

void spell_corrector(struct node* root, string str22) {
    static string fin = "";
    int r = 0;
    int hit = 0;
    if (root != NULL) {
        fin = root->data;
        if ((fin.size() - str22.size()) <= 2) {
            for (size_t o = 0; o < str22.size(); o++) {
                if (str22[o] == fin[o]) {
                    hit++;
                }
            }
        }
        int hitrate = ((hit * 100) / (str22.size()));
        if (hitrate >= 50) {
            cout <<"Suggested: "<< fin << endl;
        }
        spell_corrector(root->left, str22);
        spell_corrector(root->right, str22);
    }
}

int search(struct node* root, int ww, string str) {
    struct node* temp = root;
    int check1 = -1;
    while (root != NULL) {
        if (root->data == str) {
            check1++;
            break;
        } else if (root->weight_of_word < ww) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    if (check1 == 0) {
        cout << str << " Found in Dictionary"<<endl;
        return 1;
    } else {
        cout << str << " Not Found in Dictionary\n\n";
        spell_corrector(temp, str);
        return 2;
    }
}

int calculateWeight(string word) {
    int weight = 0;
    int sq;
    for (int j = 0; j < word.length(); j++) {
    	sq = (int(word[j]))*(int(word[j]));
        weight += sq;
    }
    return weight;
}

struct node* readFileAndInsert(struct node*& root) {
    ifstream file("Dictionary.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
    }
	int count;
    string word;
    int weight;
    while (getline(file, word)) {
        cout << "Inserting word: " << word << endl; 
        weight = calculateWeight(word);
        count++;
        root = insert(root, weight, word);  
    }
	cout<<"Total words in dictionary = "<<count<<endl;
    file.close();
    return root;
}
void WriteToFile(string word){
	ofstream file("Dictionary.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
    } else {
        file << word << endl; 
        file.close();
    }
}

int main() {
    cout << "Your Words Library" << endl;
    int opt;
    string word;
    int weight;
    int check;
    int opt1;
    struct node* root = NULL;
    root = readFileAndInsert(root);
    while (true) {
        cout << "Menu:\n 1)Search for a Word\n 2)Display Complete Words Library\n 3)Close\nChoose: ";
        cin >> opt;
        if (opt == 1) {
            cout << "Enter a word: ";
            cin >> word;
            weight = calculateWeight(word);
            check = search(root, weight, word);
            if (check == 2) {
                cout << "The word you were searching is in the suggestions?\n 1.Yes\n 2.Add to dictionary\n 3.Close\n Select: ";
                cin >> opt1;
                if (opt1 == 1) {
                    cout << "Glad to know!" << endl;
                } else if (opt1 == 2) {
                    root = insert(root, weight, word);
                    WriteToFile(word);
                } else if (opt1 == 3) {
                    cout << "Closing search menu." << endl;
                }
            }
        } else if (opt == 2) {
            cout << "Inorder Traversal of Words Library: ";
            inorder_traversal(root);
            cout << endl;
        }
        else if(opt == 3){
        	cout<<"Closing Words Library"<<endl;
        	break;
		}
    }
    return 0;
}

