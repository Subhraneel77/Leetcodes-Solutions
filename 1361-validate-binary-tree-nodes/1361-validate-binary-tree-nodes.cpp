class Solution {
public:
    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
        std::unordered_map<int, std::vector<int>> graph;
        std::vector<int> in_degree(n, 0);

        for (int node = 0; node < n; ++node) {
            int left = leftChild[node];
            int right = rightChild[node];
            if (left != -1) {
                graph[node].push_back(left);
                in_degree[left]++;
            }
            if (right != -1) {
                graph[node].push_back(right);
                in_degree[right]++;
            }
        }

        std::vector<int> root_candidates;
        for (int node = 0; node < n; ++node) {
            if (in_degree[node] == 0) {
                root_candidates.push_back(node);
            }
        }

        if (root_candidates.size() != 1) {
            return false;
        }
        int root = root_candidates[0];

        std::queue<int> q;
        std::unordered_set<int> seen;
        q.push(root);
        seen.insert(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (graph.find(node) != graph.end()) {
                for (int child : graph[node]) {
                    if (seen.find(child) != seen.end()) {
                        return false;
                    }
                    seen.insert(child);
                    q.push(child);
                }
            }
        }

        return seen.size() == n;
    }
};