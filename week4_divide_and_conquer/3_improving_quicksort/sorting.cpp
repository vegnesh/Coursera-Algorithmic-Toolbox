#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<long> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void print(vector<long> a)
{
  std::cout<<"\n";
  for(int i=0;i<a.size();i++)
    std::cout<<a[i]<<" ";
  std::cout<<"\n";
}

void partition3(vector<long> &a, int l, int r, vector<int> &index) {
  int x = a[l];
  int j = l;
  int j1 = l;
  for (int i = l + 1; i <= r; i++) {
//    std::cout<<a[i]<<" "<<j1<<" "<<j<<" ";
    if (a[i] < x)  {
      swap(a[j1],a[i]);
      j++;
      j1++;
      swap(a[i], a[j]);
    
    }
    else if(a[i]==x)
    {
      swap(a[j1],a[i]);
      j++;
      swap(a[j],a[i]);
    }
//  print(a);
//  std::cout<<j1<<" "<<j;
  }
  //swap(a[l], a[j]);
//  print(a);
  index[0] = j1;
  index[1] = j;

}



void randomized_quick_sort(vector<long> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
//  int m = partition2(a, l, r);
  vector<int> index(2);
  partition3(a,l,r,index);

//  randomized_quick_sort(a, l,m-1);// index[0] - 1);
//  randomized_quick_sort(a, m+1,r);//index[1] + 1, r);
  randomized_quick_sort(a, l, index[0] - 1);
  randomized_quick_sort(a, index[1] + 1, r);

}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);


//  vector<int> index(2);
//  partition3(a,0,a.size()-1,index);  
//  std::cout<<a[0]<<index[0]<<" "<<index[1]<<"\n"; 
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
