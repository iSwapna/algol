#include <iostream>

using namespace std;

template <class Key,
	  class Val,
	  class Hash = std::hash<Key>,
	  class KeyEqual = std::equal_to<Key>,
	  >
class hash_table {

  typedef pair<Key, Value> data;
private:
  vector<*list<data>> table;
  int sz;

public:

  hash_table(int sz = 10);
  
  bool insert(Key k, Val v);

  iterator find(Key k);

  bool delete(Key k);

};

