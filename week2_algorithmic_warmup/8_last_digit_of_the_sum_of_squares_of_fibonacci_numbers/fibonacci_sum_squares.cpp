#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fibonacci_sum_squares(long long n) {
  int pp10 = 60;
  int smalln = n%pp10;
  int nextn  = (n+1)%pp10;

  int psmall = get_pisano_number(smalln, 10);
  int plarge = get_pisano_number(nextn , 10);

  return (psmall*plarge)%10;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n)<<"\n";
}
