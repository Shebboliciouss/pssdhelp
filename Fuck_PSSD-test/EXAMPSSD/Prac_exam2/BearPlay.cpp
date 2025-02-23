using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections;

public class BearPlays 
{
    public int pileSize(int a, int b, int k)
    {
        long m = ((long)a + b);
        long p = 1;
        long t = 2;
        while (k > 0)
        {
            if (k % 2 == 1)
                p = (p * t) % m;
            t = (t * t) % m;
            k /= 2;
        }
        long v = (a * p) % m;
        long v1 = ((long)a + b) - v;
        return v < v1 ? (int)v : (int)v1;
    }

}

public class BearPlays {
    public int pileSize(int A, int B, int K) {
        long s1 = A * pow(2, K, A + B) % (A + B);
        long s2 = A + B - s1;
        return (int) Math.min(s1, s2);
    }
 
    private long pow(long a, long k, long mod) {
        if (k == 0) return 1 % mod;
        if (k % 2 == 0) {
            return pow(a * a % mod, k / 2, mod);
        }
        return a * pow(a, k - 1, mod) % mod;
    }
 
}

#include <bits/stdc++.h>
 
using namespace std;
 
class BearPlays {
public:
  long long bin(long long x, long long a, long long mod) {
    long y = 1;
    while (a) {
      if (a & 1) {
        y = (y * x) % mod;
      }
      x = (x * x) % mod;
      a >>= 1;
    }
    return y;
  }
  
  int pileSize(int A, int B, int K) {
    long long a = A, mod = A + B;
    a = (a * bin(2, K, mod)) % mod;
    long long b = mod - a;
    return min(a, b);
  }
};


Problem Statement
    	
Limak is a little bear who loves to play. Today he is playing by moving some stones between two piles of stones. Initially, one of the piles has A and the other has B stones in it.



Limak has decided to perform a sequence of K operations. In each operation he will double the size of the currently smaller pile. Formally, if the current pile sizes are labeled X and Y in such a way that X <= Y, he will move X stones from the second pile to the first one. After this move the new pile sizes will be X+X and Y-X.



You are given the ints A, B, and K. Determine the pile sizes after Limak finishes all his operations. Return the size of the smaller of those piles.



Formally, suppose that the final pile sizes are labeled P and Q in such a way that P <= Q. Return P.

 
Definition
    	
Class:	BearPlays
Method:	pileSize
Parameters:	int, int, int
Returns:	int
Method signature:	int pileSize(int A, int B, int K)
(be sure your method is public)
    
 
Notes
-	Pay attention to the unusual time limit.
 
Constraints
-	A and B will be between 1 and 1,000,000,000, inclusive.

-	K will be between 1 and 2,000,000,000, inclusive.
 
Examples
0)	
    	
4
7
2
Returns: 5
The process will look as follows:
Initially, the pile sizes are 4 and 7.
First operation: Limak doubles the pile of size 4 by moving 4 stones from the other pile to this pile. The new pile sizes are 8 and 3.
Second operation: Limak doubles the pile of size 3. The final pile sizes are 5 and 6.
As 5 <= 6, the correct return value is 5.
1)	
    	
5
5
3
Returns: 0
The initial pile sizes are 5 and 5. In the first operation Limak will double one of them, so after the operation the new pile sizes will be 10 and 0. The second and third operation do nothing: in each of them Limak doubles the size of an empty pile.



As 0 ≤ 10, the correct return value is 0.

2)	
    	
2
6
1
Returns: 4
After the only operation the pile sizes will be 4 and 4, hence the correct return value is 4.
3)	
    	
2
8
2000000000
Returns: 2
4)	
    	
900000000
350000000
3
Returns: 300000000
