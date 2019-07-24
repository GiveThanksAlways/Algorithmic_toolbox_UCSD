#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
using namespace std;

struct Point {
  int x;
  int y;
};

bool compareX(Point p1, Point p2){
  return p1.x < p2.x;
}

bool compareY(Point p1, Point p2){
  return p1.y < p2.y;
}

float distance(Point p1, Point p2){
  return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

float minimum(float d1, float d2){
  return ( d1 < d2 )? d1 : d2;
}

double minimal_distance(vector<Point> points,int left, int right) {
  if(right <= left+3){
    //cout << "left: " << left << endl;
    //cout << "right: " << right << endl;
    //cout << "distance: " << distance(points[left],points[left+1]) << endl;
    float minOflastfew = distance(points[left],points[left+1]);
    for(size_t i=left; i < right-1; i++){
      //cout << "i:" << i << endl;
      for(size_t j=i+1; j < right; j++){
        //cout << "j: " << j << endl;
        if(distance(points[i],points[j]) < minOflastfew)
          minOflastfew = distance(points[i],points[j]);
      }
    }
    //cout << "minoflastfew " << minOflastfew << endl;
    return minOflastfew;
    }

  int mid = left + (right-left)/2;
  //cout << left << "," << mid << "," << right << endl;
  
  /**for(size_t i=0; i < points.size(); i++){
    cout << points[i].x << "," << points[i].y << endl;
  }*/
  //cout << "hello" << endl;
  float d1 = minimal_distance(points,left,mid);
  float d2 = minimal_distance(points,mid,right);
  //cout << "d1: " << d1 << endl;
  //cout << "d2: " << d2 << endl;
  //cout << points[mid].x <<endl;
  float d = minimum(d1,d2);

  vector<Point> blueZone(right-left);
  int j = 0;
  for(size_t i = left; i < (right-left); i++){
    if(abs(points[i].x - points[mid].x) < d){
      blueZone[j] = points[i]; 
      //cout << "points[i] " << points[i].x << "," << points[i].y << endl;
      j++;
    }
  }
  
  float min = d;

  sort(blueZone.begin(),blueZone.begin()+j, compareY);
  /**for(size_t i = 0; i < j; i++){
    cout << blueZone[i].x << "," << blueZone[i].y << endl;
  }*/
  for(size_t i = 0; i < j; i++){
    for(size_t k = i+1; k < j && abs(blueZone[k].y - blueZone[i].y) < min; k++){
      if( distance(blueZone[i],blueZone[k]) < min)
        min = distance(blueZone[i],blueZone[k]);
        //cout << blueZone[i].x << endl;
        //cout << blueZone[k].x << endl;
    }
  }

  //cout << "d: " << d << endl;
  //cout << "min: " << min << endl;

  return minimum(d,min);
}

int main() {
  size_t n;
  std::cin >> n;
  //vector<int> x(n);
  //vector<int> y(n);
  vector<Point> points(n);
  for (size_t i = 0; i < n; i++) {
    //std::cin >> x[i] >> y[i];
    cin >> points[i].x >> points[i].y;
  }
  sort( points.begin(), points.end(), compareX);

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points,0,n) << "\n";
}
