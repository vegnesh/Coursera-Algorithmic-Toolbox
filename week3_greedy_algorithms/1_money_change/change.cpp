#include <iostream>

int get_change(int m) {
  //write your code here
  int n = m/10 + (m%10)/5 + (m%10)%5;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
