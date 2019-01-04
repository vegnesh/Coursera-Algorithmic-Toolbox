#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int bn = exp.size();
  int n  = (bn+1)/2;
  vector<int> d(n);

   
  for(int i=0;i<n;i++)
  {
 	d[i] = exp[2*i] - '0';
  } 
  int M[n][n], m[n][n];
  for(int i=0;i<n;i++)
{
	m[i][i] = d[i];
	M[i][i] = d[i];
}
int j;
int minv, maxv;
  for(int x=1;x<n;x++)
  for(int i=0;i<n-x;i++)
  {
	j = i+s;
      min_max(m,M,ops,i,j)

  }
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
