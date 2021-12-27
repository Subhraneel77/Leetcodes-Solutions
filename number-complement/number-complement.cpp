class Solution {
public:
    int findComplement(int num) {
        int binaryLength = floor(log2(num)) +1;
        int mask = (long long int) (1 << binaryLength) - 1 ;
        return num ^ mask;
    }
};
