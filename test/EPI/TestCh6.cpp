#include "../utils.hpp"
#include "../../EPI/ch6.cpp"

using std::cout;
using std::endl;
int main() {

  cout << "running EPI ch6 test: " << endl;

  int num = astd::getArr(5);
  astd::printMemory<int>(num);
  astd::printBinary<int>(num);
  astd::printBinary<float>(32.5);
  cout << "num: " << num << " :parity: " << parity(num) << endl;
 

}
