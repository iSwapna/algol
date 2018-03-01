#include <iostream>
#include <vector>
using namespace std;
void resize(int* in, int ix, int iy,
	    int* out, int ox, int oy) {
  for(int i = 0; i < ox; ++i) {
    for(int j = 0; j < oy; ++j) {
      int sx, sy;
      sx = ix*i/ox; sy = iy*j/oy;
      cout <<"sx: " << sx << " sy: " << sy << endl;
      cout << "i: " << i << " j: " << j << endl;
      out[i*oy+j] = in[sx*iy+sy];
    }
  }
}
void pprint(int* arr, int x, int y) {
  for(int i = 0; i < x*y; ++i) {
      cout << arr[i] << ",";
  }
  cout << endl;
}
int main() {
  int input[3*6] = {1,2,3,4,5,1, 
		    6,7,8,9,10,6,
		    1,2,3,4,5,1};
  int output[2*3];
  int* in = input;
  int* out = output;
  resize(in, 3, 6, out, 2, 3);
  pprint(in, 3, 6);
  pprint(out, 2, 3);
}
