// //Running Sum of 1d Array

// //Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];  // Add previous sum to current element
    }
    return nums;

    }
};


// Approach:

// Start with the first element as it is.

// For each next element, add it to the sum of all previous elements.

// Store the result at each step.