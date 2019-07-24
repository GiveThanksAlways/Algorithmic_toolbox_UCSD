#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;

struct Pair
{
     long long min;
     long long max;
};

void vectorPrint(vector<vector<long long> > &A){
  cout << endl << endl;
  for(size_t row = 0; row < A.size(); row++){
    for(size_t col = 0; col < A.size(); col++){
      cout << A[row][col] << "     " ;
    }
    cout << endl;
  }
  cout << endl << endl;
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long minimum(long long a,long long b,long long c,long long d,long long e){
  return min(min(a,b),min(min(c,d),e));
}

long long maximum(long long a,long long b,long long c,long long d,long long e){
  return max(max(a,b),max(max(c,d),e));
}

Pair MinAndMax(int i, int j, vector<vector<long long> > &M, vector< vector<long long> > &m,const string &exp){
  long long min =  numeric_limits<long long>::max();
  long long max =  numeric_limits<long long>::min();
  long long a=0,b=0,c=0,d=0;
  for(size_t k = i; k <= j-1; k++){
    char opk = exp.at((k-1)*2+1);
    a = eval(M[i][k],M[k+1][j],opk);
    b = eval(M[i][k],m[k+1][j],opk);
    c = eval(m[i][k],M[k+1][j],opk);
    d = eval(m[i][k],m[k+1][j],opk);
    min = minimum(min,a,b,c,d);
    max = maximum(max,a,b,c,d);
  }
  Pair result = {min,max};
  return result;
}

long long Parentheses(vector<vector<long long> > &M, vector< vector<long long> > &m,const string &exp){
  int n = (exp.length())/2 +1;
  for(size_t i = 1; i <= n ; i++){
    char * character;
    char what = exp.at((i-1)*2);
    character = &what;
    m[i][i]=atoll(character);
    M[i][i]=atoll(character);
  }

  for(size_t s = 1; s <= n-1; s++){
    for(size_t i = 1; i <= n-s; i++){
      int j = i + s;
      Pair answer = MinAndMax(i,j,M,m,exp);
      m[i][j] = answer.min;
      M[i][j] = answer.max;
    }
  }
  /**
  cout<< "M" ;
  vectorPrint(M);
  cout<< "m" ;
  vectorPrint(m);

  //*/
  return M[1][n];
}

long long get_maximum_value(const string &exp) {
  int n = (exp.length())/2 +2;
  vector<vector<long long> > M(n, vector<long long>(n,0));
  vector<vector<long long> > m(n, vector<long long>(n,0));
  return Parentheses(M, m, exp);
}

int main() {
  string s;
  std::cin >> s;
  //s= "5-8+7*4-8+9";
  //s="5-8+7";
  //cout << s << endl;//delete
  std::cout << get_maximum_value(s) << '\n';
}
