class Solution {
    public void rotate(int[] A, int k) {
        int n = A.length;
        if(k==n) return;
        k = k%n;
        reverse(A, 0, n);
        reverse(A, 0, k); // -> [left, right)
        reverse(A, k, n); // -> [left, right)
    }
    
    private void reverse(int[]A , int l, int r) {
        while(l<r) {
            int t = A[l];
            A[l] = A[r-1];
            A[r-1] = t;
            l++;
            r--;
        }
    }
}