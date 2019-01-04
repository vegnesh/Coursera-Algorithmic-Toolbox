#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using std::vector;
using std::string;

bool isgreater(string a, string b)
{
  string x,y;
  x = a;
  x.append(b);
  y = b;
  y.append(a);

  return (x>=y);
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;

  string temp;
  int index;
  string maxd = a[0];

  while(a.size()>0)
  {
    maxd = a[0];
    index = 0;
  for (size_t i = 1; i < a.size(); i++) {
    if(isgreater(a[i],maxd))//    a[i] >= maxd)
    {
      maxd = a[i];
      index = i;
    }
    
  }
  ret << maxd;
  temp = a[index];
  a[index] = a[a.size()-1];
  a[a.size()-1] = temp;
  a.pop_back();
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}




/*
string largest_number(vector<int> a) {
  //write your code here
  std::stringstream ret;
  int maxd = -100;
  int index = -1;
  int temp;
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
*/
