#include <iostream>
#include <vector>
#include <random>

#include "sort.hpp"

int main() {

  std::cout << "running simple sort test: " << std::endl;
  std::vector<uint> arr = astd::getArr(6, 6);
  astd::print(arr);
  astd::insertion(arr);
  std::cout << "Insertion Sort: -->" << std::endl;
  astd::print(arr);
  arr = astd::getArr(6, 6);
  astd::print(arr);
  std::cout << "\nBubble Sort: -->" << std::endl;
  astd::bubble(arr);
  astd::print(arr);
  arr = astd::getArr(6, 6);
  astd::print(arr);
  std::cout << "\nMerge Sort: -->" << std::endl;
  astd::mSort(arr);
  astd::print(arr);
  arr = astd::getArr(6, 6);
  //arr = {1, 5, 6, 1, 1, 3}; 
  astd::print(arr);
  std::cout << "\nQuick Sort: -->" << std::endl;
  astd::qSort(arr);
  astd::print(arr);

}
