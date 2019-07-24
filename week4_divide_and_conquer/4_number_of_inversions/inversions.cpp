#include <iostream>
#include <vector>

using std::vector;
using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions; // when we reach one unit 
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  int i = left; // b index for temp array 
  int j = left; // j keeps track of left
  int k = ave; // k keeps track of right
  //int subarrsize = right-left;
  
  while(j < ave && k < right){
    if(a[j] <= a[k]){
      b[i] = a[j]; 
      j++;
    }else{
      b[i] = a[k];
      k++;
      number_of_inversions += (ave-j);
    }
    i++;
  }

  // finish filling in the temp array b with what is left from left and right sub arrays
  while(j < ave){
    b[i] = a[j]; 
    j++;
    i++;
  }
  while(k < right){
    b[i] = a[k];
    k++;
    i++;
  }

  for(int index = left; index < i; index++){
    a[index] = b[index]; // copy temp array b back into a with the merge sorted part 
  }

  /*
  cout << "          left: " << left << " right: " << right;
  cout << endl << "B array: ";
  for (int i = 0; i < b.size(); i++) {
    cout  << b[i];
  }
  cout << endl << "A array: ";
  for (int i = 0; i < b.size(); i++) {
    cout  << a[i];
  }
  cout << endl;
  */

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

  /* erase later
  for (size_t i = 0; i < a.size(); i++) {
    cout << a[i] << ",";
  }
  */ // erase later
  
}
