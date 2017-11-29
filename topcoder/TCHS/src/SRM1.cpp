#include <vector>
using std::vector;

class SpeedRadar {

public:
  double averageSpeed( int minLimit,
		       int maxLimit,
		       const vector<int>& readings) {
    int count = 0; double sum = 0.0;
    for(int i = 0; i < readings.size(); ++i) {
      if (readings[i] > minLimit && readings[i] <= maxLimit) 
	sum += readings[i];
      else
	++count;
    }
    std::cout << sum << ":" << count << std::endl;
    if(count * 10 > readings.size())
      return 0.0;
    else
      return (double)sum/(readings.size() - count);
	

  }
};
