#include <iostream>
#include <vector>
using namespace std;
/*
class Singleton {
  static Singleton* instance;
  Singleton() {
    cout << "called ctor!! " <<endl;
    val++;
  }
  static int val;
public:
  static Singleton* getInstance() {
    if(instance == nullptr)
      instance = new Singleton();
    return instance;
  }
  static int getVal() {
    return val;
  }
  static void incr() {
    val += 5;
  }
};

int Singleton::val = 0;
*/

class intI {
public:
  int data;
  intI(int i=0):data(i){}
  intI& operator=(intI a) {
    swap(data, a.data);
    return *this;;

  }

};
int main() {
  
  vector<intI> arr(2);

  for(int i = 0; i < 10; ++i) {
    arr[i] = intI(i);
  }
  for(auto &val: arr)
    cout << val.data << " ";

  cout << endl;
  
  /*
  cout << Singleton::getVal() << endl;
  Singleton::incr();
  cout << Singleton::getVal() << endl;
  */
}
