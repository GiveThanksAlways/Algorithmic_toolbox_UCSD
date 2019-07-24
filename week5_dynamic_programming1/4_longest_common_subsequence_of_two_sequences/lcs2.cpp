#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

using namespace std;

int maximum(int first, int second, int third){
  return max(first,max(second,third));
}

int lcs2(vector<int> &a, vector<int> &b) {
  int D[a.size()+1][b.size()+1];
  int insertion = 0, deletion = 0, match = 0,mismatch = 0;
  
  for(size_t i = 0; i< a.size()+1; i++){
      D[i][0] = 0;
  }
  for(size_t j = 0; j < b.size()+1; j++){
      D[0][j] = 0;
    }
      

  for(size_t j = 1; j < b.size()+1; j++){
    for(size_t i = 1; i < a.size()+1; i++){
      insertion = D[i][j-1]; // sigma = 0
      deletion = D[i-1][j]; // sigma = 0
      mismatch = D[i-1][j-1]; // mu = 0
      match = D[i-1][j-1]+1;
      if(a.at(i-1) == b.at(j-1)){
        //cout << "hit " << b.at(i) << " " << a.at(j) << endl;
        D[i][j] = maximum(insertion,deletion,match);
      }else{
        D[i][j] = maximum(insertion,deletion,mismatch);
      }

      
    }
    
  }

  /**for(size_t i = 0; i< a.size()+1; i++){
    for(size_t j = 0; j < b.size()+1; j++){
      cout << D[i][j] << " " ;
    }
      cout << endl; 
  }*/

  return D[a.size()][b.size()];
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
