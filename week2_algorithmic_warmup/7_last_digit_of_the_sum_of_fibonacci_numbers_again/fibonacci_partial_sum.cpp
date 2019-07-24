#include <iostream>
#include <vector>
using namespace std;

long long fibonacci_fast(long long n) {
  if(n == 0){return 0;}
  if(n == 1){return 1;}
  long long a0 = 0;
  long long a1 = 1;
  long long sum = 0;
    // write your code here
    for(int i = 0; i < (n-2); i++){
      sum = (a0 + a1) % 10;
      a0 = a1;
      a1 = sum;
    }
    return a0+a1;
}

int fibonacci_sum_last_digit(long long to, long long from) {
    if (to <= 1)
        return to;
    // we need mod 10 which has a pisano period of 60 so we mod our input by 60 and then we just compute the sum of those Fibonacci numbers
    int fibTotals[60] = {0,1,2,4,7,2,0,3,4,8,3,2,6,9,6,6,3,0,4,5,0,6,7,4,2,7,0,8,9,8,8,7,6,4,1,6,8,5,4,0,5,6,2,9,2,2,5,8,4,3,8,2,1,4,6,1,8,0,9,0};

    /**long long fibTotals[60] = {0,1,2,4,7,12,20,33,54,88,143,232,376,609,986,1596,2583,4180,6764,10945,17710,28656,46367,75024,121392,196417,317810,514228,832039,1346268,2178308,3524577,5702886,9227464,14930351,24157816,39088168,63245985,102334154,165580140,267914295,433494436,701408732,1134903169,1836311902,2971215072,4807526975,7778742048,12586269024,20365011073,32951280098,53316291172,86267571271,139583862444,225851433716,365435296161,591286729878,956722026040,1548008755919,2504730781960};*/
    long long diff = (to - from) % 60;
    long long leftover = to % 60;
    long long sum = fibTotals[leftover];
    for(int i = 1; i < diff ; i++){
      //sum = (sum + fibonacci_fast(i));
      sum = (sum - fibTotals[i]);
      //cout << fibTotals[i]<< ",";
      //cout << fibonacci_fast(i)<<"," << endl;
    }
    //cout << endl;
    //cout << "fibTotals: " <<  fibTotals[finish] << endl;
    long long toReturn = fibTotals[to % 60] - fibTotals[from % 60];
    if(toReturn < 0 ){ return 10 + toReturn;}
    else{ return toReturn;}
    //return sum;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum(long long from, long long to){
  // what 
  if(from == to){return fibonacci_fast(from % 60);}
  if(from != 0){from = from - 1;}
  //long long diff = (to % 60) - (from % 60) + 1;
  //long long total = 0;
  //cout << diff << endl;
  /**for( int j = (from % 60); j < diff; j++){
    total = fibonacci_fast(j);
  }*/
  //return fibonacci_sum_last_digit(diff);
  
  return fibonacci_sum_last_digit(to,from) % 10;

}
int main() {
    long long from, to;
    std::cin >> from >> to;
    //cout << get_fibonacci_partial_sum_naive(from, to) << '\n';

    cout << get_fibonacci_partial_sum(from, to) << '\n';
}
