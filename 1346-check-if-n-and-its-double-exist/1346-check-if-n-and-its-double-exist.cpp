class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp; // HashMap to store the occurrence of elements

        for (int i : arr) { // Iterate over the array
            // Check if 2 * i or i / 2 already exists in the map
            // Note: We use a special condition for i / 2 to ensure it's valid
            if (mp[2 * i] || (!(i & 1) && mp[i / 2])) {
                return true; // Return true if the condition is met
            }
            // Add the current number to the map
            mp[i]++;
        }

        return false; // Return false if no such pair exists
    }
};