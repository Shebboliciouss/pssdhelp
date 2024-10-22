#include <bits/stdc++.h>
#define MAX 699
using namespace std;
 
 
class BearPlaysDiv2 {
public:
  int vis[MAX][MAX];
  struct node{
    int arr[3];  
  };
  
  string equalPiles(int A, int B, int C) {
    int sum = A + B + C;
        if(sum%3!=0)  return "impossible";
        
        node tmp;
        tmp.arr[0]=A;
        tmp.arr[1]=B;
        tmp.arr[2]=C;
    memset(vis,0,sizeof(vis));
 
        sort(tmp.arr, tmp.arr + 3);
        vis[tmp.arr[0]][tmp.arr[1]] = 1;
        queue<node> Q;
        Q.push(tmp);
        while(!Q.empty()){
            node foo = Q.front();
            if(foo.arr[0] == sum / 3 && foo.arr[1] == sum / 3) return "possible";
            Q.pop();
            for(int i=0;i<3;i++)
            {
                for(int j=i+1;j<3;j++)
                {
                    if(foo.arr[i] != foo.arr[j]){
                        node next=foo;
                        next.arr[j]=next.arr[j]-next.arr[i], next.arr[i]=next.arr[i]+next.arr[i];
                        sort(next.arr,next.arr+3);
                        if(!vis[next.arr[0]][next.arr[1]])
                        {
                            vis[next.arr[0]][next.arr[1]]=1;
                            Q.push(next);
                        }
                    }
                }
            }
        }
        return "impossible";
  }
};

import static java.util.Arrays.sort;

import java.util.HashMap;
import java.util.Map;

public class BearPlaysDiv2 {
  
  Map<Integer,Byte> used;
  
  static final int II = 1000 * 1000;
  static final int I = 1000;

  public String equalPiles(int A, int B, int C) {
    used = new HashMap<Integer, Byte>();
    return equalPiles(new int[]{A, B, C}) ? "possible" : "impossible";
  }

  private boolean equalPiles(int[] i) {
    sort(i);
    if(i[0]==i[1] && i[1]==i[2]) {
      used.put(i[0]*II+i[1]*I+i[2], (byte) 1);
      return true;
    }
    Byte b = used.get(i[0]*II+i[1]*I+i[2]);
    if(b != null && b != 0) return b == 1;
    boolean res = false;
    used.put(i[0]*II+i[1]*I+i[2], (byte) 2);
    res |= extracted(i, 0 ,1);
    res |= extracted(i, 0 ,2);
    res |= extracted(i, 1 ,2);
    used.put(i[0]*II+i[1]*I+i[2], (byte) (res ? 1:-1));
    return res;
  }

  private boolean extracted(int[] i, int f, int s) {
    if(i[f] < i[s]) {
      i = i.clone();
      change(i, f, s, i[f]);
      boolean r = equalPiles(i);
      change(i, f, s, i[f]/2);
      return r;
    } else return false;
  }

  private void change(int[] i, int j, int k, int l) {
    i[j] = i[j] + l;
    i[k] = i[k] - l;
  }
  
}

using System;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;



public class BearPlaysDiv2 {

    int[] ar = new int[3];

    void dfs(int a, int b, int c, Dictionary<Tuple<int, int, int>, int> vis, int depth)
    {
        if(depth > 10000){
            return;
        }

        vis.Add(new Tuple<int, int, int>(a, b, c), 1);

        if(a == b && a == c){
            return;
        }


        int b1 = b * 2;
        int a1 = a - b;
        int c1 = c;

        ar[0] = a1;
        ar[1] = b1;
        ar[2] = c1;

        Array.Sort(ar);
        a1 = ar[2];
        b1 = ar[1];
        c1 = ar[0];





        int b2 = b;
        int a2 = a - c;
        int c2 = c * 2;

        ar[0] = a2;
        ar[1] = b2;
        ar[2] = c2;

        Array.Sort(ar);
        a2 = ar[2];
        b2 = ar[1];
        c2 = ar[0];


        if(!vis.ContainsKey(new Tuple<int, int, int>(a1, b1, c1))){

            if(c1>0){
                dfs(a1, b1, c1, vis, depth+1);
            }
        }

        if (!vis.ContainsKey(new Tuple<int, int, int>(a2, b2, c2)))
        {
            if(c2>0){
                dfs(a2, b2, c2, vis, depth+1);
            }
        }

        return;
    }


    public string equalPiles(int A, int B, int C) {
        string res;

        ar[0] = A;
        ar[1] = B;
        ar[2] = C;

        Array.Sort(ar);
        A = ar[2];
        B = ar[1];
        C = ar[0];

        int summ = A + B + C;
        if(summ % 3 == 0){
            Dictionary<Tuple<int, int, int>, int> vis = new Dictionary<Tuple<int, int, int>, int>();
            dfs(A, B, C, vis, 0);

            bool r = vis.ContainsKey(new Tuple<int, int, int>(summ/3, summ/3, summ/3));
            if(r){
                return "possible";
            }
            else
            {
                return "impossible";
            }
        }
        else
        {
            return "impossible";
        }

        return res;
    }

}


/*
Problem Statement
    	
Limak is a little bear who loves to play. Today he is playing by moving some stones between three piles of stones. Initially, the piles contain A, B, and C stones, respectively. Limak's goal is to produce three equal piles.



Limak will try reaching his goal by performing a sequence of zero or more operations. In each operation he will start by choosing two unequal piles. Let's label their sizes X and Y in such a way that X < Y. He will then double the size of the smaller chosen pile by moving some stones between the two chosen piles. Formally, the new sizes of the two chosen piles will be X+X and Y-X.



You are given the ints A, B, and C. Return "possible" (quotes for clarity) if there is a sequence of operations that will make all three piles equal. Otherwise, return "impossible".

 
Definition
    	
Class:	BearPlaysDiv2
Method:	equalPiles
Parameters:	int, int, int
Returns:	String
Method signature:	String equalPiles(int A, int B, int C)
(be sure your method is public)
    
 
Constraints
-	A, B and C will be between 1 and 500, inclusive.
 
Examples
0)	
    	
10
15
35
Returns: "possible"
One valid sequence of operations looks as follows:
The initial pile sizes are 10, 15, and 35.
For the first operation Limak will choose the piles with 15 and 35 stones. After doubling the size of the smaller pile the new sizes of these two piles will be 30 and 20.
After the first operation the pile sizes are 10, 30, and 20.
For the second operation Limak will choose the piles with 10 and 30 stones. After doubling the size of the smaller pile the new sizes of these two piles will be 20 and 20.
After the second operation each pile has 20 stones, which means that Limak has reached his goal.
1)	
    	
1
1
2
Returns: "impossible"
No matter what Limak does, there will always be two piles with a single stone each and one pile with 2 stones.
2)	
    	
4
6
8
Returns: "impossible"
3)	
    	
18
18
18
Returns: "possible"
Sometimes Limak can reach his goal without making any operations.
4)	
    	
225
500
475
Returns: "possible"

*/