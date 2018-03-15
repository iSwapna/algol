#include <iostream>
#include <thread>
using namespace std;

void hello() {
  cout << "Hello from a lightweight flying carpet..." << endl;
}

int main() {
  thread th(hello), th2(hello); // RAII!
  th.join(); // main wait for th to finish
  th2.join();
}
