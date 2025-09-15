// 456. 132 Pattern
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.

 

// Example 1:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <climits>
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        stack<int> st;   // store potential "3"s
        int third = INT_MIN;  // potential "2"
        
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) return true;  // found nums[i] < nums[k]
            
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }

};
int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    cout << (sol.find132pattern(nums) ? "true" : "false") << endl; // Output: true
    return 0;
}