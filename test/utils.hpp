#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

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
  int randNum(int end = 10) {
    Random r;
    return r.drawNum(0, end);
  }
  std::vector<int> getUniquesArr(int len, int end = 10) {
    std::vector<int> res;
    Random r;
    int i = 0;
    std::set<int> inList;
    while(i < len) {
      int item = r.drawNum(0,end);
      if(inList.find(item) == inList.end()){
	inList.insert(item);
	res.emplace_back(item);
	i++;
      }
    }
    return res;
  }
  std::vector<int> getArr(int len, int end = 10) {
    
    std::vector<int> res;
    Random r;
    for(int i = 0; i < len; i++) {
      res.emplace_back(r.drawNum(0, end));
    }
    return res;
  }

  std::vector<int> getArrSorted(int len, int end = 10) {
    std::vector<int> arr = getArr(len, end);
    std::sort(arr.begin(), arr.end());
    return arr;

  }

  template <typename T>
  void printBinary(const T& data) {
    size_t bytes = CHAR_BIT * sizeof(data);
    switch(bytes) {
    case 8:
      std::cout << std::bitset<8>(data) << std::endl;
      break;
    case 16:
      std::cout << std::bitset<16>(data) << std::endl;
      break;
    case 32:
      std::cout << std::bitset<32>(data) << std::endl;
      break;
    case 64:
      std::cout << std::bitset<64>(data) << std::endl;
      break;
    default:
      std::cout << "NON Standard Sz obj!!" << std::endl;
    }
  }

  //template specialization for float
  //should work for x86 
  template <>
  void printBinary(const float& data) {
    std::uint32_t result = 0;
    static_assert(sizeof(float) == sizeof(result), "float is not 32 bits");
    constexpr auto size = sizeof(float);
    std::uint8_t buffer[size] = {};
    // memcpy through a byte buffer to satisfy
    // the strict aliasing rule. This does not affect
    // performance since memcpy is 'magic'
    std::memcpy(buffer, std::addressof(data), size);
    std::memcpy(std::addressof(result), buffer, size);
    std::cout << std::bitset<32>(result) << std::endl;
    
    return;
  }
  template <typename T>
  void printMemory(const T& data) {
    const char* begin = reinterpret_cast<const char*>(&data);
    const char* end = begin + sizeof(data);
    while(begin != end)
      std::cout << std::bitset<CHAR_BIT>(*begin++) << " ";
    std::cout << std::endl;
  }
  
} // astd
  
