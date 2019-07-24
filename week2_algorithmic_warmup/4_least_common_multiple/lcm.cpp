#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(int a, int b) {
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

long long lcm(int a, int b){
  return (a / gcd(a,b))*b;

}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;

  return 0;
}
