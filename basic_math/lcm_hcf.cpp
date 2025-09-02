//lcm and hcf(gfg)
// Given two integers a and b, You have to compute their LCM and GCD and return an array containing their LCM and GCD.

// Examples:

// Input: a = 5 , b = 10
// Output: [10, 5]
// Explanation: LCM of 5 and 10 is 10, while their GCD is 5.

// Explanation
// __gcd(a,b) → STL function jo Euclidean algorithm use karta hai.
// LCM ka formula:
// LCM=a×b/GCD
// ​1LL * a * b likha hai taaki multiplication ke time integer overflow na ho.
// Output vector me {lcm, gcd} return karna hai.

 vector<int> lcmAndGcd(int a, int b) {
        // gcd nikalne ka inbuilt function
        int gcd = __gcd(a, b);
        
        // lcm formula = (a*b)/gcd
        long long lcm = (1LL * a * b) / gcd;
        
        // return vector {lcm, gcd}
        return { (int)lcm, gcd };
 }