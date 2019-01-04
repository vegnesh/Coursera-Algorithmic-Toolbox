#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


void merge(vector<long> &a, int l,int m, int r)
{
  int i,j,k;
  int n1 = m - l + 1;
  int n2 = r-m;
  vector<long> L(n1);
  vector<long> R(n2);

  for(i=0;i<n1;i++)
    L[i] = a[l+i];
  for(j=0;j<n2;j++)
    R[j] = a[m+1+j];

  i=0;j=0;k=l;

  while(i<n1 && j< n2)
  {
    if(L[i]<=R[j])
    {
      a[k] = L[i];
      i++;
    }
    else
    {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  
  while(i<n1)
  {
    a[k] = L[i];
    i++;
    k++;
  }

  while(j<n2)
  {
    a[k] = R[j];
    j++;
    k++;
  }
  
}



void mergesort(vector<long> &a, int l, int r)
{
  if(r>l)
  {
    int m = l + (r-l)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
//    std::cout<<"Prior    :";
//    print(a,l,r);
    merge(a,l,m,r);
//    std::cout<<"Posterior:";
//    print(a,l,r);
  }
}



int get_majority_element(vector<long> &a, int left, int right) {
  if (left == right) return -1;
  if(a.size() == 1) return 1;
//  sort(a.begin(),a.end());
  mergesort(a,0, a.size()-1);
  long max = a[0];
  int count = 1, maxcount = -1;

  for(int i = 1; i < a.size();i++)
  {
    if(a[i] == max)
    {
      count++;

    }
    else
    {
      max = a[i];
      if(count > maxcount)
	maxcount = count;
      
      count = 1;
    
    }
  }
  if (maxcount > (double)a.size()/2.0 || count > (double)a.size()/2.0)
    return 1;

  //std::cout<<maxcount;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
