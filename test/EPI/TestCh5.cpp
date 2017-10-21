#include "../utils.hpp"
#include "../../EPI/ch5.cpp"

using std::cout;
using std::endl;
int main() {

  cout << "running EPI ch5 test: " << endl;

  int num = astd::randNum(10);
  astd::printMemory<int>(num);
  astd::printBinary<int>(num);
  astd::printBinary<float>(32.5);
  cout << "num: " << num << " :parity: " << parity(num) << endl;
 

}
