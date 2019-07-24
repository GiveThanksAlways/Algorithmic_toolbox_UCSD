#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

using std::vector;

double get_optimal_value(int items, int capacity, vector<int>& weights, vector<int>& values) {
  double value = 0.0;
  double lootWeight = 0.0;
  int safestValue = 0;
  double safestFractionalAmount = 0;
  double fractionalamount = 0;
  vector<double> lootBag;

  safestFractionalAmount = values[0] / weights[0];
  //cout << .11111 << endl;
  while(lootWeight < capacity){
    // find the item with the greatest value per weight 
    
    
    // find the best ratio of weight to value and add it 
    for(int i =0; i < items; i++ ){
      fractionalamount = (double)values[i] / (double)weights[i];
      //cout << fractionalamount << endl;
      if(fractionalamount > safestFractionalAmount){
        safestValue = i;
        safestFractionalAmount = fractionalamount;
      }else if(fractionalamount == safestFractionalAmount){
        if(weights[i] < weights[safestValue]){
          safestValue = i;
          safestFractionalAmount = fractionalamount;
        }
      }
    }
    //cout << "safestValue: " << safestValue << endl;
  
    // add loot to bag 
    if((lootWeight + weights[safestValue]) <= capacity){
      value += values[safestValue];
      lootWeight += weights[safestValue];
      //cout << value << " " << lootWeight << " " << endl;
      values[safestValue] = 0;
      weights[safestValue] = 1;
    }else{
      // only add the fractionalamount left
      value += (values[safestValue] * (capacity - lootWeight)) / weights[safestValue];
      lootWeight +=  (capacity - lootWeight);
      values[safestValue] = 0;
      weights[safestValue] = 1;
      //return value; 
    }
    safestFractionalAmount = 0;
    safestValue = 0;
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n,capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
