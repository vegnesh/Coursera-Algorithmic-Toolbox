#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_pisano_period(long long m)
{
  if(m==1)
    return 1;
  int previous = 0;
  int current  = 1;
  int next     = 0;
  int period   = 0;
  do{
    next = (previous + current)%m;
    previous = current; 
    current  = next;
    ++period;   
 
  }while( !(previous == 0 && current ==1));
  return period;
}

int get_pisano_number(int n, int m)
{

  if(n == 0 || n == 1)
    return n;
  else
  {
    int previous = 0;
    int current  = 1;
    int next;
    for(int i=2;i<=n;i++)
    {

      next = (current + previous)%m;
      previous = current;
      current = next;
    }
    return current;

  }

}

int get_fibonacci_huge_actual(long long n, long long m)
{
  int period = get_pisano_period(m);
  int smalln = n%period;
//  std::cout<<smalln<< std::endl;
  int number = get_pisano_number(smalln, m);
  return number;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_actual(n, m) << '\n';
  //  std::cout << get_pisano_period(m) << '\n';

}
