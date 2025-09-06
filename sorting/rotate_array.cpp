// //189. Rotate Array

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k = k % n; // in case k > n

        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};