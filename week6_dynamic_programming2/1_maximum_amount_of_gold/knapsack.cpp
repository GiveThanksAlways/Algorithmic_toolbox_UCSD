#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  vector<vector<int> > value(w.size()+1, vector<int>(W+1,0));//W+1);
  
  for(size_t i = 0; i< w.size()+1; i++){
      value[i][0] = 0;
  }
  for(size_t j = 0; j < W+1; j++){
      value[0][j] = 0;
    }
      
  int val = 0;
  for(size_t i = 1; i < w.size()+1; i++){
    for(size_t j = 1; j < W+1; j++){
      value[i][j] = value[i-1][j];
      if(w[i-1] <= j){
        val = value[i-1][j-w[i-1]] + w[i-1];
        if(value[i][j] < val){
          value[i][j] = val;
        }
      }
    }
  }
  /**for(size_t i = 0; i < w.size()+1; i++){
    for(size_t j = 0; j < W+1; j++){
      cout << value[i][j];
    }
    cout << endl;
  }*/
  return value[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
