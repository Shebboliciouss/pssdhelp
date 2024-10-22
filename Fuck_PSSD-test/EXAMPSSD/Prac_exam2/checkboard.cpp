The Problems
UsingStats rate it discuss it
Used as: Division One - Level One:
Value	250
Submission Rate	486 / 510 (95.29%)
Success Rate	445 / 486 (91.56%)
High Score	vishaliiita for 249.24 points (1 mins 34 secs)
Average Score	221.65 (for 445 correct submissions)
The solution can be split in two parts - computing the missing element and finding the median of the resulting set. The missing element can be found using the value of the mean. If the input array contains N elements, then the sum of all elements of the array with the missing element must be equal to (N + 1) * mean (since the mean is the sum of all elements divided by the number of elements).

When we found the missing element, we add it to the array, sort the resulting array and return the middle element (Java implementation of this algorithm follows):

    public int getMedian(int[] vals, int mean) {
        int N = vals.length + 1;
        int[] v = new int[N];
        int sum = 0;
        for (int i = 0; i < N - 1; i++) 
    sum += (v[i] = vals[i]);
        v[N - 1] = N * mean - sum;
        Arrays.sort(v);
        return v[N / 2];
    }
CheckersBoard rate it discuss it
Used as: Division One - Level Two:
Value	500
Submission Rate	368 / 510 (72.16%)
Success Rate	110 / 368 (29.89%)
High Score	Barlennan for 465.90 points (7 mins 48 secs)
Average Score	334.42 (for 110 correct submissions)
This problem only required an implementation of the approach described in the statement, though the coding could be made much easier by several tricks. To solve this problem, we count the number of black and white moves separately and return the sum of these values. Since white and black pieces move in different directions, we reverse the board before computing the answer for white pieces:

    public int numMoves(String[] board) {
        String[] s = new String[8];
        for (int i = 0; i < 8; i++) s[i] = board[7 - i];
        return count(board, 'B') + count(s, 'W'); // see the implementation of method count later
    }
To compute the number of moves for any color, we just iterate through all cells of the board. For any cell, which is occupied by a piece of the proper color, we check if it can slide or jump. We check two diagonal directions, for each of them checking if the piece can jump or slide in this direction. To simplify coding, we create an additional method isEqual, which checks whether the specified cell is occupied by the specifed piece (or empty). Also, this method will check for the cell being inside the board's bounds, to free us from checking this at every line of the code. Having this method, the implementation becomes easy:

    boolean isEqual(String[] data, int r, int c, int ch) {
        return (r >= 0 && c >= 0 && r < 8 && c < 8 && data[r].charAt(c) == ch);
    }
    int count(String[] data, char our) {
        int slide = 0;
        int jump = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (data[i].charAt(j) == our) {
                    if (isEqual(data, i + 1, j - 1, ' '))
                        slide++;
                    if (isEqual(data, i + 1, j + 1, ' '))
                        slide++;
                    if (isEqual(data, i + 1, j - 1, 'W' + 'B' - our) && isEqual(data, i + 2, j - 2, ' '))
                        jump++;
                    if (isEqual(data, i + 1, j + 1, 'W' + 'B' - our) && isEqual(data, i + 2, j + 2, ' '))
                        jump++;
                }
        return (jump == 0) ? slide : jump;
    }
MixedUpPrimes rate it discuss it
Used as: Division One - Level Three:
Value	1000
Submission Rate	70 / 510 (13.73%)
Success Rate	21 / 70 (30.00%)
High Score	kmd-10 for 829.68 points (13 mins 27 secs)
Average Score	543.74 (for 21 correct submissions)
The very first thing to do when solving this problem is to implement the test for primality:

    boolean isPrime(int p) {
        if (p == 2)
            return true;
        if (p % 2 == 0 || p < 3)
            return false;
        for (int i = 3; i * i <= p; i += 2)
            if (p % i == 0)
                return false;
        return true;
    }
Since the input array contains only six elements, we can build all possible numbers which can be constructed using the input values. To do this, we implement a recursive method that returns the set of numbers which can be constructed using some subset of the input values. This method will try to split the input into two subsets in all possible ways. For each such split, we recursively run our method on both subsets, combining the results we get (i.e., applying all possible arithmetic operations). We aggregate all values for all splits into one big set, which will be returned from the method:

    set generate(int mask) {
        set res;
        if ((mask & (mask - 1)) == 0) { // if the 
            for (int i = 0; i < N; i++)
                if (mask & (1 << i)) {
                    res.insert(data[i]);
                    return res;
                }
        }
        for (int t = 1; t < mask; t++)
            if ((t | mask) == mask && t <= mask - t) {
                set r1 = generate(t);
                set r2 = generate(mask - t);
                for (set::iterator it1 = r1.begin(); r1.end() != it1; it1++)
        for (set::iterator it2 = r2.begin(); r2.end() != it2; it2++)
            int a = *it1;
            int b = *it2;
                        res.insert(a + b);
                        res.insert(a - b);
                        res.insert(b - a);
                        res.insert(a * b);
                        if (b != 0) 
        res.insert(a / b);
                        if (a != 0) 
        res.insert(b / a);
                    }
            }
        return res;
    }
First we run method generate on the whole input set to receive set S, then we check each number in S for primality, finding the smallest and the biggest of them. See Matei's solution for a complete implementation of this approach.