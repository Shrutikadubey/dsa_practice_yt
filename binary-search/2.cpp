// Floor in a Sorted Array
// Difficulty: EasyAccuracy: 33.75%Submissions: 518K+Points: 2Average Time: 30m
// Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.

// Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.

// Examples

// Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
// Output: 1
// Explanation: Largest number less than or equal to 5 is 2, whose index is 1.

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int left = 0, right = arr.size() - 1;
        int ans = -1; // default (if no floor exists)

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= x) {
                ans = mid;       // valid floor candidate
                left = mid + 1;  // look for bigger floor
            } else {
                right = mid - 1; // look left
            }
        }
        return ans;
    }
};
