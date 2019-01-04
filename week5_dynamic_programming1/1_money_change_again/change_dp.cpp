#include <iostream>
#include <vector>
int min(int a, int b, int c)
{
  int min = a*(a<=b) + b*(b<a);
  return (min*(min<=c) + c*(c<min));
}

int get_change(int m) {
  //write your code here
  //
  //
  int x = m;

  if(m<4)
    x=4;


  std::vector<int> nc(x+1);

  nc[0] = 0;
  nc[1] = 1;
  nc[2] = 2;
  nc[3] = 1;
  nc[4] = 1;

  for(int i=5;i<=x;i++)
  {
    nc[i] = min(nc[i-1]+1,nc[i-3]+1,nc[i-4]+1);

  }

  
  return nc[m] ;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
