#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

struct Pivot{
  int m1;
  int m2;
};

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

Pivot partition3(vector<int> &a, int l, int r) {
  int i = l; int gt = r; int lt = l;
  int v = a[l];
  int temp = 0;

  while(i <= gt){
    if(a[i] == v){i++;}
    else if(a[i] > v){
      temp = a[gt];
      a[gt] = a[i];
      a[i] = temp;
      gt--;
    } 
    else{
      temp = a[lt];
      a[lt] = a[i];
      a[i] = temp;
      lt++;
      i++;
    }
    
  }

  return {lt,gt};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m = partition2(a, l, r);
  Pivot pivot = partition3(a, l, r);
  //cout << daPivot.m1 << " " << daPivot.m2 << endl;
  
  randomized_quick_sort(a, l, pivot.m1 - 1);
  randomized_quick_sort(a, pivot.m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
