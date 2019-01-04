#include <iostream>
#include <vector>
#include <math.h>
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here

  double x = (-1.0 + sqrt(n*4.0*2.0+1.0))/2.0;
  //std::cout<<"\nSolution:"<<x<<"\n";

  for(int i=1;i<=x ;i++)
  {
    summands.push_back(i);
    n-= i;

  }
  summands[summands.size()-1] += n;

   
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
