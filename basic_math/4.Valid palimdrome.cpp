// //A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.



class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Compare lowercase versions
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;

    }
};

// Hum two pointers use karenge:
// left → start se
// right → end se
// Jab tak left < right hai:
// Agar s[left] ya s[right] alphanumeric nahi hai → skip kar do.
// Fir dono ko tolower karke compare karo. Agar equal nahi hai → palindrome nahi hai (return false).
// Agar equal hai toh left++, right-- move karte hain.
// Loop ke baad agar koi mismatch nahi mila → true return. 
// Complexity:
// Time Complexity → O(n) (string ek hi baar traverse hoti hai)
// Space Complexity → O(1) (no extra storage needed)