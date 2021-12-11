class Solution {
    public int nthMagicalNumber(int N, int A, int B) {
        if (A > B) return nthMagicalNumber(N, B, A);
        int M = (int) 1e9 + 7;
        if (B % A == 0) return (int) ((1L * A * N) % M);
        long L = A / gcd(A, B) * B;
        long lo = A, hi = lo * N;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            long c = mi / A + mi / B - mi / L;
            if (c < N) lo = mi + 1;
            else hi = mi;
        }
        return (int) (lo % M);
    }

    private int gcd (int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}