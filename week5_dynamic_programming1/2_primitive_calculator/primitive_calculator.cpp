#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int min(int a, int b, int c)
{
  int min = a*(a<=b) + b*(b<a);
  return (min*(min<=c) + c*(c<min));
}

vector<int> optimal_sequence_2(int n)
{
  int x = n;
  if(n<3)
    x = 3;
  std::vector<int> seq(x+1);
  std::vector<int> list;

  seq[0] = 0;
  seq[1] = 0;
  seq[2] = 1;
  seq[3] = 1;

  list.push_back(0);
  list.push_back(1);
  list.push_back(1);
  list.push_back(1);

  int min1, min2, min3;
  for(int i=4;i<=n;i++)
  {
    min1 = seq[i-1] + 1;
    min2 = 1000000;
    min3 = 1000000;
    if(i%2 == 0)
      min2 = seq[i/2] + 1;
    if(i%3 == 0)
      min3 = seq[i/3] + 1;
    seq[i] = min(min1,min2,min3);
    if(seq[i] == min3)
      list.push_back(i/3);
    else if(seq[i]==min2)
      list.push_back(i/2);
    else
      list.push_back(i-1);


  }

 // std::cout<< seq[n]<<"\n";
 
  vector<int> retlist;
  
  retlist.push_back(n);
  while(n>1)
  {
    retlist.push_back(list[n]);
    n = list[n];
  }

  reverse(retlist.begin(), retlist.end());
  return retlist;



}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_2(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
