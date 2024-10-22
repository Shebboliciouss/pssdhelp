import java.util.ArrayList;
 
public class BearSortsDiv2 {
  int[] magic;
 
  public double getProbability(int[] seq) {
    magic = seq;
    T = new int[seq.length];
    for (int i = 0; i < T.length; i++) {
      T[i] = i + 1;
    }
    return Math.log(mergeSort(0, seq.length));
  }
 
  boolean LESS(int a, int b) {
    for (int i = 0; i < magic.length; i++) {
      if (magic[i] == a) {
        for (int j = i + 1; j < magic.length; j++) {
          if (magic[j] == b) {
            return true;
          }
        }
      }
    }
    return false;
  }
 
  int[] T;
 
  double mergeSort(int left, int right) {
    // if there is at most one element, we are done
    if (left + 1 >= right)
      return 1;
 
    // otherwise, split the sequence into halves, sort each half separately
    int mid = (left + right) / 2;
    double res = 1;
    res *= mergeSort(left, mid);
    res *= mergeSort(mid, right);
 
    // then merge the two halves together
    ArrayList<Integer> merged = new ArrayList<Integer>(); // an empty
                                // sequence
    int p1 = left;
    int p2 = mid;
    while ((p1 < mid) || (p2 < right)) {
      if (p1 == mid) {
        merged.add(T[p2]);
        p2++;
      } else if (p2 == right) {
        merged.add(T[p1]);
        p1++;
      } else {
        if (LESS(T[p1], T[p2])) {
          merged.add(T[p1]);
          res *= 0.5;
          p1++;
        } else {
          merged.add(T[p2]);
          res *= 0.5;
          p2++;
        }
      }
    }
    // finally, move the merged elements back into the original array
    for (int i = left; i < right; i++) {
      T[i] = merged.get(i - left);
    }
    return res;
  }
}


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class BearSortsDiv2
{
    List<int> input = new List<int>();
    List<int> output = new List<int>();
    public double getProbability(int[] seq)
    {
        for(int i=0;i<seq.Length;i++)
        {
            input.Add(i + 1);
            output.Add(seq[i]);
        }
        mergSort(0, seq.Length);

        return Math.Log(ans);
    }


//  # mergeSort(left,right) sorts elements left, left+1, ..., right-1 of a global array T
//  function mergeSort(left,right):
    public void mergSort(int left, int right)
    {
    //    # if there is at most one element, we are done
//    if left+1 >= right: return
        if(left+1>=right)
        {
            return;
        }

//    # otherwise, split the sequence into halves, sort each half separately
//    mid = (left + right) div 2
//    mergeSort(left,mid)
//    mergeSort(mid,right)
        int mid = (left + right) / 2;
        mergSort(left, mid);
        mergSort(mid, right);

//    # then merge the two halves together
//    merged = []    # an empty sequence
//    p1 = left
//    p2 = mid
        List<int> merged = new List<int>();
        int p1 = left, p2 = mid;

//    while (p1 < mid) or (p2 < right):
        while (p1 < mid || p2 < right)
        {
//        if p1 == mid:
            if (p1 == mid)
            {
//            merged.append( T[p2] )
//            p2 += 1
                merged.Add(input[p2]);
                p2++;
            }//        else if p2 == right:
            else if (p2 == right)
            {
                //            merged.append( T[p1] )
                //            p1 += 1
                merged.Add(input[p1]);
                p1++;
            }//        else:
            else
            {
//            if LESS( T[p1], T[p2] ):
                if (less(p1,p2))
                {
                    //                merged.append( T[p1] )
                    //                p1 += 1
                    merged.Add(input[p1]);
                    p1++;
                }//            else:
                else
                {
//                merged.append( T[p2] )
//                p2 += 1
                    merged.Add(input[p2]);
                    p2++;
                }
            }
        }
//    # finally, move the merged elements back into the original array
//    for i from left to right-1 inclusive:
//        T[i] = merged[i-left]
        for(int i=left;i<right;i++)
        {
            input[i] = merged[i - left];
        }

    }

    double ans=1;

    public bool less(int p1, int p2)
    {
        ans*=0.5;

        for(int i=0;i<output.Count;i++)
        {
            if(output[i]==input[p1])
            {
                return true;
            }
            else if(output[i]==input[p2])
            {
                return false;
            }
        }

        return true;// this should not be called!!!
    }

    public static void Main()
    {
        BearSortsDiv2 obj = new BearSortsDiv2();

        int[] cc = { 1, 2 };

        obj.getProbability(cc);
    }
}


#include <bits/stdc++.h>
using namespace std;
 
double l;
 
double licz(vector <int> wek)
{
    int n=wek.size();
    int m=n/2;
    int ost1=0, ost2=0;
    if (n==1)
    return 0.0;
    vector <int> jed;
    vector <int> dwa;
    for (int i=0; i<n; i++)
    {
        if (wek[i]<m)
        {
            jed.push_back(wek[i]);
            ost1=i;
        }
        else
        {
            dwa.push_back(wek[i]-m);
            ost2=i;
        }
    }
    double ret=0;
    for (int i=0; i<=min(ost1, ost2); i++)
    {
        ret+=l;
    }
    return ret+licz(jed)+licz(dwa);
}
 
struct BearSortsDiv2
{
     double getProbability(vector <int> wek)
     {
        l=log(0.5);
        for (int i=0; i<wek.size(); i++)
        {
            wek[i]--;
        }
        return licz(wek);
     }
};


/*



 Problem Statement for BearSortsDiv2


Problem Statement
    	
Bear Limak was chilling in the forest when he suddenly found a computer program. The program was a correct implementation of MergeSort. Below you can find the program in pseudocode.



# mergeSort(left,right) sorts elements left, left+1, ..., right-1 of a global array T
function mergeSort(left,right):
    # if there is at most one element, we are done
    if left+1 >= right: return

    # otherwise, split the sequence into halves, sort each half separately
    mid = (left + right) div 2
    mergeSort(left,mid)
    mergeSort(mid,right)

    # then merge the two halves together
    merged = []    # an empty sequence
    p1 = left
    p2 = mid
    while (p1 < mid) or (p2 < right):
        if p1 == mid:
            merged.append( T[p2] )
            p2 += 1
        else if p2 == right:
            merged.append( T[p1] )
            p1 += 1
        else:
            if LESS( T[p1], T[p2] ):
                merged.append( T[p1] )
                p1 += 1
            else:
                merged.append( T[p2] )
                p2 += 1

    # finally, move the merged elements back into the original array
    for i from left to right-1 inclusive:
        T[i] = merged[i-left]


Limak noticed that one part of the implementation was missing: the function LESS. You can probably guess that the function is supposed to return a boolean value stating whether the first argument is less than the second argument. However, Limak is a bear and he didn't know that. Instead he implemented his own version of this function. Limak's function uses a true random number generator. Each of the two possible return values (true, false) is returned with probability 50 percent.



The random values generated in different calls to Limak's function LESS are mutually independent. Note that even if you call LESS twice with the same arguments, the two return values may differ.



After implementing LESS, Limak decided to run his brand new program. He initialized the global array T to contain N elements. Then, he filled the values 1 through N into the array: for each valid i, he set T[i] to i+1. Finally, he executed the function mergeSort(0,N).



Even with Limak's new LESS function, the program never crashes. On the other hand, it does not necessarily produce a sorted sequence when it terminates. In general, when the program terminates, the array T will contain some permutation of the numbers 1 through N.



After running the program many times, Limak has noticed that different output permutations are produced with different probabilities. Your task is to help him learn more about these probabilities. More precisely, your task is to compute the probability that a given sequence will appear as the output of Limak's program.



You are given a int[] sortedSequence with N elements, containing a permutation of 1 through N. Let P be the probability that Limak's program, when run on an array with N elements, outputs this permutation. Return the value log(P), where log denotes the natural (base e) logarithm.

 
Definition
    	
Class:	BearSortsDiv2
Method:	getProbability
Parameters:	int[]
Returns:	double
Method signature:	double getProbability(int[] seq)
(be sure your method is public)
    
 
Notes
-	Your return value must have absolute or relative error smaller than 1e-9.
-	You may assume that for each N and for each permutation P of 1 through N the probability that P appears as the output of Limak's program is strictly positive.
 
Constraints
-	sortedSequence will contain exactly N elements.

-	N will be between 1 and 40, inclusive.

-	Elements of sortedSequence will be between 1 and N, inclusive.

-	Elements of sortedSequence will be pairwise distinct.
 
Examples
0)	
    	
{1,2}
Returns: -0.6931471805599453
Limak is sorting a 2-element sequence. The algorithm will split it into two 1-element sequences and then it will merge those together. While merging, the algorithm will call LESS(1, 2) to "compare" the two elements. If LESS(1, 2) returns true, the resulting permutation will be {1, 2}, otherwise it will be {2, 1}. Therefore, the probability of each of those two permutations is equal to 0.5. The return value is log(0.5).
1)	
    	
{1,3,2}
Returns: -1.3862943611198906
When {1, 2, 3} is sorted, it is first split into {1} and {2, 3}. After that, in order to obtain {1, 3, 2} in the end, two things must happen, one after another:
When {2, 3} is recursively sorted, the result must be {3, 2}. From Example 0 we know this happens with probability 0.5.
When merging {1} and {3, 2}, the first call to LESS will be LESS(1, 3). This call must return true. Again, this happens with probability 0.5.
Therefore, the probability is 0.5 * 0.5 = 0.25, and the answer is log(0.25).
2)	
    	
{10,13,18,2,4,6,24,22,19,5,7,20,23,14,21,17,25,3,1,11,12,8,15,16,9}
Returns: -57.53121598647546
*/