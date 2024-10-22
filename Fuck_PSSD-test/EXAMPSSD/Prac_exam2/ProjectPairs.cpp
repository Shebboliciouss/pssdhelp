#include <iostream>
#include <vector>

using namespace std;

class ProjectPairs
{
public:
	int minDiff(vector<int> practice)
	{
		vector<int> v;
		v=practice;
		int i;
		int j;
		int sum;
		sum=0;
		int min;
		int diff;

		for(i=0;i<practice.size();i++)
		{
			for(j=1;j<practice.size();j++)
			{
				sum1=practice[i]+practice[j];
				sum2=practice[i+1]+practice[j+1];
				diff=abs(sum1-sum2);
				
			}
		}

	}
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ProjectPairs
{
public:
    int minDiff(vector<int> practice)
    {
        int N = practice.size();
        int minDiff = INT_MAX;

        for(int i=0; i<N; i++)
        {
            for(int j=i+1; j<N; j++)
            {
                for(int k=0; k<N; k++)
                {
                    for(int l=k+1; l<N; l++)
                    {
                        if(i!=k && i!=l && j!=k && j!=l)
                        {
                            int sum1 = practice[i] + practice[j];
                            int sum2 = practice[k] + practice[l];
                            int diff = abs(sum1 - sum2);
                            minDiff = min(minDiff, diff);
                        }
                    }
                }
            }
        }

        return minDiff;
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ProjectPairs
{
public:
    int minDiff(vector<int> practice)
    {
        // This method takes a vector of integers 'practice' as input.

        int N = practice.size(); // Get the size of the input vector.
        int minDiff = INT_MAX;   // Initialize a variable to store the minimum difference.

        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                // The first loop iterates through all pairs of distinct elements (i and j).

                for(int k = 0; k < N; k++)
                {
                    for(int l = k + 1; l < N; l++)
                    {
                        // The second loop iterates through all pairs of distinct elements (k and l).

                        if(i != k && i != l && j != k && j != l)
                        {
                            // Ensure that i, j, k, and l are all distinct.

                            int sum1 = practice[i] + practice[j]; // Calculate the sum of elements at indices i and j.
                            int sum2 = practice[k] + practice[l]; // Calculate the sum of elements at indices k and l.
                            int diff = abs(sum1 - sum2);           // Calculate the absolute difference between the sums.

                            minDiff = min(minDiff, diff); // Update the minimum difference if 'diff' is smaller.
                        }
                    }
                }
            }
        }

        return minDiff; // Return the minimum difference found.
    }
};










