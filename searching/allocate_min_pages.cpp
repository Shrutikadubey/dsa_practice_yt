//book allocation
//allocate min. no. of pages
//Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.


#include <vector>
class Solution {
  public:
    // Helper function to check if allocation is possible
    bool isPossible(vector<int> &arr, int k, int maxPages) {
        int studentCount = 1;
        int pageSum = 0;
        
        for (int pages : arr) {
            if (pages > maxPages) return false; // single book exceeds limit
            
            if (pageSum + pages > maxPages) {
                studentCount++;
                pageSum = pages;
                if (studentCount > k) return false;
            } else {
                pageSum += pages;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return -1;  // Not enough books for students
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;  // Try smaller maximum
            } else {
                low = mid + 1;  // Increase pages limit
            }
        }
        return result;
    }
};
