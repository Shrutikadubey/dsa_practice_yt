//sum 1 to n
//Given a positive integer n, The task is to find the value of Σi F(i) where i is from 1 to n and function F(i) is defined as the sum of all divisors of i.

 long long sumOfDivisors(long long n) {
  long long ans = 0;
        for (long long d = 1; d <= n; d++) {
            ans += d * (n / d);
        }
        return ans;
    }