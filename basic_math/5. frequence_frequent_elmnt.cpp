// //The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

 class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end()); // Step 1: sort array
        long long sum = 0; // window ka sum
        int left = 0, ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // Condition check: cost > k?
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};



// Pehle array sort kiya → nums.
// Ek sliding window maintain kiya [left, right].
// Har window ke liye, cost calculate karte hain:
// cost = nums[right] * (window size) - sum(window)
// Ye batata hai ki kitne increments chahiye sabko nums[right] ke barabar karne ke liye.
// Agar cost > k → left++ karke window chhoti karo.
// Har step pe max window size update karo → wahi answer hai. 

// Complexity
// Sorting: O(n log n)
// Sliding window: O(n)
// Overall: O(n log n)
// Space: O(1)