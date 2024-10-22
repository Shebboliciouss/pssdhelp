#include <bits/stdc++.h>
using namespace std;



struct ThreeTeleports{

#define ll long long
int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> tp)
{
	int n;
	ll best = abs(xMe - xHome) + abs(yMe - yHome);
	for(int i = 0; i < tp.size(); i++)
	{
		stringstream ss(tp[i]);
		vector<int>t;
		while(ss>>n){
			t.push_back(n);
		}

		vector<string>temp;
		for(int j = 0; j < tp.size(); j++)
		{
			if(j == i)continue;
			temp.push_back(tp[j]);
		}	

		ll dist1 = abs(xMe - t[0]) + abs(yMe - t[1]);
		ll dist2 = abs(xMe - t[2]) + abs(yMe - t[3]);

		best = min(best, dist1 + 10L + shortestDistance(t[2], t[3], xHome, yHome, temp));
		best = min(best, dist2 + 10L + shortestDistance(t[0], t[1], xHome, yHome, temp));
	}
	return (int)best;
};

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class ThreeTeleports {
  public:
    int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports);
    vector <int> Order;
    void Permute(int index);
};

int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, 
                                     vector <string> teleports)
{
  vector <long long> X, Y;
  int i, x1, x2, y1, y2;

  /* Create the vectors X and Y, which hold the x and y coordinates of the eight
     locations that we care about. */

  X.push_back(xMe);
  Y.push_back(yMe);

  for (i = 0; i < teleports.size(); i++) {
    sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
    X.push_back(x1);
    Y.push_back(y1);
    X.push_back(x2);
    Y.push_back(y2);
  }

  X.push_back(xHome);
  Y.push_back(yHome);
  
  /* We use %lld to print out long long's using printf(). */

  for (i = 0; i < X.size(); i++) printf("[%lld,%lld]\n", X[i], Y[i]);

  return 0;
}

class ThreeTeleports {
public:
  int shortestDistance(int, int, int, int, vector <string>);
};
 
int ThreeTeleports::shortestDistance(int xM, int yM, int xH, int yH, vector <string> tel) {
  int link[110][110],xyt[55][4],x[110],y[110],l=tel.size();
  for (int i=0;i<tel.size();i++){
        int xx=0,yy=0;
      for (int j=0;j<tel[i].size();j++){
          if (tel[i][j]==' ') {
                 xyt[i][yy++]=xx;
                 xx=0;
            }
          else xx=xx*10+tel[i][j]-'0';
            if (j==tel[i].size()-1) xyt[i][yy++]=xx;
         }          
     }
     x[0]=xM; y[0]=yM;
     int gs=1;
     memset(link,-1,sizeof(link));
     for (int i=0;i<l;i++){
         x[gs]=xyt[i][0];
         y[gs++]=xyt[i][1];
         x[gs]=xyt[i][2];
         y[gs++]=xyt[i][3];
         link[gs-2][gs-1]=link[gs-1][gs-2]=10;
         
     }
     x[gs]=xH;
     y[gs++]=yH;
     for (int i=0;i<gs;i++)
         for (int j=0;j<gs;j++)
             if (link[i][j]==-1 || (abs(x[i]-x[j])+abs(y[i]-y[j])<link[i][j]))
                link[i][j]=link[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
     
     for (int k=0;k<gs;k++)
         for (int i=0;i<gs;i++)
             if (i!=k && link[i][k]!=-1)
             for (int j=0;j<gs;j++)
               if (j!=k && j!=i && link[k][j]!=-1)
                  if (link[i][k]<link[i][j]-link[k][j] || link[i][j]==-1)
                     link[i][j]=link[i][k]+link[k][j];
     return link[0][gs-1];
}

// dp shortest path, but then i found that it is bellman ford algorithm
// wrong, should be something wrong with constructing graph
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	int t[3][4];
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		for (int j = 0; j < 4; j++) {
			ss >> t[i][j];
		}
	}
	int g[8][8];
	memset(g, -1, sizeof(g));
	g[6][7] = d(xMe, yMe, xHome, yHome);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			g[6][i * 2 + j] = d(xMe, yMe, t[i][2 * j], t[i][2 * j + 1]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			g[i * 2 + j][7] = d(t[i][2 * j], t[i][2 * j + 1], xHome, yHome);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[i * 2][i * 2 + 1] = 10;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 2; l++) {
					if (i != k) {
						g[i * 2 + j][k * 2 + l] = d(t[i][2 * j], t[i][2 * j + 1], t[k][2 * l], t[k][2 * l + 1]);
					}
				}
			}
		}
	}
	long long inf = 0x4040404040404040;
	long long dp[8];
	memset(dp, 0x40, sizeof(dp));
	dp[6] = 0;
	while (1) {
		bool bo = true;
		for (int i = 0; i < 8; i++) {
			if (dp[i] != inf) {
				for (int j = 0; j < 8; j++) {
					if (g[i][j] != -1) {
						int t = dp[i] + g[i][j];
						if (t < dp[j]) {
							bo = false;
							dp[j] = t;
						}
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	return dp[7];
}
// dp shortest path (bellman ford algorithm), but this time construct graph correct
int d(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long dp[8];
	memset(dp, 0x10, sizeof(dp));
	dp[0] = 0;
	while (1) { // this can be improved to do at most 8 - 1 operations
		bool bo = true;
		for (int i = 0; i < 8; i++) {
			if (dp[i] != inf) {
				for (int j = 0; j < 8; j++) {
					long long t = dp[i] + g[i][j];
					if (t < dp[j]) {
						bo = false;
						dp[j] = t;
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	return dp[1];
}
// floyd warshall shortest path algorithm
int d(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	return g[0][1];
}
// dijkstra algorithm without priority queue
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	bool v[8];
	memset(v, 0, sizeof(v));
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	for (int i = 0; i < 7; i++) {
		int n = -1;
		for (int j = 0; j < 8; j++) {
			if ((n == -1 || d[j] < d[n]) && !v[j]) {
				m = d[j];
				n = j;
			}
		}
		if (n == -1) {
			break;
		}
		v[n] = true;
		for (int j = 0; j < 8; j++) {
			d[j] = min(d[j], d[n] + g[n][j]);
		}
	}
	return d[1];
}
// dijkstra with set
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	set< pair<long long, int> > s;
	s.insert(make_pair(0, 0));
	while (!s.empty()) {
		int n = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < 8; i++) {
			long long t = d[n] + g[n][i];
			if (t < d[i]) {
				if (d[i] != inf) {
					s.erase(s.find(make_pair(d[i], i)));
				}
				d[i] = t;
				s.insert(make_pair(t, i));
			}
		}
	}
	return d[1];
}
// dijkstra with set alternative, i think is cleaner
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	set< pair<long long, int> > s;
	s.insert(make_pair(0, 0));
	while (!s.empty()) {
		int n = s.begin()->second;
		int nd = s.begin()->first;
		s.erase(s.begin());
		if (nd <= d[n]) {
			for (int i = 0; i < 8; i++) {
				long long t = d[n] + g[n][i];
				if (t < d[i]) {
					d[i] = t;
					s.insert(make_pair(t, i));
				}
			}
		}
	}
	return d[1];
}
// bellman ford
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	for (int i = 0; i < 8 - 1; i++) {
		bool bo = true;
		for (int j = 0; j < 8; j++) {
			if (d[j] != inf) {
				for (int k = 0; k < 8; k++) {
					long long t = d[j] + g[j][k];
					if (t < d[k]) {
						bo = false;
						d[k] = t;
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	return d[1];
}