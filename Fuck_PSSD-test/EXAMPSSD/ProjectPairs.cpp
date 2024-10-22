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









