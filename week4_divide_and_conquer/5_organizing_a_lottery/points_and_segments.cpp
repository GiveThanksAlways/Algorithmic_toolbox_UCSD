#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using namespace std;


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  
  vector< pair<int,string> > pairs;

  for (size_t i = 0; i < starts.size(); i++) {
    pairs.push_back(make_pair(starts[i], "l"));
    pairs.push_back(make_pair(ends[i],"r"));
  }
  for (size_t i = 0; i < points.size(); i++) {
    pairs.push_back(make_pair(points[i],"p"));
  }

  map<int,int> hashtable;
  sort(pairs.begin(),pairs.end());
  int totalSegments = 0;

  for (size_t i = 0; i < pairs.size(); i++) {
    //cout << pairs[i].first << pairs[i].second << endl;
    if(pairs[i].second == "l") totalSegments++; 
    else if(pairs[i].second == "r") totalSegments--;
    else{
       hashtable[pairs[i].first] = totalSegments;
    }

  }
  
  for (size_t i = 0; i < points.size(); i++){
      cnt[i] = hashtable[points[i]];
  }

  //cout << endl;

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
