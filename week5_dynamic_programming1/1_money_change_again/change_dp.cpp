#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int get_changeRecursive(int n, vector<int> &coins)  {
  if(n == 0)
    return 0;
  int best = -1;
  int nextTry = std::numeric_limits<int>::max();
  for(int i = 0; i < coins.size(); i++){
    if(coins[i] <= n){
      nextTry = get_changeRecursive(n-coins[i], coins);
    }
    if(best < 0 || best > nextTry + 1){
      best = nextTry+1;
    }
  }
  
  return best;
}

int get_change(int money, vector<int> &coins, vector<int> &MinNumCoins){
  MinNumCoins.push_back(0);
  int NumCoins = 0;
  for(size_t m = 1; m <= money; m++){
    MinNumCoins.push_back(std::numeric_limits<int>::max()); // infinity
    for(size_t c = 0; c < coins.size(); c++){
      //cout << coins[c] << endl;
      if(m >= coins[c]){
        NumCoins = MinNumCoins[m-coins[c]] + 1;
        if(NumCoins < MinNumCoins[m]){
          MinNumCoins[m] = NumCoins;
        }
      }
    }
  }
  return MinNumCoins[money];
}

int main() {
  int m;
  //int coins[] = { 1, 3, 4 }; 
  vector<int> coins;
  vector<int> MinNumCoins;
  coins.push_back(1);
  coins.push_back(3);
  coins.push_back(4);

  std::cin >> m;
  std::cout << get_change(m, coins,MinNumCoins) << '\n';
}
