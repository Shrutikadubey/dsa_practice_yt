//compliment of base 10 integer

// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

//For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
//Given an integer n, return its complement.

 Logic (Samjhne Layak)

Pehle ye dekho ki n kitne bits ka hai (binary length).
Example: 5 = 101 → 3 bits.

Us length ka ek mask banao jisme sab bits 1 ho.

Example: 3 bits ka mask = 111 (decimal = 7).

Ab n ^ mask (XOR) kar do.
Kyunki XOR me:

1 ^ 1 = 0

0 ^ 1 = 1
Matlab har bit flip ho jayegi.

class Solution {
public:
    int bitwiseComplement(int n) {
        // Special case: agar n = 0 hai to iska complement 1 hota hai
        if (n == 0) return 1;

        int num = n;  // original value safe rakhne ke liye
        int mask = 0;

        while (num != 0) {
            mask = (mask << 1) | 1;  // mask me 1 add karo
            num >>= 1;               // next bit ke liye shift karo
        }

        return (~n) & mask;  // ya fir (n ^ mask)
    }
};