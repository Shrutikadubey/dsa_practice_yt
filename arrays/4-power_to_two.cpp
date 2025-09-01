231. Power of Two

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

Problem:

Hume check karna hai ki given integer n kya power of 2 hai ya nahi.
Matlab:

Agar n = 1, 2, 4, 8, 16, 32 ... to return true.

Otherwise false.

Observations:

Power of two ka matlab hai uski binary representation me sirf ek hi bit 1 hota hai.

Example:
1 = 0001 ✅
2 = 0010 ✅
4 = 0100 ✅
6 = 0110 ❌ (do 1 hain)
Negative numbers aur 0 kabhi bhi power of two nahi hote.

🔹 Solutions:
✅ Solution 1 (Bit Manipulation Trick)

Formula:
👉 n > 0 && (n & (n - 1)) == 0

Explanation:

Agar n power of 2 hai to uske binary me ek hi 1 hota hai.
(n - 1) us bit ko hata ke uske neeche sab 1 bana deta hai.
Isliye n & (n - 1) hamesha 0 hota hai.

Example:
n = 8 → 1000
n - 1 = 7 → 0111
1000 & 0111 = 0000


class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans=1;
        for(int i=0;i<=30;i++){
            if(ans==n){
                return true;
            }if(ans<INT_MAX/2)
             ans=ans*2;
        }
        return false;
    }
};