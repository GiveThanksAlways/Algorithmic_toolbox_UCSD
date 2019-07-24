#include <iostream>
#include <string>
#include <algorithm>

using std::string;

using namespace std;

int minimum(int first, int second, int third){
  return min(first,min(second,third));
}

int edit_distance(const string &str1, const string &str2) {
  int D[str1.length()+1][str2.length()+1];
  int insertion = 0, deletion = 0, match = 0,mismatch = 0;
  
  for(size_t i = 0; i< str1.length()+1; i++){
      D[i][0] = i;
  }
  for(size_t j = 0; j < str2.length()+1; j++){
      D[0][j] = j;
    }
      

  for(size_t j = 1; j < str2.length()+1; j++){
    for(size_t i = 1; i < str1.length()+1; i++){
      insertion = D[i][j-1] + 1;
      deletion = D[i-1][j] + 1;
      mismatch = D[i-1][j-1] + 1;
      match = D[i-1][j-1];
      if(str1.at(i-1) == str2.at(j-1)){
        //cout << "hit " << str2.at(i) << " " << str1.at(j) << endl;
        D[i][j] = minimum(insertion,deletion,match);
      }else{
        D[i][j] = minimum(insertion,deletion,mismatch);
      }

      
    }
    
  }

  /**for(size_t i = 0; i< str1.length()+1; i++){
    for(size_t j = 0; j < str2.length()+1; j++){
      cout << D[i][j] << " " ;
    }
      cout << endl; 
  }*/

  return D[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
