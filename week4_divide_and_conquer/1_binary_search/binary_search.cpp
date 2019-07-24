#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

using namespace std;

int binary_search_recursive(const vector<int> &a,int low, int high, int key) {
  if(high < low)
  {
    //if(a[low-1] == key){return low-1;}
    //else{return -1;}
    return -1;
  }
  int mid = low + (high - low)/2;
  //cout << "mid: " << mid << " high:" << high << " low: " << low << endl;
  if(key == a[mid]){
    return mid;
  }
  else if( key < a[mid]){ return binary_search_recursive(a, low, mid-1, key); }
  else{ return binary_search_recursive(a, mid+1, high, key); }
  
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  return binary_search_recursive(a,left,right-1,x);
  
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    
    //std::cout << linear_search(a, b[i]) << ' ';
    //cout << "        start  " << endl;
    cout << binary_search(a,b[i]) << ' ';
    //cout << endl << "      end" << endl;

  }
}
