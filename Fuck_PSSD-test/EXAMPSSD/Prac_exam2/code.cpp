Topcoder
CUSTOMER
TALENT
ABOUT US
Tool
CJ
icon
What makes you, you?
Share a little something about you. AI can help.
Add Bio
close
December 22, 2013
SRM 601
Thrive - default banner
Thrive banner shape
article author avatar
[[rng_58]]
[[rng_58]]
DURATION
30 min
CATEGORIES
Competitive Programming
SRM Editorials
TAGS
Brute Force
Dynamic Programming
Greedy
SHARE

COMPETITIVE PROGRAMMING AT TOPCODER
MATCH SUMMARY
Round Overview
Discuss this match

SRM 601, or the match right between SRM 600 and the last match of the year. It might not be the most special match this year, or the most special match this month, but it was a rare chance to have some topcoder fun on a Sunday. The problem set was provided by Witaliy. The focus seems to have been dynamic programming, as the 3 hardest problems were all dynamic programming ones with interesting twists. In division 1, coders were welcome with an ad hoc problem that needed some good observations to work. tourist broke the speed barrier in this problem, solving it in just a couple of minutes. The medium problem was both an easy dynamic programming problem and a complicated dynamic programming problem. It was all up to the coders’ creativity at coming up with clever ways to reduce a problem to a simpler one. No surprise that a coder like Petr, who is very good at exactly that, solved the problem in only 8 minutes. The hardest problem was also a dynamic programming one, this one needed a magic trick to get rid of two complexity factors. Yet the problem was another triumph for Petr, even though this time other 9 coders solved it as well. Between the two speed records and the still very fast solution to 250, Petr won the division with a very comfortable lead of over 200 points. This is Petr’s 100-th division 1 win. This is also the fifth time Petr is mentioned in this commentary. Turns out SRM 601 was special after all!

WINTERANDMANDARINS
Problem Details

Used as: Division Two - Level One:

Value	250
Submission Rate	1004 / 1110 (90.45%)
Success Rate	786 / 1004 (78.29%)
High Score	yarned for 248.79 points (1 mins 59 secs)
Average Score	213.75 (for 786 correct submissions)
A very quick idea is to do a brute force for the smallest and the largest bags of mandarins. We cannot pick any pair of maximum and minimum, we are interested only in pairs such that there are at least `K` bags within that range. If the pair is valid, then the difference is a candidate difference between the largest and smallest bag, we should remember the smallest difference.

The following Java solution uses this logic:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
public int getNumber(int[] bags, int K) {
  int res = Integer.MAX_VALUE;
  int n = bags.length;
  // smallest bag bag[i]:
  for (int i = 0; i < n; i++) {
    // largest bag bag[j], a different one:
    for (int j = 0; j < n; j++) {
      if ((i != j) && (bags[i] <= bags[j])) {
        // count bags in this interval:
        int c = 2;
        for (int k = 0; k < n; k++) {
          if ((k != i) && (k != j) && (bags[i] <= bags[k]) && (bags[k] <= bags[j])) {
            c++;
          }
        }
        if (c >= K) { //enough bags:
          res = Math.min(res, bags[j] - bags[i]);
        }
      }
    }
  }
  return res;
}
Simpler code comes in exchange of having to do more analysis. It tends to be helpful to sort an array before processing it. If we assume the bags array is sorted and we decide that the smallest bag will have index `i`, then there will be exactly `K` bags between index `i` and index `i + K - 1`, inclusive. Index `i + K - 1` will be the one that will contain the smallest possible K-th bag when bag i is the smallest. So the result is equal to the minimum difference (bag[i + K - 1] - bag[i]) for each `(i < n - K)`. This is the approach used by the following c++ and python solutions.

1
2
3
4
5
6
7
8
9
int getNumber(vector < int > bags, int K) {
  sort(bags.begin(), bags.end());
  int n = bags.size();
  int res = numeric_limits < int > ::max(); //init result with something large
  for (int i = 0; i + K <= n; i++) {
    res = std::min(res, bags[i + K - 1] - bags[i]);
  }
  return res;
}
1
2
3
4
5
class WinterAndMandarins:
  def getNumber(self, bags, K):
  bags = sorted(bags)
return min(bags[i + K - 1] - bags[i]
  for i in range(0, len(bags) - K + 1))
WINTERANDCANDIES
Problem Details

Used as: Division Two - Level Two:

Value	500
Submission Rate	794 / 1110 (71.53%)
Success Rate	673 / 794 (84.76%)
High Score	so_what for 494.18 points (3 mins 5 secs)
Average Score	369.17 (for 673 correct submissions)
In this combinatorics problem, the first decision to make is the integer `K`. Let’s try all valid values for `K`, and count for each of them the number of ways to pick a valid subset of candies. The value of `K` might be between 1 and `n`.

For a given `K`, the subset of candy must contain exactly one candy of type 1, one candy of type 2, … and one candy of type `K`. The choice we make for a type of candy does not affect our available options for the other types of candy. Thus they are independent, which means that the total number of ways to pick the subset is equal to: (Number of options for type 1 candy) * (Number of options for type 2 candy) * … (Number of options for type K candy). The number of options for each type of candy is equal to the number of candy of that type in the original set.

In short, the result for `K` is equal to the following product:
`c(1) * c(2) * … c(K)`

Where `c(i)` is the number of candy of type `i`. And the final result is to sum up the results for each `K`.

C++ CODE
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
int getNumber(vector < int > type) {
  // we'll use the cnt map to grab the counts of each type of candy.
  map < int, int > cnt;
  for (int x: type) {
    cnt[x]++;
  }
  int p = 1;
  int res = 0;
  for (int k = 1; k <= type.size(); k++) {
    // add cnt[1] * cnt[2] * ... cnt[k]:
    // p is currently = cnt[1] * ...  * cnt[k-1]
    p *= cnt[k];
    res += p;
  }
  return res;
}
PYTHON CODE
1
2
3
4
5
6
7
8
9
10
11
class WinterAndCandies:
  def getNumber(self, t):
  def product(a, b):
  return a * b

def withK(k): # solves
for a given K
return reduce(product, [t.count(i) for i in range(1, k + 1)])
# multiply all t.count(i) for i = 1...k

return sum(withK(k) for k in range(1, len(t) + 1)) # sum of all K
WINTERANDREINDEERS
Problem Details

Used as: Division Two - Level Three:

Value	1000
Submission Rate	59 / 1110 (5.32%)
Success Rate	10 / 59 (16.95%)
High Score	a06 for 464.64 points (42 mins 46 secs)
Average Score	398.83 (for 10 correct submissions)
This problem is similar to the longest common sub-sequence which is a classical dynamic programming problem. The main difference is that, in addition to being a longest common subsequence to `A` and `B`, the wanted string must also contain `C` as a sub-string.

I suggest to do the same thing you’d do to solve the LCS problem, but with a slight modification. Usually we have `f(i,j)` which returns the LCS of the substring of `A` starting at index `i` and the substring of `B` starting at index `j`. But we will add a parameter `d` which is 0 if we want the substring to contain `C` as a substring and 1 otherwise, so we have `f(i,j, d)`. When `d = 1`, it is easy to see that the solution is the same as the LCS. What can we do when `d = 0` ?

If `d = 0` and `i = |A|` or `j = |B|`, then at least one of the sub-strings is empty, the longest common subsequence is “” and it won’t contain `C`. We should mark this case as invalid, return `-oo` , a very low negative number so if the result of `f(i,j,d)` is used in a sum, the sum stays invalid.

Otherwise, we can do the usual subsequence matching, same as LCS:

If `A[i] = B[j]`, we can match the two characters. A candidate for LCS is: `1 + f(i+1, j+1, d)`.

Another candidate is: `f(i+1, j, d)`, we ignore the character `A[i]`.

Also : `f(i, j+1, d)`.

However, we also need to take care of `C`. We should have a `C` in the common subsequence we find. Which means `C` must be a subsequence of `A[i], A[i+1], …` and a subsequence of `B[j], B[j+1], …`. Imagine we find that all characters of `C` exist as subsequence of `A[i], A[i+1], …, A[e_A-1]` and as a subsequence of `B[j], B[j+1], …, B[e_B-1]`, then we can create a common subsequence that starts with `C`, and then continues with whatever common subsequence we can find after `e_A` and `e_B`. In other words: `|C| + f(e_A, e_B, 1)` is a candidate subsequence. Note that `d` became `1` because we no longer need the remaining subsequence to contain `C`.

An issue with that approach is to find the `e_A` and `e_B` values. For a given `i`, there might be multiple `e_A` values, but we should find the smallest to maximize the available characters when we calculate `f(e_A, e_B, 0)` and thus maximize the LCS. So we should find, for each `i`, the minimum `e_A` for which `C` is a subsequence of `A[i], A[i+1], … A[e_A - 1]`. A similar problem needs to be solved for `e_B`. We can precalculate the solutions to both problems in `O(|A|^2)` and `O(|B|^2)` time, respectively.

CODE
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
const int INF = 50000;
int dp[2501][2501][2];

int cEndA[2501];
int cEndB[2501];

// For each i, find the minimum cEnd[i], such that the substring [i, cEnd[i] )
// of A contains C as a subsequence.
void makeCEnd(const string & A,
  const string & C, int * cEnd) {
  int n = A.size();
  int m = C.size();
  // For each i:
  for (int i = 0; i < n; i++) {
    cEnd[i] = -1; //If none exist, mark with -1
    int k = 0;
    // Find the characters of C one by one, finish when we find them all:
    for (int j = i; j < n; j++) {
      if (A[j] == C[k]) {
        k++;
        if (k == m) {
          cEnd[i] = j + 1;
          break;
        }
      }
    }
  }
}

int getNumber(const string & A,
  const string & B,
    const string & C) {
  //Assume we already concatenated the contents of allA, allB and allC
  // precalculate cEndA:
  makeCEnd(A, C, cEndA);
  // precalculate cEndB:
  makeCEnd(B, C, cEndB);

  for (int i = A.size(); i >= 0; i--) {
    for (int j = B.size(); j >= 0; j--) {
      for (int d = 0; d < 2; d++) {
        int & res = dp[i][j][d];
        if (i >= A.size() || j >= B.size()) {
          res = (d ? 0 : -INF);
        } else {
          res = -INF;
          if (A[i] == B[j]) {
            // match
            res = std::max(res, 1 + dp[i + 1][j + 1][d]);
          }
          // move i:
          res = std::max(res, dp[i + 1][j][d]);
          // move j:
          res = std::max(res, dp[i][j + 1][d]);
          if ((cEndA[i] != -1) && (cEndB[j] != -1)) {
            // match c!
            res = std::max < int > (res, C.size() + dp[cEndA[i]][cEndB[j]][1]);
          }
        }
      }
    }
  }
  return max < int > (0, dp[0][0][0]);
}

int getNumber(vector < string > allA, vector < string > allB, vector < string > allC) {
  string A = accumulate(allA.begin(), allA.end(), string(""));
  string B = accumulate(allB.begin(), allB.end(), string(""));
  string C = accumulate(allC.begin(), allC.end(), string(""));
  return getNumber(A, B, C);
}
WINTERANDPRESENTS
Problem Details

Used as: Division One - Level One:

Value	250
Submission Rate	608 / 767 (79.27%)
Success Rate	590 / 608 (97.04%)
High Score	tourist for 248.29 points (2 mins 22 secs)
Average Score	178.16 (for 590 correct submissions)
If `O` is the number of oranges in the final present and `A` the number of apples. We should count the total number of `(A,O)` pairs.

A VALUE OF X AND A TOTAL NUMBER OF FRUITS
When you pick `X`, exactly `X` fruits are taken from each bag. This means there will be exactly `nX` fruits in the present. This is relevant because it means that two different values of `X` cannot give the same pair `(A,O)`. We can safely count the number of pairs for each `X` and add them together. If the minimum number of fruit in each bag is `t` , then there are `t` valid values for `X`: `(1<=X<=t)`. In this problem, the maximum value for `t` is 2000000.

NUMBER OF APPLES
Once `X` is fixed, there will be `nX` fruit. This means that if we pick `A` apples in total, the number of oranges will be determined by `(O = nX - A)`. This means the number of valid values of `A` given `X` is the same as the number of `(A,O)` pairs given `X`.

THE SET OF VALID A
The set of valid `A` values can be very large. The maximum possible number of apples picked is 1000000 * n. The minimum possible is 0. So the valid values of `A` can be any candidate between those two numbers.

Let’s find the actual bounds for the valid `A` values. If we want the number of apples to be as large as possible, we should take as many apples from each bag as we can. The maximum number of apples we can take from bag i is: `min(“apples”[i], X)`, because we cannot take more apples than those in the bag and we cannot exceed X (If we take less than X apples, the remaining fruit taken from the bag will be oranges). The sum `m_A = sum min(“apples”[i], X)` is the maximum number of apples we can take. In order to calculate the minimum number of apples we can take, we need to take as many oranges as possible from each bag. Let `m_O = sum min(“oranges”[i], X)` be the maximum number of oranges, the minimum number of apples is: `nX - m_O`.

A crucial observation is to notice that the set of valid `A` values is a interval. In other words, all the values between `nX - m_O` and `m_A`, inclusive, will be valid. This means that the total number of valid `A` values is equal to: `m_A - (nX - m_O) + 1`.

We need `O(n)` time to calculate `m_A` and `m_O`, in addition to the up to 2000000 values of `X` we check. This will tightly fit into the time constraints.

CODE
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
long getNumber(vector < int > apple, vector < int > orange) {
  int n = apple.size();
  int m = 2000000;
  for (int i = 0; i < n; i++) {
    m = std::min(m, apple[i] + orange[i]);
  }
  long res = 0;

  // For each valid X:
  for (int X = 1; X <= m; X++) {
    // If we take X, then there are nX in total.

    // maximum apples:
    int mA = 0;
    for (int a: apple) {
      mA += std::min(X, a);
    }
    // maximum oranges:
    int mO = 0;
    for (int o: orange) {
      mO += std::min(X, o);
    }
    // total:
    res += mA - (n * X - mO) + 1;
  }
  return res;
}
A FASTER SOLUTION
That solution is official and passes system tests, but it can be done better, python specifically might need an extra hand to run in time. We can reduce the complexity. The trick is to avoid calculating the maximum oranges and apples in `O(n)` time for each value of `X`. Imagine the list of apple counts was sorted. Then there would be a minimum index i for which: `(“apple”[i] >= X)`, the maximum number of apples is equal to the sum of the first `i` elements plus `X(n - i)`. With this idea, we can make a two-pointers method for a `O(m + n)` total complexity, where `m` is the minimum number of fruit in a bag. Giving the following python solution 1.5 seconds run time in the worst case.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
class WinterAndPresents:
  def getNumber(self, apple, orange):
  n = len(apple)
m = min(apple[i] + orange[i]
  for i in range(n))
res = 0;

sa = sorted(apple)
so = sorted(orange)

(sumA, sumO, i, j) = (0, 0, 0, 0)

# For each valid X:
  for X in xrange(1, m + 1):
  # If we take X, then there are nX in total.

# maximum apples:
  while ((i < n) and(sa[i] < X)):
    sumA += sa[i]
i += 1
mA = sumA + X * (n - i);

# maximum oranges:
  while ((j < n) and(so[j] < X)):
    sumO += so[j]
j += 1
mO = sumO + X * (n - j)
# total:
  res += mA - (n * X - mO) + 1
return res
WINTERANDSNOWMEN
Problem Details

Used as: Division One - Level Two:

Value	500
Submission Rate	72 / 767 (9.39%)
Success Rate	55 / 72 (76.39%)
High Score	Petr for 458.89 points (8 mins 39 secs)
Average Score	279.61 (for 55 correct submissions)
SIMPLE AND SLOW DP
Let’s begin with a dynamic programming approach that is too slow but allows us to understand some ideas that will be useful in the final approach.

We can describe the final state by two numbers `X` and `Y`, where `X` is the xor value of the numbers in the first set and `Y` is the xor value of the numbers in the second set. We need `(X < Y)`. Initially, the xor values are `x = y = 0` and we have to assign all positive numbers: `t <= T = max(N,M)` to one (or none) of the sets. Consider a function `f(t, x, y)`, that solves the following sub-problem: We can use positive numbers `(1 <= t)`, the initial xor value of the first set is `x` and the initial xor value of the second set is `y`. How many ways exist to assign the `t` integers to the sets such that the final xor values `X` and `Y` follow `X < Y`?:

Base case: If `t = 0`, then there are no more numbers to use. The xor values, `x` and `y` will not change. If `(x < y)` then there is exactly one way to do it (doing nothing) the result is 1. Else it is impossible to do it and the result is 0.

Otherwise, we can decide what to do with number `t`:

If `(t <= N)`, we can add `t` to the first set, which would change the xor value into `x = x o+ t` (Where `o+` is the xor operation). To count the number of ways to assign the remaining `t-1` integers we can call `f(t - 1, x o+ t, y)`.

If `(t <= M)`, we can add `t` to the second set , its xor value becomes `(y o+ t)` and there are `t-1` integers left: `f(t - 1, x, y o+ t)`.

We can also choose to leave the integer outside both sets. The available integers are decremented: `f(t-1, x, y)`.

`f(t, x, y)` would be equal to the sum of those three partial results.
The recurrence relation is acyclic because it always calls `f(t-1, …, …)`. There are `O(max(N,M))` values for `t`. If the maximum number of bits of `N` and `M` is `b`, then there are `O(2^b)` different values for `x` and `y` (Any combination of 1s and 0s is possible for the xor). Note that `b` is `O(log(max(N,M)))`, so it turns out that there are `O( max(N,M) )` values for `x` and `y`. The total number of states for this recurrence is `O( max(N,M)^3)`, which is too slow for `M, N <= 2000`. We need something better.

SMALLER CONDITION
It would be great if we could remove one of the factors so that we have a `O( max(N,M)^2)` solution. The problem right now is the `X<Y` which forces us to remember two numbers in the state. Here is a key observation: If `X < Y`, then the binary representations would be like this:

1
2
3
i
Y = abcdef1 ?? .. ?
  X = abcdef0 ?? .. ?
There should be a bit position `i` such that the two numbers have equal bits in the higher bit positions, `Y` has 1 in the i-th position and `X` has 0 in that position. The remaining bit positions can have any value.

How about, we try all candidates for position `i`, there are only `O( log( max(N,M) ) )` of them. For each of those candidates count the number of ways to assign the numbers to sets such that the xor values `X` and `Y` follow the property described above.

A SINGLE XOR
At first the above condition seems unhelpful and more complicated than the initial problem. The second key observation is to think about the xor between Y and X:

1
2
3
4
i
Y = abcdef1 ?? .. ?
  X = abcdef0 ?? .. ?
  X ^ Y = ** 0000001 ** ?? .. ?
There are now two conditions:

The xor value `X o+ Y` must follow the pattern: 0000…1. It must have all zeros until the i-th bit which should have 1.

The i-th bit of X must be 0.

This is very nice because applying a xor to one of `X` or `Y` will also apply the xor to `X o+ Y`. Consider the current xor value `x o+ y` and we decide to apply a xor to `x` `(x = x o+ t)`.
`(x o+ t) o+ y = x o+ t o+ y = x o+ y o+ t = (x o+ y) o+ t`
That’s because the commutative and associativity properties of the Xor operation.

This will allow us to solve the problem using a simple dynamic programming. Consider `f(t, z, b)` where `t` is the number of positive integers available. `z` is the current xor `x o+ y` and `b` is the value of the i-th bit of `x`.

Base case: If `t = 0`, then there are no more numbers to use. Result is 1 if and only if `z` contains only zeros for bit positions higher than `i` and 1 for bit `i`. `b = 0`.

Otherwise, decide what to do with number `t`:

If `(t <= N)`, we can add `t` to the first set, which would change the xor value into `x = x o+ t`. Which in place means that `z = z o+ t`. Note also that the i-th bit changes. Let `k` be the i-th bit value in `t`, then `b = b o+ k`. We can solve sub-problem by calling `f(t - 1, z o+ t, b o+ k)`.

If `(t <= M)`, we can add `t` to the second set , `(z = z o+ t)` and there are `t-1` integers left. `b` does not change: `f(t - 1, z o+ t, b)`.

We can also choose to leave the integer outside both sets.: `f(t-1, z, b)`.

`f(t, z, b)` would be equal to the sum of those three partial results.

SOME MORE OPTIMIZATIONS
Note that we must do that `O( max(N,M) ^2)` dynamic programming once for each bit position i. This gives us a total complexity: `O( max(N,M)^2 log(max(N,M)) )`, which can be very tight. We should make sure to optimize as much as possible.

For a given i, the values of the bit positions smaller than i do not matter. We can actually ignore them altogether and remove the first i bits from all numbers in the dp. This means that the total number of bits in the xor value z will be reduced by i. This actually reduces the complexity. For example, without this optimization, we will estimate 11 * 2001 * 2048 * 2 states (11 bit positions, 2001 integers, 2048 variations of z, 2 bits for b). With the optimization we have: 2001 * 2048 * 2 + 2001 * 1024 * 2 + … + 2001 * 1 * 2 = 2001 * 2 * 4096. In effect, the complexity becomes `O( max(N,M)^2)` with a constant factor.

CODE
The following c++ code takes 0.3 seconds in the worst case:

static
const int MOD = 1000000007;
static
const int MAX_BITS = 11;
static
const int MAX_N = 2000;
long dp[MAX_N + 1][1 << MAX_BITS][2];

int i, N, M;

int rec(int t, int z, int b) {
  long res = dp[t][z][b];
  if (res == -1) {
    if (t == 0) {
      // the limit
      if ((z == 1) && (b == 0)) {
        res = 1;
      } else {
        res = 0;
      }
    } else {
      // xor number t to neither A or B:
      res = rec(t - 1, z, b);
      // xor number t to A:
      if (t <= N) {
        res += rec(t - 1, z ^ (t >> i), b ^ ((t >> i) & 1));
      }
      // xor number q = p+1 to B:
      if (t <= M) {
        res += rec(t - 1, z ^ (t >> i), b);
      }
    }
    res %= MOD;
    // save it
    dp[t][z][b] = res;
  }
  return (int) res;
}

int getNumber(int N, int M) {
  long res = 0;
  for (int i = 0; i < MAX_BITS; i++) {
    // first difference will be in i-th bit
    //                             i
    //                  B  = abcdef1??????
    //                  A  = abcdef0??????
    //              A ^ B  = 0000001??????
    // (A >> i) ^ (B >> i) = 0000001
    memset(dp, -1, sizeof(dp));
    this - > N = N;
    this - > M = M;
    this - > i = i;
    res += rec(max(N, M), 0, 0);
  }
  return (int)(res % MOD);
}
WINTERANDSHOPPING
Problem Details

Used as: Division One - Level Three:

Value	950
Submission Rate	17 / 767 (2.22%)
Success Rate	10 / 17 (58.82%)
High Score	Petr for 609.53 points (24 mins 18 secs)
Average Score	442.67 (for 10 correct submissions)
THE SLOW DYNAMIC PROGRAMMING
As a first step, we’ll think of a dynamic programming approach that has too large an algorithmic complexity to work, but will be the starting point.

Imagine we decide what color to sell at each time unit. The constraints tell us that the relevant range of time will be between 0 and 499, inclusive. (Sum of first[i], red[i], green[i], blue[j] will be less than 499). We assign the colors in increasing order. Each time will have at most one color assigned, and any store open at that time will have to sell a ball of that color.

If at the current time `t`, there are no stores open, there is nothing to do , we can proceed to picking the color for time `t+1`.

If we reach time 500, we know that all stores will be closed, assuming the previous choices were valid, this represents a valid assignment of colors.

If there is one store open, we pick a color. The store needs to have at least one ball of that color available. This means that we need to remember the number of balls of each color that are available in each store.

If there are two stores open, we should also pick a color, this time both stores must have at least one ball of that color.

Each step `t` depends on the number of balls available in each of the `n` stores after we decided the colors for the previous `t` times. We pick a valid color and proceed to time `t+1`.

Once a store closes, we do not need to remember how many balls it has left (and actually, since we did everything in a valid way, the store should not have any more balls). Before a store opens, it couldn’t spend any colors. So we only need to remember the number of remaining balls of each color for each of the (at most 2) stores that are open at time t.

At time `t`, we can tell that, for store store `i`, we have already used `t-“first”[i]` balls. This means that time `t`, the number of red balls and the number of green balls are sufficient to find the number of remaining blue balls in a store.

Although we were defining the state as the number of balls remaining in each store, it is possibly simpler to use the number of balls we already spent from each store. This way, every time a new store opens, we can assume we spent 0 balls of each color.

In short, there are 5 parameters that represent a state in the problem. We can use a function `f(t, r_0, g_0, r_1, g_1)`:

`t`: The current time. Assume that the colors for the previous `t` times were already assigned correctly. `f()` returns the number of ways to assign colors to the remaining times.

`r_0`: The number of red balls from store 0 (if it exists) we already used.

`g_0`: The number of green balls from store 0 we already used.

`r_1`: The number of red balls from store 1 (if it exists) we already used.

`g_1`: The number of green balls from store 1 we already used.

This function is already complex to implement. Store 0 and 1 vary or may not even exist depending on the time. We would have to first plan how to assign which stores are 0 and 1 for each time. A convenient idea is to define store 0 as the store that opened the earliest though it is possible two stores open at the same time. In a basic way, the recurrence works as follows:

If `t = 500`, all times were assigned correctly, there is exactly 1 way to finish it. Return 1.

If there are no open stores at time `t`, procceed to time `t+1`. If any store opens at time `t+1`, we wouldn’t have used any colors from it: `f(t+1, 0,0,0,0)`.

If only one store is open, calculate (using `r_0`, `g_0`, `t` and the store’s opening time), the number of remaining balls of each color. If there is only one ball left, use it and make sure to reset the count of used balls to 0 (It would be a new store). Else if we pick color red, for example, increase the number of used red balls `r_0` by 1: `f(t+1, r_0+1, g_0, 0,0)`.

If two stores are open at the same time, we need to find the number of remaining balls of each color. It is more complicated to know if a choice is valid. If any of the stores closes at time `t+1`, we need to be careful to reset the count to 0. If store `s_0` closes at time `t+1` and `s_1` is still open, we need to move the used counts from `r_1, g_1` to `r_0, g_0`.

Let `T = 500` (The maximum time) and the maximum number of balls of a given color in a store be `c`. This recurrence relation would have `O(Tc^4)` states. Each state needs `O(1)` time to do some ad hoc case checking and calling new instances. With dynamic programming, the total time and memory complexity would be `O(Tc^4)`. The constraints are unhelpful: `(T <= 500)`, `(c <= 100)`. We need something better.

3 PARAMETERS
A great complexity would be `O(Tc^2)`, the question is if it is possible to describe the state of two stores by just using two colors instead of four. This requires some analysis.

When there is at most one store open at time `t`, we certainly need to know only `r_0` and `g_0`. The issue is when there are two stores open. The trick is to notice this: Imagine that there are two stores currently open. One of the stores, let’s name it `A` will close before the other store `B`.

We can find the number of remaining balls in A: `r_A`, `g_A` and `b_A`.

Same for `B`: `r_B`, `g_B` and `b_B`.

We know that `A` will close at a time `e`, this means that we will forcefully spend `r_A`, `g_A` and `b_A` balls of each color between time `t` and `e`. The only thing we can change about this is the order.

Between that time interval, the balls we take from `B` should be the same as the ones we take from `A`. A required condition is that there are enough balls of each color in B: `(r_B >= r_A)`, `(g_B >= g_A)`, `(b_B >= b_A)`, at time `e`, we will know that we spent `r_A`, `g_A` and `b_A` balls of each color from store A, store B is closed so we no longer need its state.

The number of orderings for the `r_A`, `g_A` and `b_A` balls can be calculated through combinatorics. There are `((r_A+g_A+b_A),(r_A))` ways to pick the positions of the red balls and `((g_A+b_A),(g_A))` ways to pick the positions of the green balls out of the remaining ones. So it is: `((r_A+g_A+b_A),(r_A)) times ((g_A+b_A),(g_A))` in total. Where `((n),(k))` is the binomial coefficeint.

We can skip to time `e`.

This means that whenever there are 2 stores open, we can easily skip to the earliest time in which one of the two stores closes. Now think about this: We are at time `t`, a store `s_0` was already open and we used `r_0` and `g_0` balls from it. A store `s_1` opens exactly at time `t`. We obviously didn’t spend anything from store `s_1` yet. According to previous analysis, we can skip to the earliest time `e` where either `s_0` or `s_1` will close. After this time, at most one store will remain open, so we will still only need two parameters to describe the number of used balls. It will follow that we can describe the state using only 3 parameters, `f(t, r_0, g_0)`. This needs a case by case analysis:

BASIC THINGS
If there is only one store open, you can use a red ball, a blue ball or a green ball and proceed to time `t+1`. The function call if you use a red ball, for example, will be: `f(t+1, r_0 + 1, g_0)`. There is an exception, if the store closes at time `t+1`, then there is only one ball remaining, since the store will close, we need to reset the used counts to 0: `f(t +1, 0,0)`.

When the time finished: `t = 500`, then we have assigned all colors correctly and return 1 - there is one valid way to finish it.

S0 AND S1 OPEN AT THE SAME TIME
We normally assume that `s_0` is the store that opened the earliest, but it is possible for two stores to open at the same time. This is not a big deal, because we should always make sure to reset the counts to `0,0` whenever the stores close. So in this case, when two stores open at the same time, the used counts will be `(0,0)` and it doesn’t matter which of the stores is `s_0`.

S0 AND S1 CLOSE AT THE SAME TIME
The number of remaining balls in both stores must be the same. We calculate the number of orderings for them and procceed to time `e` , where both stores close. Reset the counts to zero: `f(e, 0,0)`.

S0 CLOSES BEFORE S1
The number of balls of each color in `s_1` must be greater than or equal to the number of remaining balls in `s_0`, calculate the number of orders for the remaining balls in `s_0`. The number of used balls of each color in `s_1` is equal to the number of remaining balls in `s_0`: `f(e, r, g)`.

S0 CLOSES AFTER S1
The number of remaining balls of each color in `s_0` must be greater than or equal to the number of balls in `s_1`, calculate the number of orders for the balls in `s_1`. The number of used balls of each color in `s_0` increases by the number of balls in `s_1`: `f(e, r_0 + r_1, g_0 + g_1)`.

GREAT!
So in fact, we have created a recurrence that only needs `O(Tc^2)` time and space. We just need to code it. It still needs some care with the implementation and to handle different cases. Don’t forget to reset the counts to 0 when all current stores close.

CODE
We can precalculate all relevant binomial coefficients in `O(n^2)` time using Pascal’s triangle.

Problems that ask you to return the result modulo 1,000,000,007 (or a similar number) usually do so to allow us to solve problems that have large results without actually using those large numbers in calculations. We can handle these numbers with modular arithmetic. Read this recipe for more info.
static
const int MOD = 1000000007;
static
const int MAX_BALLS = 100;
static
const int MAX_TIME = 500;

struct store {
  int first, red, green, blue, total;
  int end;
};

int n;
vector < store > stores;

vector < int > timeStores[MAX_TIME];

int dp[MAX_TIME + 1][MAX_BALLS + 1][MAX_BALLS + 1];
int C[MAX_BALLS * 3 + 1][MAX_BALLS * 3 + 1];
long rec(int t, int sred, int sgreen) {
  long res = dp[t][sred][sgreen];
  if (res == -1) {
    res = 0;
    if (t == MAX_TIME) {
      // the end of times...
      res = 1;
    } else {
      int m = timeStores[t].size();
      if (m == 0) {
        res = rec(t + 1, 0, 0);
      } else {
        int i = timeStores[t][0];
        // remaining balls:
        int red = stores[i].red - sred;
        int green = stores[i].green - sgreen;
        int blue = stores[i].blue - ((t - stores[i].first) - sred - sgreen);

        if (m == 1) {
          if (red + green + blue == 1) {
            // the last ball 
            res = rec(t + 1, 0, 0);
          } else {
            if (red > 0) { //use a red ball:
              res = rec(t + 1, sred + 1, sgreen);
            }
            if (green > 0) { //use a green ball:
              res += rec(t + 1, sred, sgreen + 1);
            }
            if (blue > 0) { //use a blue ball:
              res += rec(t + 1, sred, sgreen);
            }
          }
        } else {
          // two stores. The store that opened earliest is timeStores[t][0]
          // thus for it we already spent sred red balls and sgreen green balls
          int j = timeStores[t][1];
          if (stores[i].end == stores[j].end) {
            // both end at the same time !
            // the number of balls must be the same
            if ((red == stores[j].red) &&
              (green == stores[j].green) &&
              (blue == stores[j].blue)
            ) {
              // pick an order:
              res = C[red + green + blue][green + blue];
              res = (res * C[green + blue][green]) % MOD;
              res = (res * rec(stores[i].end, 0, 0)) % MOD;
            }
          } else if (stores[i].end < stores[j].end) {
            // i ends first
            // the balls we spend for i are the same we spend for j
            // in this interval, just pick the order...
            if ((red <= stores[j].red) &&
              (green <= stores[j].green) &&
              (blue <= stores[j].blue)
            ) {
              // pick an order:
              res = C[red + green + blue][green + blue];
              res = (res * C[green + blue][green]) % MOD;
              res = (res * rec(stores[i].end, red, green)) % MOD;
            }
          } else {
            // j ends first
            // the balls we spend for j are the same we spend for
            // i in this interval.
            if ((red >= stores[j].red) &&
              (green >= stores[j].green) &&
              (blue >= stores[j].blue)
            ) {
              // pick an order:
              res = C[stores[j].end - stores[j].first][stores[j].green + stores[j].blue];
              res = (res * C[stores[j].green + stores[j].blue][stores[j].green]) % MOD;
              res = (res * rec(stores[j].end, sred + stores[j].red, sgreen + stores[j].green)) % MOD;
            }
          }
        }
      }
    }
    res %= MOD;
    dp[t][sred][sgreen] = (int)(res);
  }
  return res;
}

int getNumber(vector < int > first, vector < int > red, vector < int > green, vector < int > blue) {
  // Pascal's triangle to precalculate the binomial coefficients
  memset(C, 0, sizeof(C));
  for (int i = 0; i <= MAX_BALLS * 3; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  // save some information about the stores in memory
  n = first.size();
  stores.resize(n);
  for (int i = 0; i < n; i++) {
    stores[i].first = first[i];
    stores[i].red = red[i];
    stores[i].green = green[i];
    stores[i].blue = blue[i];
    stores[i].end = first[i] + red[i] + blue[i] + green[i];
    for (int j = stores[i].first; j < stores[i].end; j++) {
      timeStores[j].push_back(i);
      assert(timeStores[j].size() <= 2);
    }
  }
  // Make sure that for each time, store 0 is the one that was open the earliest:
  for (int t = 0; t < 500; t++) {
    if (timeStores[t].size() == 2) {
      int & s0 = timeStores[t][0];
      int & s1 = timeStores[t][1];
      if (stores[s0].first > stores[s1].first) {
        swap(s1, s0);
      }
    }
  }
  // reset dp table to -1 in all states
  memset(dp, -1, sizeof(dp));
  // start at time 0, 0 used balls in the first store.
  return rec(0, 0, 0);
}
