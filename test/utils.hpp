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
  using uint32 = unsigned int;
  
  class Random {
  public:
    Random() = default;
    Random(std::mt19937::result_type seed): eng(seed) {}
    uint32 drawNum(uint32 start = 0, uint32 end = UINT32_MAX);
  private:
    std::mt19937 eng{std::random_device{} () };
  };
  
  uint32 Random::drawNum(uint32 start, uint32 end) {
    return std::uniform_int_distribution<uint32>{start, end}(eng);
  }
  
  std::vector<uint32> getArr(int len, int end = 10) {
    
    std::vector<uint32> res;
    Random r;
    for(int i = 0; i < len; i++) {
      res.push_back(r.drawNum(0, end));
    }
    return res;
  }
  
} // astd
  
