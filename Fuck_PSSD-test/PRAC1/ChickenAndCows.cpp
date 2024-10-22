#include <iostream>
#include <vector>
using namespace std;

class ChickenAndCows{
public:
    vector<int> howMany(int heads,int legs)
        {
                vector <int> ans;
                ans.clear();
                int x=-1; int y=-1;

                if ((legs-2*heads)%2==0)
                {
                        y=(legs-2*heads)/2;
                        x=heads-y;
                }
                if (x<0) return ans;
                if (y<0) return ans;
                ans.push_back(x);
                ans.push_back(y);
        }
};

class OnTheFarmDivTwo {
public:
	vector <int> animals(int heads, int legs) {
		if ((4 * heads - legs) >= 0 && (4 * heads - legs) % 2 == 0 &&
			(legs - 2 * heads) >= 0 && (legs - 2 * heads) % 2 == 0)
			return vector<int> {(4 * heads - legs) / 2, (legs - 2 * heads) / 2};
		else
			return vector<int> {};
	}
};

class OnTheFarmDivTwo {
public:
  vector <int> animals(int heads, int legs) {
    double y = (legs - 2 * heads) / 2.0;
    double x = heads - y;
    if (y >= 0 && x >= 0 && int(y) == y && int(x) == x)
      return {int(x), int(y)};
    else 
      return {};
  }
};

