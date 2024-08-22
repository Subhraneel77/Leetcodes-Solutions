class Solution {
public:
    static int findComplement(int num) {
        return num^((1LL<<(32-countl_zero((unsigned)num)))-1);
    }
};