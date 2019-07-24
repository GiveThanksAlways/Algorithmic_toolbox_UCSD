#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long int max_product = 0;
    int n = numbers.size();
    vector<long long int> temp;

    // make a copy to sort 
    for(int i=0; i < n; i++){
      temp.push_back(numbers[i]);
    }
    sort(temp.begin(),temp.end());

   /**for(std::vector<int>::iterator it=temp.begin(); it!=temp.end(); it++){
      cout << ' ' << *it;
   }*/
    //cout << '\n';
    max_product = temp[n-1] * temp[n-2]; // iterator starts at 0 so n-1 is last guy, n-2 is second last 
    //max_product = 100000 * 90000;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long int result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
