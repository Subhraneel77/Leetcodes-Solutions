class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0, high = height.size() - 1, res = 0;
        int low_max = 0, high_max = 0;

        while(low <= high){
            if(height[low] < height[high]){
                if (height[low] > low_max){
                    low_max = height[low];
                } else {
                    res += low_max - height[low];
                }
                low++;
            } else {
                if (height[high] > high_max){
                    high_max = height[high];
                } else {
                    res += high_max - height[high];
                }
                high--;
            }
        }

        return res;
    }
};