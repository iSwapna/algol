#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream in(("dat.txt");
  string str;
  getline(in,str);
  while(in) {
    cout << str << endl;
    getline(in, str);
  }
  ofstream out("outDat.txt", ios::noreplace);
  

}

