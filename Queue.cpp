#include <iostream>
#include <conio.h>
using namespace std;

struct Queue {
    int f;
    int r;
    int size;
    int* arr;
};

void createqueue(struct Queue* q) {
    q->f = -1;
    q->r = -1;
    cout << "Enter the size of array: ";
    cin >> q->size;
    q->arr = new int[q->size];
}

bool isEmpty(struct Queue* q) {
    if (q->f==-1) {
        cout << "Queue is empty" << endl;
        return true;
    } else {
        return false;
    }
}

bool isFull(struct Queue* q) {
    if ((q->r + 1) % q->size == q->f) {
        cout << "Queue is Full" << endl;
        return true;
    } else {
        return false;
    }
}

void Enqueue(struct Queue* q) {
    if (isFull(q)) {
        return;
    }

    if (q->f == -1) {  
        q->f = q->r = 0;
    } else {
        q->r = (q->r + 1) % q->size;
    }
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    q->arr[q->r] = data;
    cout << data << " Enqueued!" << endl;
    cout<<endl;
}

void Dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return;
    }

    int data = q->arr[q->f];

    if (q->f == q->r) {  
        q->f = q->r = -1;
    } else {
        q->f = (q->f + 1) % q->size;
    }
    cout << data << " Dequeued from queue" << endl;
    cout<<endl;
}

void FirstElement(struct Queue* q) {
    if (!isEmpty(q)) {
        cout << "The First in the line is " << q->arr[q->f] << endl;
    }
    else{
    	return;
	}
}

void LastElement(struct Queue* q) {
    if (!isEmpty(q)) {
//        int last_index = (q->r + q->size) % q->size;
        cout << "The Last in the line is " << q->arr[q->r] << endl;
    } else {
        return;
    }
}

void peek(struct Queue* q) {
    if (isEmpty(q)) {
        cout << "No where to peek" << endl;
        return;
    } else {
        int index;
        cout << "Enter the index you want to peek at: ";
        cin >> index;
        if (index >= q->f && index <= q->r) {
            cout << "Peek-a-boo hehe!" << endl;
            cout << q->arr[index] << endl;
        } else {
            cout << "Invalid index" << endl;
        }
    }
}

void display(struct Queue* q) {
 	if (isEmpty(q)) {
        return;
    }
    int option;
	cout<<"Which direction to move\n 1)Forward\n 2)Reverse\n";
	cin>>option;
	if(option == 1){
	    int i = q->f;
	    cout<<"Moving Forward...\n";
	    while(true)
	    {
	    	if(i == q->r)
	    	{
	    		cout << q->arr[i] << " ";
	    		break;
			}
			cout << q->arr[i] << " ";
			i = (i + 1) % q->size;
		}
	    cout << endl;
	}
	else{
	    int reverse_i = q->r;
	    cout<<"Moving Backwards...\n";
		while (reverse_i != q->f) {
		    cout << q->arr[reverse_i] << " ";
		    reverse_i = (reverse_i - 1 + q->size) % q->size;
		}
		cout << q->arr[q->f] << endl;
	}
}


int main() {
    struct Queue q;
    createqueue(&q);
    int option;
    while (true) {
        cout << "1)Enqueue \n2)Dequeue \n3)IsEmpty \n4)IsFull \n5)Peek In \n6)Display \n7)First Element \n8)Last Element \n9)Exit \nChoose: ";
        cin >> option;
        if (option == 1) {
            Enqueue(&q);
        } 
		else if (option == 2) {
            Dequeue(&q);
        } 
		else if (option == 3) {
            bool ans = isEmpty(&q);
            if (ans == false) {
                cout << "Queue is not Empty" << endl;
            }
        } 
		else if (option == 4) {
            bool anss = isFull(&q);
            if (anss == false) {
                cout << "Queue is not full" << endl;
            }
        } 
		else if (option == 5) {
            peek(&q);
        } 
		else if (option == 6) {
            display(&q);
        } 
		else if (option == 7) {
            FirstElement(&q);
        } 
		else if (option == 8) {
            LastElement(&q);
        } 
		else if (option == 9) {
            delete[] q.arr; 
            break;
        } 
		else {
            cout << "Invalid option" << endl;
        }
    }
    return 0;
}
