class Solution {
    public int bitwiseComplement(int N) {
        return N == 0 ? 1 : N ^ ((Integer.highestOneBit(N) << 1) - 1);
    }
}