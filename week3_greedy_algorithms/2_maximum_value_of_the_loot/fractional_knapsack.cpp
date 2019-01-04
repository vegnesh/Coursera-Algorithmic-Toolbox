#include <iostream>
#include <vector>

using std::vector;


int get_max(vector<int>& weights, vector<int>& values)
{
  double max    = 0.0;
  int    index  = -1; 
  for(int i=0;i<weights.size();i++)
  {
    if(weights[i] > 0){
    if(max< (double)values[i]/weights[i])
    {
      max = (double)values[i]/weights[i];
      index = i;
    }
    }

  }


  return index;
}

double get_min(double a, double b)
{
  if(a<b)
    return a;
  return b;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double wval  = 0.0;
   // write your code here
  int index = -1;
  vector<double> TWgt(weights.size(),0.0);

  for(int i =0; i<weights.size(); i++)
  {
    if(capacity == 0)
    {
      return value;
    }
    index = get_max(weights,values);
    wval  = get_min(capacity, weights[index]);
    value += wval*((double)values[index]/weights[index]);
    weights[index] -=  wval;
    TWgt[index] += wval;
    capacity -=  wval;


  }


  return value;
}



int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
