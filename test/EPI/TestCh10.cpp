#include "../utils.hpp"
#include "../../EPI/ch10.cpp"
#include <algorithm>

int main() {

  std::cout << "running EPI ch10 test: " << std::endl;
  std::vector<std::vector<int>> S;
  for(int i = 0; i < 3; ++i) {
    std::vector<int> arr = astd::getArr(2, 5);
    std::sort(arr.begin(), arr.end());
    S.emplace_back(arr);
    astd::print(S[i]);
  }

  astd::print(mergeArrays(S));
  

}
