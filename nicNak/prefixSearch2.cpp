// INCOMPLETE 
// find strings with prefix in a list L
// len(prefix) - p, len(List) = N, len(word) = M
// sorting - O(NM(logN)), bin searching - O(plogN)


// eg: prefix = "ba", L = {"bat", "bar", "batch",
//                          "cat", "cart", "car"}

// sort, then do bin search for start and end,
// per char in prefix!!

// never assume 26 alpha set
// trie: the HASHMAP of next nodes is IMP O(1) lookup
/*
  class TrieNode(object):
      def __init__(self, val)
        self.wordEnding = False
	self.children = {}
	hashMap<char, TrieNode*>

  class Trie(object):
      def __init__(self):
        self.root = TrieNode("")
      def addNode(seld, word):

 */
#include <iostream>
#include <unordered_map>

class TrieNode {

  bool wordEnding;
  unordered_map<char, TrieNode*> children;
public:
  TrieNode():wordEnding(false) {};

};


class Trie {

  TrieNode root;

public:
  
  
  void addWord(string wrd) {

  }
  
  bool isWord(string wrd) {


  }
  // to make the trie - O(NM), to find k words that match O(p+kM)
  vector<string> findWordsWithPrefix(string pre) {
    vector<string> res;
    int idx = 0;
    TrieNode* curr = root;
    while(idx < pre.size()) {
      auto iter = curr->children.find(pre[idx]);
      if(iter != curr->children.end())
	

    }
    // recursion is better...
    queue<TrieNode*> nextNodes = root;

    while(!nextNodes.empty()) {
      TrieNode* curr = nextNodes.top()
	if(curr->children.find(pre[idx])) {


	}


    }
    return res;
  }
};

// q 3- find all words that matches "abc.c.ef"
// res set is a ref passed in from a wrapper

vector<string> findAll(string pre, string curr,
		       vector<string>& res, TireNode* node, int idx = 0) {

  if(curr.size() == pre.size() && node.ending) {
    res.push_back(curr);
    return res;
  }


}
