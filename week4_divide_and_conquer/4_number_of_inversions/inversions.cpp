#include <iostream>
#include <vector>

using std::vector;

void print(const vector<int>& a, int l, int r)
{
  for(int i = l;i<r;i++)
    std::cout<<a[i]<<" ";
  std::cout<<"\n";
}

int merge(vector<int> &a, int l,int m, int r)
{
  int i,j,k;
  int n1 = m - l + 1;
  int n2 = r-m;
  vector<int> L(n1);
  vector<int> R(n2);

  for(i=0;i<n1;i++)
    L[i] = a[l+i];
  for(j=0;j<n2;j++)
    R[j] = a[m+1+j];

  i=0;j=0;k=l;

  int count = 0;

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
      count+= (n1 - i);
         
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

  return count;
  
}



int mergesort(vector<int> &a, int l, int r)
{
  long pa = 0, pb = 0, pt = 0;  
  if(r>l)
  {
    int m = l + (r-l)/2;
    pa = mergesort(a,l,m);
    pb = mergesort(a,m+1,r);
//    std::cout<<"Prior    :";
//    print(a,l,r);
    pt = merge(a,l,m,r);
//    std::cout<<"Posterior:";
//    print(a,l,r);
    
  }
   
  return pa+pb+pt;

}
















long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
//  mergesort(a,0,a.size()-1);
//  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  std::cout<<mergesort(a,0,a.size()-1)<<"\n";

}
