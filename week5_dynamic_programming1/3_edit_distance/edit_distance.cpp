#include <iostream>
#include <string>

using std::string;

int minv(int a, int b, int c)
{
 int rv = a;
 if(b<a)
   rv = b;
 if(c<rv)
   rv = c;
 return rv;
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.size();
  int n = str2.size();
  int ED[m+1][n+1];
  for(int i=0;i<m+1;i++)
    ED[i][0] = i;
  for(int j=0;j<n+1;j++)
    ED[0][j] = j;
  int diff = 1;
  for(int i=1;i<m+1;i++)
  for(int j=1;j<n+1;j++)
  {
      diff = 1;
      if(str1[i-1] == str2[j-1])
        diff = 0;
      ED[i][j] = minv(ED[i-1][j] +1 , ED[i][j-1]+1, ED[i-1][j-1] + diff);
   
  }
  return ED[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}