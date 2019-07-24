#include <iostream>

int get_change(int m) {

  int dimes    = 0;
  int nickels  = 0;
  int pennies  = 0;

  dimes = m / 10;
  nickels = (m % 10) / 5;
  pennies = ((m % 10) % 5);

  return dimes + nickels + pennies;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
