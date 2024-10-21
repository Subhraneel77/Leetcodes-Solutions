class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return dfs(0, s, seen);
    }

private:
    int dfs(int start, const string& s, unordered_set<string>& seen) {
        if (start == s.size()) return 0;

        int maxSplits = 0;
        for (int i = start + 1; i <= s.size(); ++i) {
            string substring = s.substr(start, i - start);

            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + dfs(i, s, seen));
                seen.erase(substring);  // Backtrack
            }
        }
        return maxSplits;
    }
};