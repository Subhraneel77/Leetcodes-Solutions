class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;  // XOR to find differing bits
        int count = 0;
        
        // Count the number of 1's in the XOR result
        while (xorResult > 0) {
            count += xorResult & 1;  // Check if the least significant bit is 1
            xorResult >>= 1;         // Right shift to check the next bit
        }
        
        return count;
    }
};