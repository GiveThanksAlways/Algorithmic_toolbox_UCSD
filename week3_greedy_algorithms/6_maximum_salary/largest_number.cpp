
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using namespace std;

// compare strings converted to integers 
bool compareFunction (string a, string b){
  return stoi(a+b) > stoi(b+a);
}

string largest_number(vector<string> a) {
  string a1,a2;
  bool compare;

  /**for(int i=0; i < a.size() -1; i++){
    a1 = a[i]+a[i+1];
    a2 = a[i+1]+a[i];
    compare = stoi(a1) > stoi(a2);
    cout << stoi(a2)<< compare << endl;
    //cout << a1 << " > " << a2 << compare << endl;
  }*/

  // sort by where ab > ba when strings are turned into integers 
  sort(a.begin(),a.end(),compareFunction);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
