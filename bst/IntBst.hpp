/******************************************
*
*	@BST.hpp 
*		'implementation for int Key, Value pair'
*
*	@author Swapna Iyer 
*	@date 07/31/2014
*
******************************************/

class Node {
	
	Node* left;
	Node* right;
	Node* parent;
	int key;
	int val;
	int count;

	Node(int k, int v): key(k), val(v), count(1), left(NULL), 
						right(NULL), parent(NULL) {}
	friend class Bst;
};

class Bst {

	Node* root;

	public:
		Bst(){root = NULL;} //if root not init-ed, sz will segfault!!
		int size();
		void insert(int k, int v);
		bool find(int k, int& v);	
		int min(int& val);
		int max(int& val);
		int rank(int key);
		int sum(int min, int max);

	private:
		int size(Node* node) {
			if(node == NULL) return 0;
			return node->count;
		}	

		Node* put(Node* node, int k, int v);
		int sum(Node* node, int minKey, int maxKey);
		int rank(Node* node, int key);
};



