//2. reverse integer

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// e.g-> 123=>321

// concept- last digit =n%10
//          ans=(ans*10)+digit
//          n=n/10
//overflow aur edge case ko handle kaise kre
ans>INT_MAx/10

class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x!=0){
            int digit=x%10;
            if((ans>INT_MAX/10)||(ans<INT_MIN/10)){
                return 0;
            }
            ans=(ans*10)+digit;
            x=x/10;
        }
        return ans;
    }
};

Kaise Solve Karein (Logic)

Ek ek digit nikalna hai (x % 10) se.

Usko new reversed number me dalna hai (rev = rev * 10 + digit).

Har step pe check karna hai ki rev 32-bit ke limit ke bahar na chala jaye. Agar gaya toh 0 return.

Last me rev return kar do.