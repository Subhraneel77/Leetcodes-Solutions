class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0] = 1; // first condition

        for (int i = 1; i < arr.size(); ++i) {
            if (abs(arr[i] - arr[i - 1]) <= 1) continue; // purposely wrote for understanding
            else arr[i] = arr[i - 1] + 1; // second condition   
        }

        return arr.back(); // returns a reference to the last element
    }
};