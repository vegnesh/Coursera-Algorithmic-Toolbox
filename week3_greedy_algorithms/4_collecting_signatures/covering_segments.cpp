#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
  bool operator < (const Segment& s) const
  {
    if(start == s.start)
      return (end < s.end);
    return (start < s.start);
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here

  sort(segments.begin(),segments.end());
  int min;
  int j;

  for(int i=0;i<segments.size();i++)
  {

    min = segments[i].end;
    j = i+1;
    for(;j<segments.size();j++)
    {
      
      if( segments[j].start > min )
      {
	//std::cout<<"Inner:"<<segments[j].start <<" "<<min<<"\n";
	break;
      }
      else if(segments[j].end < min)
      {
	min = segments[j].end;
      }
      
    }
   i = j-1;
   points.push_back(min);

   // std::cout<<segments[i].start<<" "<<segments[i].end<<"\n";


  }

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
