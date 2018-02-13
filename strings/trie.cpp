#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

struct Node {
  bool isEnd;
  vector<unique_ptr<Node>> children;
  set<int> position;
  Node(int symSz=36,
       bool end=false):isEnd(end), children(symSz) {
    position.clear();
  }
};

int mapSym(char ch) {
    if(ch >= '0' && ch <= '9')
      return ch - '0' + 26;
    else
      return ch - 'a';
}

class Trie {
public:
  Trie() {
    root = make_unique<Node>(Node());
  }
  void insert(string wrd, set<int>& pos) {
    Node* curr = root.get();
    for(auto &ch: wrd) {
      int idx = mapSym(ch);
      if(curr->children[idx] == nullptr)
	curr->children[idx] = make_unique<Node>(Node());
      curr = curr->children[idx].get();
    }
    curr->isEnd = true;
    curr->position = pos;
  }
  bool find(string wrd, set<int>& pos) {
    Node* curr;
    curr = root.get();
    for(auto &ch: wrd) {
      int idx = mapSym(ch);
      if(!curr->children[idx])
	return false;
      curr = curr->children[idx].get();
    }
    if(curr->isEnd == false)
      return false;
    pos = curr->position;
    return true;
  }

private:
  unique_ptr<Node> root;
};
int main() {

  Trie trie;
  vector<string> dict{"more", "abd", "34", "all"};
  int rnd = 3;
  for(auto &str: dict) {
    set<int> ps{rnd+3, rnd+6, rnd++};
    trie.insert(str, ps);
  }
  set<int> pos;
  vector<string> searchFor{"34", "abdd", "more", "bla2"};
  for(auto &str: searchFor) {
    pos.clear();
    if(trie.find(str, pos)) {
      cout << "Found: <" << str << "> at positions: ";
      for(auto &p: pos)
	cout <<  p << " ";
      cout << endl;
    }
    else
      cout << "Not found in dict: <" << str << ">" << endl;
  }
}
