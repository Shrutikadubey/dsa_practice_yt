// The Painter's Partition Problem-II
// Difficulty: HardAccuracy: 27.52%Submissions: 154K+Points: 8
// Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

// Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

#include<iostream>
#include<vector>
class Solution {
  public:
    // Helper function: check if we can paint all boards within maxTime using k painters
    bool isPossible(vector<int>& arr, int k, long long maxTime) {
        int painterCount = 1;
        long long timeSum = 0;

        for (int len : arr) {
            if (len > maxTime) return false; // single board exceeds limit

            if (timeSum + len > maxTime) {
                painterCount++;
                timeSum = len;
                if (painterCount > k) return false;
            } else {
                timeSum += len;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());   // biggest board
        long long high = accumulate(arr.begin(), arr.end(), 0LL); // sum of all boards
        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;  // try smaller max time
            } else {
                low = mid + 1;   // need more time
            }
        }
        return (int)result;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << obj.minTime(arr, k) << endl;  // Output: 60

return 0;
}