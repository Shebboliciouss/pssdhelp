/*
 Problem Statement for Travel
 
Problem Statement
    	
A traveling salesman has recently decided to go international and sell his wares around the globe. He has done in depth research and has come up with a list of cities which he thinks will provide the best market for his goods. In planning his trip, the salesman wants to minimize the total distance he has to travel because he does not particularly like traveling (which is unfortunate for him, as he is a traveling salesman) and furthermore, he figures the less distance he has to travel, the cheaper his trip will be. However, this salesman is not particularily good at math, and so you must write a computer program to help him find his way in the least distance.

You will be given a set of cities defined by their longitudes and latitudes. In addition, you will be given the radius of the planet that this traveling salesman resides on. Assume that there are direct flights, both ways, between every pair of cities that the salesman wants to visit, and that the flights follow the shortest path possible (over the surface of the planet). In addition, the first element of the input String[] will be the city in which the salesman lives, and thus his trip must start and end at this city.

Each city is defined by two numbers, a latitude and a longitude. The latitude is the number of degrees above the equator, with 90 being the north pole, and -90 being the south pole. The longitude is the number of degrees east or west of some arbitrary, predefined point. Thus, 90 degrees east is one quarter of the way around the globe in the eastern direction.

If the result is not an integer, round it to the nearest integer (.5 rounds up)

 
Definition
    	
Class:	Travel
Method:	shortest
Parameters:	String[], int
Returns:	int
Method signature:	int shortest(String[] cities, int radius)
(be sure your method is public)
    
 
Notes
-	Assume the planet is a perfect sphere.
-	To find the cartesion coordinates of a city, assuming the center of the planet is at (0,0,0), use the following formulas:

x = r*cos(latitude)*cos(longitude)

y = r*cos(latitude)*sin(longitude)

z = r*sin(latitude)
 
Constraints
-	cities contains between 2 and 9 elements, inclusive.
-	Each element of cities represents a unique point on the globe.
-	Each element of cities is formatted as "<latitude> <longitude>" where <latitude> is an integer in the range -90 to 90, inclusive, and <longitude> is an integer in the range -180 to 180, inclusive.
-	radius is an integer between 1 and 1,000, inclusive.
-	to avoid rounding errors, the shortest path, prior to rounding, will not be within 0.001 of <x>+0.5 for any integer <x>.
 
Examples
0)	
    	
{"0 0","0 1"}
1000
Returns: 35
The two cities are located one degree apart at the same latitude
1)	
    	
{"0 0","0 1","0 -1","-1 0","1 0","-1 -1","1 1","1 -1","-1 1"}
1
Returns: 0
2)	
    	
{"40 -82","-27 -59","-40 48"
,"26 -12","-31 -37","-30 42"
,"-36 -23","-26 71","-19 83","8 63"}
698
Returns: 4505
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
 
using namespace std;
 
typedef vector<int> VI;
typedef vector<string> VS;/*
typedef priority_queue PQ;
typedef string S;
typedef long long int64;
 
VS tok(S s, S sep)
{
  VS r;
  int i=0,j;
  while(i<s.size())
  {
    j = s.find_first_of(sep, i);
    if(j==-1) j=s.size();
    if(i!=j) r.push_back(s.substr(i, j-i));
    i = j+1;
  }
  return r;
}
 
VI toki(S s, S sep)
{
  VS a = tok(s, sep);
  VI r;
  for(int i=0; i<a.size();i++)
    r.push_back(atoi(a[i].c_str()));
  return r;
}
*/
 
#define PI 3.1415926
 
class Travel {
  public:
  double dist[10][10];
  float coor[10][2];
  int n;
  bool visited[10];
  double min;
  double d(int a, int b)
  {
    double x1, x2, y1, y2, z1, z2;
    x1 = cos(coor[a][0])*cos(coor[a][1]);y1=cos(coor[a][0])*sin(coor[a][1]);z1=sin(coor[a][0]);
    x2 = cos(coor[b][0])*cos(coor[b][1]);y2=cos(coor[b][0])*sin(coor[b][1]);z2=sin(coor[b][0]);
    double v=x1*x2+y1*y2+z1*z2;
    return acos(v);
  }
  void tr(int now, int vis, double dis)
  {
    if(vis==n-1)
    {
      if(min>dis+dist[now][0])
      min=dis+dist[now][0];
      return;
    }
    visited[now]=true;
    for(int i=0;i<n;i++)
    {
      if(!visited[i])
      tr(i, vis+1, dis+dist[now][i]);
    }
    visited[now]=false;
  }
  int shortest(vector <string> a, int b) {
    int i,j,k;
    n=a.size();
    for(i=0;i<a.size();i++)
    {
      sscanf(a[i].c_str(), "%f %f", &coor[i][0], &coor[i][1]);
      coor[i][0]/=180;coor[i][0]*=PI;
      coor[i][1]/=180;coor[i][1]*=PI;
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    dist[i][j] = d(i,j);
    for(i=0;i<n;i++)visited[i]=false;
    min=100000000;
    tr(0,0,0);
    return min*b+0.5001;
  }
};

import java.util.*;
import java.math.*;

public class Travel {
    double best = -1;

    int n;
    boolean[] visited;
    double[][] d;

    double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
  double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
  d = Math.sqrt(d) / 2;
  double t = Math.asin(d) * 2;
  return t;
    } 

    void visit(int k, int from, double sum) {
  if ( k == n - 1 ) {
      sum += d[from][0];
      if ( sum < best || best < 0 )
    best = sum;
      return;
  }

  for ( int i = 1; i < n; ++i )
      if ( ! visited[i] ) {
    visited[i] = true;
    visit(k+1, i, sum + d[from][i]);
    visited[i] = false;
      }
    }

    static double pi = 3.1416;
  public int shortest(String[] s, int radius) {
      n = s.length;
      double[] x = new double[10];
      double[] y = new double[10];
      double[] z = new double[10];

      for ( int i = 0; i < s.length; ++i ) {
    int[] m = new int[10];
    StringTokenizer st = new StringTokenizer(s[i], " ");
    int j = 0;
    while ( st.hasMoreTokens() ) {
        String t = st.nextToken();
        int k = Integer.parseInt(t);
            m[j++] = k;
    }

    double lat, lon;

    lat = m[0] * pi / 180; 
    lon = m[1] * pi / 180; 

    x[i] = Math.cos(lon) * Math.cos(lat);
    y[i] = Math.cos(lat) * Math.sin(lon);
    z[i] = Math.sin(lat);
    System.out.println(x[i] + " " + y[i] + " " + z[i]);
      }

      d = new double[n][n];

      for ( int i = 0; i < n; ++i )
    for ( int j = 0; j < n; ++j )
        {
        d[i][j] = radius * dist(x[i], y[i], z[i], x[j], y[j], z[j]);
        System.out.println(d[i][j]);
        }

      visited = new boolean[n];
      visit(0, 0, 0);
      return (int)(Math.round(best + 0.0001));
  }
}