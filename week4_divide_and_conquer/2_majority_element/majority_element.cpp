#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  int half = right/2; // n/2
  //cout << "half: " << half << endl;
  if (left == right) return -1;
  if (left + 1 == right) return a[left]; // only one element
  
  sort(a.begin(),a.end());
  /*for(int i=0; i< right; i++){
    cout << a[i] << ',';
  }
  cout << endl;
  */
  for(int j=0; j< half+1; j++){
    if(a[j] == a[j+half]){
      //cout << endl << "hit" << endl;
      return 1;
    }
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
