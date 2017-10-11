/* TOPCODER 
   http://community.topcoder.com/stat?c=problem_statement&pm=3561&rd=6519
   Problem Name:	 SortEstimate
   Used In:	 SRM 230
   Used As:	 Division I Level One , Division II Level Two
   Categories:	 Math, Search

You have implemented a sorting algorithm that requires exactly c*n*lg(n) nanoseconds to sort n integers. Here lg denotes the base-2 logarithm. Given time nanoseconds, return the largest n such that c*n*lg(n) <= time.
Definition
Class: SortEstimate
Method: howMany
Parameters: int, int
Returns: double
Method signature: double howMany(int c, int time)

*/
#include <iostream>
#include <math.h>

class SortEstimate {
    
public:
    double howMany(int c, int time) {
      double hi = 2000000000; double lo = 1; double curr;  double num = 1;
      while((hi - lo) > 1e-9) {
	num = (hi + lo)/2;
	curr = c * num * (log(num) / log(2));
	std::cout << curr << std::endl;
	if(time == curr) {
	  std::cout << "returning.." << num << std::endl;
	  return num;
	}
	else if(curr > time) 
	  hi = num;
	else
	  lo = num;
      }
      return num;
    }// end
};

int main() {

  SortEstimate s;
  std::cout << s.howMany(1, 8) << " = " << 4.0 << std::endl;



}
