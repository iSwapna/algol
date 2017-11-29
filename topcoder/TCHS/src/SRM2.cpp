#include <string>
using std::string;

class FountainOfLife {
public:
  double exilerOfDeath( int ex, int poi, int pool ) {
    if( ex >= poi ) return -1.0;
    return ( double( pool ) / ( poi - ex ) );
    
  }

};

class ApocalypseSomeday {
  
public:
  int getNthBrute(int n) {
    int i = 665;

    while(n) {
      i++;
      for(int k = i; k; k /= 10) {
	if(k % 1000 == 666) {
	  --n; break;
	}
      }
    }
    return i;
  }
  //tbd using pattern match
  int getNth(int n) {
    string base = "666", lt = "", rt = "";
    int ans;
    char ch = '0';
    while(n) {
      
    }
    return ans;
  }
};

class Wizarding {

public:
  string rules, spell;
  string resStr;
  int resPow = 0;
  
  void process(string curr) {
    int pow = 1;
    for(int i = 0; i < curr.size(); ++i)
      pow *= (curr[i] - 'A' + 1);
    pow %= 77077;

    if(pow > resPow) {
      resPow = pow;
      resStr = curr;
      return;
    }
    if(pow < resPow) return;
    if(curr.size() < resStr.size())
      resStr = curr;
    else if(curr.size() == resStr.size() &&
	    std::lexicographical_compare(curr.begin(), resStr.begin(),
					 curr.end(), resStr.end()))
      resStr = curr;
  }
    
  void find(string curr = "", int depth = 0) {
    //std::cout <<"Find: depth: " << depth << std::endl;
    if(depth == spell.size()) {
      if(curr == "") return;
      process(curr);
      return;
    }
    find(curr + spell[depth], depth + 1);
    find(curr, depth + 1);
    char rep = rules[spell[depth] - 'A'];
    if(rep != '-')
      find(curr + rep, depth + 1);
  }
  string counterspell(string s, string r) {

    rules = r; spell = s;
    resPow = -1; resStr = "";
    find();
    return resStr;
  }
};
