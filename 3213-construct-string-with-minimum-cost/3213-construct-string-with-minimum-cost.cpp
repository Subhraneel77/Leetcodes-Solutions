struct TrieNode {
    TrieNode *sfx = nullptr;
    TrieNode *dict = nullptr;
    std::array<TrieNode*, 26> child{};
    int word_id = -1;
};
static TrieNode preallocated_nodes[(int)5e4 + 5];
static TrieNode *preallocated_queue[(int)5e4 + 5];
static int dp[(int)1e5 + 5];

class Solution {
public:
    int minimumCost(string &target, vector<string>& words, vector<int>& costs) {
        auto trie = Trie(words, costs);
        int n = target.size();
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1e9;
            for (int j : trie.suffixesAfterAppending(target[i - 1])) {
                dp[i] = std::min(dp[i], dp[i - words[j].size()] + costs[j]);
            }
        }
        return dp[n] == 1e9 ? -1 : dp[n];
    }

    struct Trie {
        int count = 0;
        TrieNode *newTrieNode() {
            preallocated_nodes[count] = TrieNode();
            return &preallocated_nodes[count++];
        }
    
        TrieNode *root = nullptr, *curr = nullptr;
        Trie(vector<string>& words, vector<int> &costs) {
            root = newTrieNode();
            root->sfx = root->dict = root;
            for (int i = 0; i < words.size(); ++i) {
                auto &&word = words[i];
                TrieNode *u = root;
                for (auto c : word) {
                    if (!u->child[c - 'a']) {
                        u->child[c - 'a'] = newTrieNode();
                    }
                    u = u->child[c - 'a'];
                }
                if (u->word_id < 0 || costs[i] < costs[u->word_id]) {
                    u->word_id = i;
                }
            }
    
            Queue q;
            q.push(root);
            while (!q.empty()) {
                TrieNode *u = q.pop();
                for (int i = 0; i < 26; ++i) {
                    auto v = u->child[i];
                    if (!v) {
                        continue;
                    }
    
                    TrieNode *p = u->sfx;
                    while (p != root && !p->child[i]) {
                        p = p->sfx;
                    }
    
                    if (u != root && p->child[i]) {
                        v->sfx = p->child[i];
                    } else {
                        v->sfx = root;
                    }
    
                    v->dict = v->sfx->word_id >= 0 ? v->sfx : v->sfx->dict;
                    q.push(v);
                }
            }
            curr = root;
        }


        Trie &suffixesAfterAppending(char letter) {
            while (curr != root && !curr->child[letter - 'a']) {
                curr = curr->sfx;
            }
    
            if (curr->child[letter - 'a']) {
                curr = curr->child[letter - 'a'];
                start = curr->word_id >= 0 ? curr : curr->dict;
            } else {
                start = root;
            }

            return *this;
        }

        // Iterate all suffixes for current prefix, longest to shortest
        TrieNode *start = root;
        struct Iterator {
            TrieNode *u = nullptr;
            Iterator &operator++() { u = u->dict; return *this; }
            bool operator==(Iterator &o) { return u == o.u; }
            int operator*() { return u->word_id; }
        };
        Iterator begin() { return Iterator{start}; } 
        Iterator end() { return Iterator{root}; } 

        // Optimization literally just for fun
        struct Queue {
            int start = 0, end = 0;
            inline void push(TrieNode *u) { preallocated_queue[end++] = u; }
            inline TrieNode *pop() { return preallocated_queue[start++]; }
            bool empty() { return start == end; }
        };
    };
};