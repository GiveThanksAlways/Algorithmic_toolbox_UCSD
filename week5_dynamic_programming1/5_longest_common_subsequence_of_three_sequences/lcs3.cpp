#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

using namespace std;

int maximum(int first, int second, int third,int fourth){
  return max(max(first,fourth),max(second,third));
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int D[a.size()+1][b.size()+1][c.size()+1];
  int insertion = 0, deletion = 0, match = 0,mismatch = 0,indelk = 0;
  
  for(size_t i = 0; i< a.size()+1; i++){
    for(size_t j = 0; j < b.size()+1; j++){
      for(size_t k = 0; k < c.size()+1; k++){
          D[i][j][k] = 0;
        }
    }
  }
      

  for(size_t j = 1; j < b.size()+1; j++){
    for(size_t i = 1; i < a.size()+1; i++){
      for(size_t k = 1; k < c.size()+1; k++){
        insertion = D[i][j-1][k]; // sigma = 0
        deletion = D[i-1][j][k]; // sigma = 0
        indelk = D[i][j][k-1];
        mismatch = D[i-1][j-1][k-1]; // mu = 0
        match = D[i-1][j-1][k-1] + 1;
        if(a.at(i-1) == b.at(j-1) && b.at(j-1) == c.at(k-1)){
          //cout << "HIT " << a.at(i-1) << endl;
          D[i][j][k] = maximum(insertion,deletion,indelk,match);
          //cout << " " << D[i][j][k] << endl;
        }else{
          D[i][j][k] = maximum(insertion,deletion,indelk,mismatch);
        }
      }
      
    }
    
  }

  /**for(size_t i = 0; i< a.size()+1; i++){
    for(size_t j = 0; j < b.size()+1; j++){
      cout << D[i][j][1] << " " ;
    }
      cout << endl; 
  }*/

  return D[a.size()][b.size()][c.size()];
  //return std::min(std::min(a.size(), b.size()), c.size());
}


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
