class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int currNum = 1;
        int index = 0;

        while (currNum <= n && index < target.size()) {
            int num = target[index];
            if (num == currNum) {
                operations.push_back("Push");
                currNum++;
                index++;
            } else {
                operations.push_back("Push");
                operations.push_back("Pop");
                currNum++;
            }
        }

        return operations;
    }
};