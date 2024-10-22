


 Problem Statistics for Single Round Match 664 > Round 1 > Room 38 > ywiz

	Class Name	Method Name	 	Difficulty	Status	Score	

	[ BearCheats ]	eyesight	problem details	Level One	Passed System Test	249.81	
	BearPlaysDiv2	equalPiles	problem details	Level Two	Failed System Test	549.74	
	BearSortsDiv2	getProbability	problem details	Level Three	Opened	0.00	



View BearCheats   Problem Statement
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
 
class BearCheats {
public:
  string eyesight(int A, int B) {
    int cnt = 0;
    string a,b;
    stringstream ss;
    ss << A;
    ss >> a;
    ss.clear(stringstream::goodbit);
    ss << B;
    ss >> b;
    string h = "happy";
    string g = "glasses";
    if(a.size()!=b.size())return g;
    for(int i=0;i<a.size();i++){
      if(a[i]!=b[i])cnt++;
    }
    if(cnt>1)return g;
    return h;
    
  }
};

public class BearCheats {

  public String eyesight(int A, int B) {
    int diff = 0;
    while(A > 0) {
      if(A % 10 != B % 10) diff++;
      if(diff > 1) return "glasses";
      A/=10; B/=10;
    }
    return "happy";
  }
}

using System;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections;

public class BearCheats {
    public string eyesight(int A, int B) {
        string res = "";

        string a = A + "";
        string b = B + "";

        int cnt = 0;
        for (int i = 0; i < a.Length; i++ )
        {
            if(a[i] != b[i]){
                cnt++;
            }
        }


        if(cnt <= 1){
            return "happy";
        }
        else
        {
            return "glasses";
        }

        return res;
    }

}



/*
Problem Statement
    	
Limak is an old brown bear. Because of his bad eyesight he sometimes has to visit his doctor, Dr. Carrot. Today is one such day.



Dr. Carrot has a blackboard in his office. There is a number A written on the blackboard. In order to examine Limak's eyesight, Dr. Carrot asked him to read the number. Limak couldn't see the number really well. He could determine the number of digits correctly, but he was not sure what the individual digits are. Finally, he decided to announce the number B to the doctor. The doctor then left the office for a short while.



Limak really doesn't want to wear glasses, so he has decided to cheat. As soon as the doctor left the room, Limak went to the blackboard to read the correct number A. Before the doctor returns, Limak has the time to change one of the digits of A to any different digit. (Note that he may not add any new digits to A and he may not completely erase any digits of A. He may only change at most one of the digits.) Limak hopes that he can deceive the doctor by changing the number A into his number B.



You are given the ints A and B. Return the String "happy" (quotes for clarity) if Limak can convince the doctor that his eyesight is good. Otherwise, return the String "glasses".

 
Definition
    	
Class:	BearCheats
Method:	eyesight
Parameters:	int, int
Returns:	String
Method signature:	String eyesight(int A, int B)
(be sure your method is public)
    
 
Constraints
-	A and B will be between 1 and 999,999, inclusive.
-	A and B will have the same number of digits.
 
Examples
0)	
    	
8072
3072
Returns: "happy"
Limak wants to change 8072 into 3072. He can do that by changing the digit 8 to a 3.
1)	
    	
508
540
Returns: "glasses"
Limak would need to change two digits, but he only has the time to change at most one.
2)	
    	
854000
854000
Returns: "happy"
It is possible that Limak read the number correctly. If that happens, he will not change any digits.
3)	
    	
1
6
Returns: "happy"
4)	
    	
385900
123000
Returns: "glasses"

*/