#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_fast_with_mod(long long n,long long x) {
  if(n == 0){return 0;}
  if(n == 1){return 1;}
  long long a0 = 0;
  long long a1 = 1;
  long long sum = 0;
    // write your code here
    for(int i = 0; i < (n-2); i++){
      sum = (a0 + a1) % x;
      a0 = a1;
      a1 = sum;
    }
    return a0+a1;
}

long long fibonacci_fast(long long n) {
  if(n == 0){return 0;}
  if(n == 1){return 1;}
  long long a0 = 0;
  long long a1 = 1;
  long long sum = 0;
    // write your code here
    for(int i = 0; i < (n-2); i++){
      sum = (a0 + a1);
      a0 = a1;
      a1 = sum;
    }
    return a0+a1;
}

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

    return sum % 10;
}

int fibonacci_sum_last_digit(long long n) {
    if (n <= 1)
        return n;
    // we need mod 10 which has a pisano period of 60 so we mod our input by 60 and then we just compute the sum of those Fibonacci numbers
    int fibTotals[60] = {0,1,2,4,7,2,0,3,4,8,3,2,6,9,6,6,3,0,4,5,0,6,7,4,2,7,0,8,9,8,8,7,6,4,1,6,8,5,4,0,5,6,2,9,2,2,5,8,4,3,8,2,1,4,6,1,8,0,9,0};

    /**long long sum = 0;
    for(int i = 0; i < 60; i++){
      sum = (sum + fibonacci_fast(i));
      cout << sum % 10 << ",";
      
    }
    cout << endl;*/
    return fibTotals[n % 60];
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << endl;
    std::cout << fibonacci_sum_last_digit(n) << endl;
    
}
