/*
 *
 * Some interesting problems
 *
 */

#include <iostream>
#include <set>
#include <map>

using std::set;
using std::string;
using std::cout;
using std::endl;

/*
 * Find minimum lenght of substring of 's', 
 * containing all characters in 'a'. 'a' does not contain duplicates.
 * String 's' includes at least a single occurence of each character in 'a'
 */
int findLen(string s, string alpha) {
  int len = s.size();
  set<char> seen;
  for(int start = 0; start < s.size() - alpha.size() + 1; ++start) {
    seen.clear();
    for(int i = start; i < s.size(); ++i) {
      seen.insert(s[i]);
      if(seen.size() == alpha.size()) {
	int currLen = i - start + 1;
	if(currLen < len)
	  len = currLen;
	break;
      }
    }
  }
  
  return len;
}

int main() {

  std::cout << findLen("abbbbccbbcca", "abc") << std::endl;
  std::cout << findLen("abbbabccbbcca", "abc") << std::endl;
  std::cout << findLen("abbbb", "ab") << std::endl;
}

  
