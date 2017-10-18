#include <iostream>
#include <vector>
#include <random>
namespace astd {
  template <typename T> void print(std::vector<T> arr) {
    std::cout << "Arr values: " ;
    for(auto& item: arr)
      std::cout << item << " ";
    std::cout << std::endl;
  }
  class Random {
  public:
    Random() = default;
    Random(std::mt19937::result_type seed): eng(seed) {}
    int drawNum(int start = 0, int end = INT_MAX);
  private:
    std::mt19937 eng{std::random_device{} () };
  };
  
  int Random::drawNum(int start, int end) {
    return std::uniform_int_distribution<int>{start, end}(eng);
  }
  
  std::vector<int> getArr(int len, int end = 10) {
    
    std::vector<int> res;
    Random r;
    for(int i = 0; i < len; i++) {
      res.push_back(r.drawNum(0, end));
    }
    return res;
  }
  
} // astd
  
