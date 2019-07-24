#include <iostream>
using namespace std;

// we want to output F_n mod m

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

int gcd(int a, int b) {
  // we do GCD with a > b
  int answer = 0;
  if(b>a){
    int temp = a;
    a = b;
    b = temp;
  }

  if(a != 0 & b !=0){
    int tempReturn = 0;
    int q = 0;
    q = a % b;
    //cout << "a: " << a << " b: " << b << "\n";
    //cout << (a % b) << "\n";
    //cout << "q: " << q << " b: " << b << "\n";
    return gcd(b,q);
    // 200 192
    //return a;
  }else{
    return a; // when b=0 we return a all the way back up through all of recusion calls 
  }

}

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1){return n;}

    int a0 = 0;
    int a1 = 1;
    int sum = 0;
    int pisanoPeriod = 1;
    int pisanoa0 = 0;
    int pisanoa1 = 0;
    int temp = 0;

    // first time to get started
    sum = a0 + a1;// 0 + 1
    a0=a1; // 1
    a1=sum; // 1
    pisanoa0 = a0 % m; // 4
    pisanoa1 = a1 % m; // 2
    
    //long long FN = fibonacci_fast(n); // get F_n or the nth fibonacci number 
    bool PisanoPeriodBegin = false;
    while(!PisanoPeriodBegin){
      // keep adding the mod m until we see the beginning of the period 01
      temp = (pisanoa0 + pisanoa1) % m; // 6
      pisanoa0 = pisanoa1;
      pisanoa1 = temp;
      if(pisanoa0 == 0 && pisanoa1 == 1){PisanoPeriodBegin = true;}
      
      pisanoPeriod++;
      if(pisanoPeriod> 10000){PisanoPeriodBegin = true;} // Error fail safe 
    }
    //cout << "pisanoPeriod: " <<  pisanoPeriod << endl;
    return fibonacci_fast_with_mod( n % pisanoPeriod , m) % m;
    

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n'; //239 1000

    // my code below 
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
