class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> charCount;
        for (char c : S) {
            charCount[c]++;
        }

        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> maxHeap(comp);

        for (const auto& entry : charCount) {
            maxHeap.push(entry);
        }

        string result = "";
        char prevChar = '\0';

        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            result += current.first;
            charCount[current.first]--;

            if (prevChar != '\0' && charCount[prevChar] > 0) {
                maxHeap.push({prevChar, charCount[prevChar]});
            }

            prevChar = current.first;
        }

        return result.length() == S.length() ? result : "";
    }
};
