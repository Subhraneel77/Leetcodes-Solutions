class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Define a custom comparator for the min-heap
        auto comp = [&arr](const std::pair<int, int>& a,
                           const std::pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };

        // Priority queue (min-heap) with the custom comparator
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(comp)>
            pq(comp);

        // Initialize the heap with the first possible fraction from each
        // numerator
        for (int i = 0; i < arr.size() - 1; ++i) {
            pq.emplace(i, arr.size() - 1);
        }

        // Extract the smallest fraction k-1 times to reach the k-th smallest
        for (int i = 1; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            int numeratorIndex = top.first;
            int denominatorIndex = top.second;

            // Push the next fraction with the same numerator and the next
            // smaller denominator
            if (denominatorIndex - 1 > numeratorIndex) {
                pq.emplace(numeratorIndex, denominatorIndex - 1);
            }
        }

        // The k-th smallest fraction's indices after popping k-1 elements
        auto result = pq.top();
        return {arr[result.first], arr[result.second]};
    }
};