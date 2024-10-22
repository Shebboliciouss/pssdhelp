/*100088. Maximum Value of an Ordered Triplet I
User Accepted:11991
User Tried:13607
Total Accepted:12490
Total Submissions:29982
Difficulty:Easy
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> results(n);
//         results[n-1] = nums[n-1];
//         for(int i = n-2;i>=0;i--){
//             results[i]=max(results[i+1], nums[i]);
//         }
        
        
        
//         int ans = 0;
//         for(int i = 0; i < n-2; i++){
//             for(int j = i+1; j < n-1;j++){
//                 ans = max(ans, (nums[i]-nums[j])*results[j+1]);
//             }
//         }
//         // for (int i = 0; i<n; i++){
//         //     for(int j = i+1; j < n-1; j++){
//         //         for(int k = j+1; k<)
//         //     }
//         // }
//         return ans;
//     }
// };

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> numk(n,0);
        vector<int> numi(n,0);
        
        numk[n-1] = nums[n-1];
        numi[0] = nums[0];
        
        for(int i = n-2;i>=0;i--){
            numk[i]=std::max(numk[i+1], nums[i]);
        }
        
        for (int i = 1; i < n; i++){
            numi[i] = std::max(numi[i-1], nums[i]);
        }
        
        
        long long ans = 0;
        //for(int i = 0; i < n-2; i++){
            for(int j = 1; j < n-1;j++){
                long long value = (long)(numi[j-1]-nums[j])*(long)numk[j+1];
                ans = max(ans, value);
            }
        //}
        
        return ans;
    }
};

int main(){
//     Testcase:
//     [12,6,1,2,7]
// [1,10,3,4,19]
// [1,2,3]
// [31,1,10,9,8]
// return:
// 77
// 133
// 0
// 300
    Solution s;
    vector<int> nums = {12,6,1,2,7};
    vector<int> nums1 = {1,10,3,4,19};
    vector<int> nums2 = {1,2,3};
    vector<int> nums3 = {31,1,10,9,8};
    cout << s.maximumTripletValue(nums) << endl;
    cout << s.maximumTripletValue(nums1) << endl;
    cout << s.maximumTripletValue(nums2) << endl;
    cout << s.maximumTripletValue(nums3) << endl;
    return 0;
}