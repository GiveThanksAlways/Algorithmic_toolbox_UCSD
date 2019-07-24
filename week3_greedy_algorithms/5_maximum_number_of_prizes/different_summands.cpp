#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int k = 1;
  int n_minus_k = n;
  while( k * 2 < n_minus_k){
    n_minus_k = n_minus_k - k;
    summands.push_back(k);
    k++;
  }
  summands.push_back(n_minus_k);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
