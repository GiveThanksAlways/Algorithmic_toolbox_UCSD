#include <iostream>

using namespace std;

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

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
