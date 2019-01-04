#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
struct IPoint{
  int number, label, ival;
  bool operator < (const IPoint& s) const
  {
    if(number == s.number)
      return (label < s.label);
    return (number < s.number);
  }
};

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  //
  vector<IPoint> data(starts.size() + ends.size() + points.size());
  for(int i=0;i<starts.size();i++)
  {
    data[i].number = starts[i];
    data[i].label  = -1;
    data[i].ival   = i;
  }

  for(int i=0;i<ends.size();i++)
  {
    data[i+starts.size()].number = ends[i];
    data[i+starts.size()].label  = 1;
    data[i+starts.size()].ival   = i;

  }


  int tp = starts.size() + ends.size();
   
  for(int i=0;i<points.size(); i++)
  {
    data[i+tp].number = points[i];
    data[i+tp].label  = 0;
    data[i+tp].ival   = i;
  }

  sort(data.begin(),data.end());


  int index = 0, cindex = 0;
  int segcount = 0;
  while(index < data.size() && cindex < points.size())
  {
    segcount += data[index].label;
    if(data[index].label == 0)
    {
      if(segcount >= 0)
      {
	cnt[data[index].ival] = 0;
      }
      else
	cnt[data[index].ival] = -segcount;
      cindex++;
    }
    index++;

  }
  

  



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
