//single_elemnt_sorted_array
//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                // unique element is on right
                s = mid + 2;
            } else {
                // unique element is on left (including mid)
                e = mid;
            }
        }
        return nums[s];
    }
