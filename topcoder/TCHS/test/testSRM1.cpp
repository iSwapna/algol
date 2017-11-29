#include <iostream>
#include "../src/SRM1.cpp"

using std::cout;
using std::endl;

int main() {
  int min = 1, max = 50;
  vector<int> arr{43, 50, 40};
  SpeedRadar s;
  cout << "min: " << min << " :max: " << max << endl;
  cout << s.averageSpeed(min, max, arr) << endl;
  arr = {42,43,44,45,46,47,48,49,50,51};
  cout << s.averageSpeed(min, max, arr) << endl;
  arr = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54};
  min = 20; max = 60;
  cout << s.averageSpeed(min, max, arr) << endl;




}
