#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


using std::vector;
using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> steps;
  vector<int> steptype;
  vector<int> sequence;
  steps.push_back(0);
  steps.push_back(0);
  sequence.push_back(n);
  int temp1 = 0;
  int temp2 = 0;
  int temp3 = 0;
  int addSteps = 0;
  int mult2Steps = 0;
  int mult3Steps = 0;

  for(int num =2; num <= n; num++){
    
    temp1 = num-1;
    addSteps = steps[temp1] + 1;
    if(num % 2 == 0){
      temp2 = num / 2;
      mult2Steps = steps[temp2] + 1;
    }else{mult2Steps = std::numeric_limits<int>::max();}

    if(num % 3 == 0 ){
      temp3 = num / 3;
      mult3Steps = steps[temp3] + 1;
    }else{mult3Steps = std::numeric_limits<int>::max();}

    /**cout << "num: " << num << endl;
    cout << "addSteps: " << addSteps << endl;
    cout << "mult2Steps: " << mult2Steps << endl;
    cout << "mult3Steps: " << mult3Steps << endl;
    cout << endl;*/

    if(addSteps <= mult2Steps && addSteps <= mult3Steps){
      // add step wins
      steps.push_back(addSteps);
      steptype.push_back(1);
    }else if(mult2Steps <= addSteps && mult2Steps <= mult3Steps){
      // mult2 wins
      steps.push_back(mult2Steps);
      steptype.push_back(2);
    }else{
      // mult3 wins
      steps.push_back(mult3Steps);
      steptype.push_back(3);
    }


  }
  
  
  /**for(size_t j = 0; j < steptype.size(); j++){
    cout << steptype[j] << "," ;
  }
  cout << endl << endl;
  cout << n << ",";*/
  while(n > 1 ){
    if(steptype[n-2] == 1){
      n = n -1;
    }else if(steptype[n-2] == 2){
      n = n/2;
    }else if(steptype[n-2] == 3){
      n = n/3;
    }
    //cout << n << ',';
    sequence.insert(sequence.begin(),n);
  }
  //cout << endl << endl << endl;
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
