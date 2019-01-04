#include <iostream>
#include <math.h>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<long> &a, long x) {
  int left = 0, right = (int)a.size();
  int index;

  if(right == 0)
    return -1;

  //write your code here
  
  while(left<=right)
  {
  index = left + (right - left)/2;
  //std::cout<<"\nIndex:" << index;
  if( a[index] == x)
    return index;
  if( a[index] > x)
    right = index-1;
  else
    left  = index+1;
  }
   
 return -1; 

}




int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
