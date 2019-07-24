#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

bool compareFunction (int a, int b){
  return b < a;
}

void changeA(vector<int> &A,int index){
  A[index] = 0;
}

int partition3(const vector<int> &A) {
  int sum = 0;
  for(size_t i = 0; i < A.size(); i++){
    sum += A[i];
  }
  if(A.size()< 3) // if there are not 3 elements then it won't even work
    return 0;
  
  if(sum % 3 != 0) // if sum is not divisble by 3, then you can't get 3 equal partitions
    return 0;

  vector<vector<int> > value(A.size()+1, vector<int>(sum/3+1,0));
  
  for(size_t i = 0; i< A.size()+1; i++){
      value[i][0] = 0;
  }
  for(size_t j = 0; j < sum/3 + 1; j++){
      value[0][j] = 0;
    }
      
  int val = 0;
  for(size_t i = 1; i < A.size()+1; i++){
    for(size_t j = 1; j < sum/3+1; j++){
      value[i][j] = value[i-1][j];
      if(A[i-1] <= j){
        val = value[i-1][j-A[i-1]] + A[i-1];
        if(value[i][j] < val){
          value[i][j] = val;
        }
      }
    }
  }
  /**for(size_t i = 0; i < A.size()+1; i++){
    for(size_t j = 0; j < sum/3+1; j++){
      cout << value[i][j] << " ";
    }
    cout << endl << endl;
  }*/
  vector<int> boolvec(A.size()+1,0);

  int right = sum/3;
  int hit = 0;
  for(int k = A.size(); k > 0; k--){
    //cout << value[k][right] << endl;
    if(value[k][right] != value[k-1][right]){
      //cout << "hit " << A[k-1] << endl;
      boolvec[k-1] = 1;
      // make A[k-1] =0

      hit++;
      right = right - A[k-1];
    }

  }
  /**for(size_t i = 0; i < A.size(); i++){
    cout << boolvec[i] << "--" << A[i] << "," ;
  }
  cout <<endl;*/
  if(value[A.size()][sum/3] != sum/3)
    return 0;
// second pass
//
//
//
//
//
vector<vector<int> > value2(A.size()+1-hit, vector<int>(sum/3+1,0));
  
  for(size_t i = 0; i< A.size()+1-hit; i++){
      value2[i][0] = 0;
  }
  for(size_t j = 0; j < sum/3 + 1; j++){
      value2[0][j] = 0;
    }
      
  int val2 = 0;
  
  for(size_t i = 1; i < A.size()+1-hit; i++){
    int skip = 0;
    while(boolvec[i-1] == 1){i++; skip++;}
    i = i - skip;
    for(size_t j = 1; j < sum/3+1; j++){
      value2[i][j] = value2[i-1][j];
      if(A[i-1+skip] <= j){
        val2 = value2[i-1][j-A[i-1+skip]] + A[i-1+skip];
        if(value2[i][j] < val2){
          value2[i][j] = val2;
        }
      }
    }
  }
  
/**
I need to skip the rows on the second pass
the second time should work
or just change the A vector to make values zero
*/
  /**cout << endl << " new value vec " << endl << endl;
  for(size_t i = 0; i < A.size()+1-hit; i++){
    for(size_t j = 0; j < sum/3+1; j++){
      cout << value2[i][j] << " ";
    }
    cout << endl << endl;
  }*/
  //cout << value2[A.size()-hit-1][sum/3] << endl;
  if(value2[A.size()-hit][sum/3] != sum/3)
    return 0;

  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  //sort(A.begin(),A.end(),compareFunction);
  //random_shuffle(A.begin(),A.end());
  if(!partition3(A)){
    sort(A.begin(),A.end(),compareFunction);
  }
  if(!partition3(A)){
    random_shuffle(A.begin(),A.end());
    std::cout << partition3(A) << '\n';
  }else{
    std::cout << 1 << '\n';
  }
    
  
}
