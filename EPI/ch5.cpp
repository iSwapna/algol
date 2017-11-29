/*
*  Chapter 5 of EPI
*  Primitives
*/

#include <iostream>

short parity(unsigned long x) {

  short res = 0;

  while(x) {
    res ^= 1;
    x &= (x - 1);

  }
  return res;
}

