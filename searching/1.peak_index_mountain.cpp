// Peak Index in a Mountain Array
// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.








// approach-1
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int s = 0, e = arr.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;   // peak is to the right
            } else {
                e = mid;       // peak is at mid or to the left
            }
        }
        return s;

    }
};

// approach-2
// int s = 1, e = arr.size() - 2; // prevent out-of-range
//         while (s <= e) {
//             int mid = s + (e - s) / 2;

//             if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
//                 return mid;
//             }
//             else if (arr[mid - 1] < arr[mid]) { // increasing slope → go right
//                 s = mid + 1;
//             }
//             else {  // decreasing slope → go left
//                 e = mid - 1;
//             }
//         }
//         return -1; // should not happen if input is a valid mountain

       