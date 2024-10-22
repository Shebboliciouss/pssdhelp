#include <string>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<utility>
#include <vector>
using namespace std;
 
#define REP(i,n) for(int i = 0, _n=n; i<_n; ++i) 
#define FOR(i,a,b) for(int i=(a), _b = (b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a), _b = (b); i>=_b; --i)
 
bool between(int z1, int z2, int z3) {
  if ((z2<=z1)&&(z1<=z3)) return true;
  if ((z3<=z1)&&(z1<=z2)) return true;
  return false;
}
 
double pol(int xp, int x1, int y1, int x2, int y2) {
  if (x1>x2) { swap(x1,x2); swap(y1,y2); }
  double value;
  if (x1!=x2) {
    value = ((double)y1 + ((double)(y2-y1)/(double)(x2-x1))*(double)(xp-x1));
  } else {
    value = y1;
  }
  return value;
}
 
pair<double,double> count(int Xp, vector<int> & X, vector<int> & Y) {
  X.push_back(X[0]);
  Y.push_back(Y[0]);
  vector<double> tt;
  REP(i,X.size()-1) {
    if (between(Xp,X[i],X[i+1])) {
      tt.push_back(pol(Xp,X[i],Y[i],X[i+1],Y[i+1]));
    }
  }
  pair<double,double> aa;
  if (tt.size()==0) {
    aa.first = -1;
  } else {
    aa.first = tt[0]; aa.second = tt[0];
    REP(i,tt.size()) {
      aa.first = min(aa.first,tt[i]);
      aa.second = max(aa.second,tt[i]);
    }
  }
  return aa;
}
 
class CheckerPolygon {
  public:
  vector <int> countSquares(vector <int> X, vector <int> Y) {
    vector<pair<double,double> > tab;
    FOR(rzad,0,10000) {
      pair<double,double> result = count(rzad,X,Y);
      tab.push_back(result);
    }
    //FOR(i,2,4) cout << i << " " << tab[i].first << " " << tab[i].second << endl;
    int suma = 0;
    int suma1 = 0;
    int suma2 = 0;
    FOR(rzad,0,9999) {
      if ((tab[rzad].first<0)||(tab[rzad+1].first<0)) {
      } else {
        double z1 = max(tab[rzad].first,tab[rzad+1].first);
        double z2 = min(tab[rzad].second,tab[rzad+1].second);
        //cout << z1 << " " << z2 << endl;
        int w2 = (int) z2;
        int w1 = (int) z1;
        
        if (abs((double)w1-z1)>0.0000001) {
          w1++;
        }
        //cout << w1 << " " << w2 << endl;
        if (w2>=w1) {
          int k1 = 0; 
          int k2 = 0;
          if (w1%2==0) {
            k1=(w2-w1)/2+(w2-w1)%2;
            k2=(w2-w1)/2;
          } else {
            k2=(w2-w1)/2+(w2-w1)%2;
            k1=(w2-w1)/2;
          }
          if (rzad%2==0) {
            suma1+=k1;
            suma2+=k2;
            
          } else {
            suma1+=k2;
            suma2+=k1;
          }
          
          suma+=(w2-w1);
          //cout << suma << endl;
        }
      }
    }
    vector<int> temp;
    temp.push_back(suma1);
    temp.push_back(suma2);
 
    return temp;
    
  }
};

TopCoder problem "CheckerPolygon" used in TCCC05 Semi 3 (Division I Level Two)

Problem Statement
    	
A convex polygon is placed on a large checkerboard with the polygon vertices lying on the grid intersections. Calculate the number of light and dark squares lying entirely inside the polygon. Assume that the polygon edges are infinitely thin. In the picture below, 28 light squares and 26 dark squares are enclosed by the polygon. The upper left corner (coordinates 0,0) will always be a dark square.




Create a class CheckerPolygon containing the method countSquares which takes two int[], X and Y, describing the convex polygon. Element i in X and Y is the coordinate for the ith vertex in the polygon. The method should return a int[] containing exactly two elements: the first element is the number of light squares entirely enclosed by the polygon, and the second element the number of dark squares entirely enclosed by the polygon.

 
Definition
    	
Class:	CheckerPolygon
Method:	countSquares
Parameters:	int[], int[]
Returns:	int[]
Method signature:	int[] countSquares(int[] X, int[] Y)
(be sure your method is public)
    
 
Notes
-	The vertices in the polygon may be ordered clockwise or counter-clockwise.
 
Constraints
-	X and Y will contain between 3 and 50 elements, inclusive.
-	X will contain the same number of elements as Y.
-	Each element in X and Y will be between 0 and 10000, inclusive.
-	The polygon described by X and Y will be convex.
-	There will not be three points lying on the same line.
 
Examples
0)	
    	
{1,2,5,8,11,10,6,4,2}
{7,5,2,1,2,8,11,11,9}
Returns: {26, 28}
This is the example in the problem statement.
1)	
    	
{1,5000,5001,10000,10000,5001,5000,1}
{4999,0,0,4999,5000,9999,9999,5000}
Returns: {25000000, 24990001}
2)	
    	
{1,3,6}
{3,6,1}
Returns: {1, 1}
3)	
    	
{537,127,987,2390}
{173,98,12,107}
Returns: {90908, 90911}
