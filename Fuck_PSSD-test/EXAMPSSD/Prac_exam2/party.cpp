Given m, the minimum distance between two elements of D and a[r], the minimum element of D 
what is the maximum number of elements we can add? Note that no element can be larger than 
a[r] + km. The inclusion of a[r] means that we cannot add any element smaller than a[r] + m, 
because it would mean that the added element is smaller than a[r] (breaking the condition that 
a[r] is the minimum) or it would break the requirement that the distances be larger than m. 
So the next element to add should be larger than a[r] + m. If we add any element x as the second-smallest element, 
it will make us unable to add any new elements smaller than x + m, so the smaller x is , the less restrictions we 
will have. In other words, we should always add the smallest element possible. We begin with d_0 = a[r], then we 
pick d_1 as the smallest element that is larger than d_0 + m, then d_2 should be the smallest element larger than 
d_1 + m and so and so until the elements become so large that we cannot add them without breaking the rule that 
they should be at most a[r] + km. Searching for these elements will take O(n) time for a total complexity of O(n^4).



int maxsize(vector < int > a, int k) {
  int n = a.size();
  sort(a.begin(), a.end());
  int res = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long mindif = abs(a[i] - a[j]);
      // the minimum difference between two elements of S is mindif
      long maxdif = k * mindif;

      for (int r = 0; r < n; r++) {
        // a[r] is the smallest element in this case
        int c = 1;
        int p = r;
        for (int s = r + 1; s < n; s++) {
          // always pick the smallest element allowed:
          if (a[s] >= a[p] + mindif) {
            if (a[s] - a[r] <= maxdif) {
              p = s;
              c++;
            }
          }
        }
        res = std::max(res, c);
      }
    }
  }

  return res;
}



import java.util.Arrays;
 
public class CliqueParty {
 
  public int maxsize(int[] a, int k) {
    Arrays.sort(a);
    int res = 1;
    int n = a.length;
    for (int min = 0; min < n; min++) {
      for (int max = min + 1; max < n; max++) {
        int diff = a[max] - a[min];
        int atleast = (diff - 1) / k + 1;
        int last = a[min];
        int cnt = 1;
        for (int j = min + 1; j <= max; j++) {
          if (a[j] >= last + atleast) {
            cnt++;
            last = a[j];
          }
        }
        res = Math.max(res, cnt);
      }
    }
    return res;
  }
 
}


class CliqueParty {
public:
  int maxsize(vector <int> a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int mn = (a[j] - a[i] + k - 1) / k;
        int cnt = 2;
        int last = a[i];
        for (int k = i + 1; k < j; k++) {
          if (a[k] - last >= mn && a[j] - a[k] >= mn) {
            cnt++;
            last = a[k];
          }
        }
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};

/*
Problem Statement
    	
A set of positive integers is called k-smooth if each pair (A,B) of elements of the set satisfies A <= k * B. For example, the set {3,4,7,9} is 3-smooth but the set {30,60,100} is not: 100 is strictly more than 3 * 30.

Hero likes some sets of integers. In order to determine whether he likes a set S, Hero uses the following procedure:
Form a new set D of pairwise differences of elements in S. In other words: for each pair of elements A, B in S, put the number |A-B| into D.
Hero likes the original set S if and only if the new set D is k-smooth.
You are given a int[] a containing a set of distinct integers. You are also given the int k Hero uses while determining whether he likes a set of integers.
Select the largest subset of a Hero likes. Return the number of elements in that subset.

 
Definition
    	
Class:	CliqueParty
Method:	maxsize
Parameters:	int[], int
Returns:	int
Method signature:	int maxsize(int[] a, int k)
(be sure your method is public)
    
 
Constraints
-	Number of elements in a will be between 2 and 50, inclusive.
-	Each elements in a will be between 1 and 1,000,000,000, inclusive.
-	All elements in a will be distinct.
-	k will be between 1 and 1,000,000,000, inclusive.
 
Examples
0)	
    	
{1,2,3}
2
Returns: 3
Hero likes the entire set a.
1)	
    	
{1,2,3}
1
Returns: 2
Here, Hero does not like the entire set a, but he does like, for example, the subset {1,3}.
2)	
    	
{4,10,5,6}
2
Returns: 3
3)	
    	
{1,2,3,4,5,6}
3
Returns: 4
4)	
    	
{10,9,25,24,23,30}
7
Returns: 4


*/