#include <iostream>
#include "../src/SRM2.cpp"
using namespace std;

int main() {
  
  int ex = 1, poi = 2, pool = 2;
  FountainOfLife f;
  cout.precision(9);
  cout << std::fixed;
  cout << "Time: " << f.exilerOfDeath(ex, poi, pool) << endl;
  ex = 40, poi = 43, pool = 41;
  cout << "Time: " << f.exilerOfDeath(ex, poi, pool) << endl;
  ex = 1, poi = 10000, pool = 1;
  cout << std::scientific;
  cout << "Time: " << f.exilerOfDeath(ex, poi, pool) << endl;
  ApocalypseSomeday a;
  cout << "Nth: " << a.getNthBrute(500) << endl;
  Wizarding w;
  cout << "Wizarding:" << w.counterspell("AA", "Z-------------------------") << endl;
    cout << "Wizarding:" <<
      w.counterspell("ABCDE", "ZYXXYXZZXYXXZZXZYYXZZZX---") << endl;
    cout << "Wizarding:" <<
      w.counterspell("ABCDEABCDEABC", "ACBDESKADSLOEDDDASDBADEDAE") << endl;

}
