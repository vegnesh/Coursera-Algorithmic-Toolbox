#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

int fibonacci_sum(long long n)
{
  int pp10 = 60;
  int smalln = (n+2)%pp10;
  int last = get_pisano_number(smalln,10);
  if(last == 0)
    return 9;
  else
    return last - 1;

  

}


int get_fibonacci_partial_sum(long long from, long long to) {
  int less = 0;
  int great= 0;
  if(from<to)
  {
    less = fibonacci_sum(from-1);
    great= fibonacci_sum(to);
  }
  else
  {
    less = fibonacci_sum(to-1);
    great= fibonacci_sum(from);
  }

//  std::cout<<great<<" "<<less<<std::endl;
  if(great<less)
    return 10 + great - less;
  else
    return great - less;

}



int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
