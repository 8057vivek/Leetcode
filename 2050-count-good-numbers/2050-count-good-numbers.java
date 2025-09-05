class Solution {
    private static final long MOD = 1000000007;

    public int countGoodNumbers(long n) {
        long evens = (n + 1) / 2;
        long odds = n / 2;

        long part1 = modPow(5, evens, MOD); 
        long part2 = modPow(4, odds, MOD); 

        return (int)((part1 * part2) % MOD);
    }

    long modPow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { // if exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod; 
            exp = exp / 2;              
        }
        return result;
    }

}
