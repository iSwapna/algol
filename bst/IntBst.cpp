/**
*
*	@Bst.cpp 
*		'implementation file of Bst'
*
*	@author Swapna Iyer
*	@date 07/31/2014
*
**/

#include<iostream>
#include<vector>
#include "IntBst.hpp"

using namespace std;

// find size of bst
int Bst::size() {
	return size(root);
}

//insert key k value v pair
void Bst::insert(int k, int v) {
	root = put(root, k, v);
}

Node* Bst::put(Node* node, int k, int v) {
	if(node == NULL) return new Node(k, v);
	if(node->key > k) {
		node->left = put(node->left, k, v);
	} else if(node->key < k) {
		node->right = put(node->right, k, v);
	} else  
		node->val = v;

	node->count = 1 + (size(node->left) + size(node->right));
	return node;
} 

//find key k 
bool Bst::find(int k, int& v) {

	Node* node = root;
	while(node != NULL) {
		if(node->key > k) 
			node = node->left;
		else if(node->key < k)
			node = node->right;
		else {
			v = node->val;
			return true;
		} 
	}
	return false;
}

//find max val in tree
int Bst::min(int& val) {

	Node* node = root;
	if (node == NULL) return -99;

	while(node->left != NULL)
		node = node->left;

	val = node->val;
	return node->key;
}
//find max val in tree
int Bst::max(int& val) {

	Node* node = root;

	if (node == NULL) return -99;
	while(node->right != NULL) 
		node = node->right;

	val = node->val;
	return node->key;
}

//rank of key- how many keys below this key
int Bst::rank(int key) {

	Node* node = root;
	return rank(node, key);

}

int Bst::rank(Node* node, int key) {

	if(node == NULL) return 0;
	if(node->key > key) {
		return rank(node->left, key);
	} else if(node->key < key) {
		return 1 + size(node->left) + rank(node->right, key);
	} else
		return size(node->left);
}

// sum of all values in range [min, max] in tree
int Bst::sum(int min, int max) {

	Node* node = root;
	return sum(root, min, max);
}

int Bst::sum(Node* node, int min, int max) {

	if(node == NULL) return 0;

	if(node->key > min && node->key < max) {
	return node->val + sum(node->right, min, max) + sum(node->left, min, max);
	} else if(node->key <= min)
		return sum(node->right, min, max);
	else //node->key >= max 
		return sum(node->left, min, max);
}

int main() {

	cout << "main" << endl;
	Bst bst;
	int min, max, val = 0;
	
	int SIZE = 8;
	cout << "sz: " << bst.size() << endl;

	int keys[] =   { 10,  14,  3,  5,  6,  17,  12, 13};
	int values[] = {100, 140, 30, 25, 46, 17, 112,  3};

	for(int i = 0; i < SIZE; ++i) {
	
		bst.insert(keys[i], values[i]);

		bool found = bst.find(keys[i], val);
	cout << "After insert, found: " << found << " val: " << val << endl;
		cout << "sz: " << bst.size() << endl;
		min = bst.min(val); 
		cout << "min: " << bst.min(val) << ":" << val << endl;
		max = bst.max(val); 
		cout << "max: " << bst.max(val) << ":" << val << endl;
	}

	cout << "sum from 5 to 13: " << bst.sum(5, 13) << endl;
	cout << "sum from 25 to 123: " << bst.sum(25, 123) << endl;
	cout << "sum from 0 to 11: " << bst.sum(0, 11) << endl;

}
