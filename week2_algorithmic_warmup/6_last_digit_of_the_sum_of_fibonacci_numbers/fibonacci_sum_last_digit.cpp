#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum ;
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

int main() {
    long long n = 0;
    std::cin >> n;
//    for(int i = 0; i<n; i++){
    std::cout << fibonacci_sum(n)<<"\n";
//    std::cout<< "n:"<<i<<" Last Digit:"<< fibonacci_sum(i) << "\n";
//    }
}
