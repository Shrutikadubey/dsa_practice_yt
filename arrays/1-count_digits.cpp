//1.count digits (gfg)

// Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.
// A digit d of n divides n evenly if the remainder when n is divided by d is 0 (n % d == 0).
// Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.

class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int num = n;
        int count = 0;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0 && num % digit == 0) {
                count++;
            }
            n /= 10;
        }

        return count;
    }
};


Example Walkthrough

Input: n = 1012

Digits = {1, 0, 1, 2}

Check:

1 divides 1012 → ✅

0 → skip

1 divides 1012 → ✅

2 divides 1012 → ✅

Total = 3

Output → 3