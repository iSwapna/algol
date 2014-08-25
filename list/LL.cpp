
/**
*
*	@LL.cpp
*		CLASSIC LINKED LIST STUFF
*
*	@author	Swapna Iyer 
*	@date 08/09/2014
*
**/

#include <iostream>

using namespace std;

class Node {

		int data;
		Node* next;

	public:
 		Node(): next(NULL), data(0) {};	
 		Node(int d): next(NULL), data(d) {};	
		void setData(int d){ data = d; }; 
		
	friend class LL;

};

class LL {

		Node* head;
		Node* tail;
		int size;

	public:
		LL(): head(NULL), tail(NULL), size(0) {};	
		void insert(int data);
		bool lookup(int data);
		bool remove(int data);
		int getSize() { return size; }
		void printLL();
};

void LL::printLL() {

	cout << endl;
	cout << "LL: SIZE :" << getSize() << endl;
	Node* node = head;

	int i = 1;
	while(node != NULL) {
		cout << "idx: " << i++ << " val:" << node->data << endl;
		node = node->next;
	}
}

void LL::insert(int d) {

	Node* newNode = new Node(d);

	if(head == NULL){
		head = newNode;
		tail = newNode;

	} else {
		newNode->next = head;
		head = newNode;
	}
		size++;
		return;
	
}

bool LL::lookup(int d) {

	Node* node = head;

	while(node != NULL) {
		if(node->data == d) return true;
		node = node->next;
	}
	return false;
}

bool LL::remove(int d) {

	if( head == NULL) return false;
	Node* node = head->next;
	Node* prev = head;

	while(node!= NULL) {

		if(node->data == d) {
			prev->next = node->next;
			size--;
			delete node;
			return true;
		}
		node = node->next;
		prev = prev->next;
	}
	return false;
}

int main(int argc, char* argv[]) {

	LL ll;

	cout << ll.getSize() << endl;

	ll.insert(3);
	ll.insert(2);
	ll.insert(3);
	ll.printLL();
	 cout << "found 5: " <<ll.lookup(5) << endl;
	ll.insert(5);
	ll.printLL();
	 cout << "found 5: " <<ll.lookup(5) << endl;
	ll.remove(3);
	 cout << "found 3: " <<ll.lookup(3) << endl;
	ll.printLL();
	ll.remove(3);
	 cout << "found 3: " <<ll.lookup(3) << endl;
	ll.printLL();
	ll.insert(13);
	 cout << "found 3: " <<ll.lookup(3) << endl;
	ll.printLL();
}

