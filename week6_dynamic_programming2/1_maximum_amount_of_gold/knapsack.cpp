#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int nw = w.size();
  int T[W+1][nw+1];
  
  for(int i = 0;i<=W;i++)
  T[i][0] = 0;
  
  for(int i = 1;i<=nw;i++)
  {
      for(int j=0;j<=W;j++)
      {
          T[j][i] = T[j][i-1];
          if(j>=w[i-1])
          {
              if((T[j-w[i-1]][i-1] + w[i-1]) > T[j][i])
                T[j][i] =  T[j-w[i-1]][i-1] + w[i-1];
          }
          
          
      }
      
  }
  
  return T[W][nw];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
