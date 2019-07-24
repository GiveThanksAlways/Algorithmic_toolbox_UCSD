#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

bool compareFunction (Segment segment1, Segment segment2){
  return (segment1.end < segment2.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(),segments.end(),compareFunction);
  /**for (size_t i = 0; i < segments.size(); i++){
    cout << segments[i].start << ',' << segments[i].end << ',';
  }*/
  
  int counter = 0;
  int point = segments[0].end;
  int position  = point;
  int ii = 0;
  int n = segments.size();
  //points.push_back(point);

  while( ii < n){
    point = segments[ii].end;
    counter++; 
    ii++;
    //cout << "start: " << ii << endl;
    //points.push_back(segments[ii].start);
    
    //cout << position << endl;
    points.push_back(point);
    while(position >= segments[ii].start && position <= segments[ii].end){
      //cout << "hit " << segments[ii].start << ',' << segments[ii].end << endl;
      //points.pop_back();
      ii++;
    }
    position = segments[ii].end;
  }
  //points.push_back(point);
  /**for (size_t i = 0; i < segments.size(); i++){
    cout << segments[i].start << ',' << segments[i].end << ',';
  }
  cout << endl << endl;

  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
