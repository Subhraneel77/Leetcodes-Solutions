class UnionFind {
    vector<int> root, Size;
public:
    int merge;
    UnionFind(int N) : root(N), Size(N, 1), merge(0) {
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x])
            return x;
        return root[x] = Find(root[x]); // Path compression
    }

    bool Union(int x, int y) {
        x = Find(x), y = Find(y);

        if (x == y) return false;

        if (Size[x] > Size[y]) {
            Size[x] += Size[y];
            root[y] = x;
        } else {
            Size[y] += Size[x];
            root[x] = y;
        }
        merge++;
        return 1;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size();
        const int side = n+1; // side length of the extended grid
        const int N = side*side; // total vertices in the extended grid

        bitset<962> vertex = 0; // Supports up to a 31x31 grid
        UnionFind G(N);

        int N0 = N-side;
        vertex[0] = 1;         // Top-left corner
        vertex[N0] = 1;        // Bottom-left corner

        for (int i = 0; i < n; i++) {
            vertex[i+1] = 1;               // Top border
            G.Union(i, i+1);

            vertex[i+N0+1] = 1;          // Bottom border
            G.Union(i+N0, i+N0+1);

            vertex[i*side] = 1;            // Left border
            G.Union(i*side, i*side+side);

            vertex[n+i*side] = 1;        // Right border
            G.Union(n+i*side, n+(i+1)*side);
        }

        int E = 4*n; // Initial edges from the borders

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '\\') {
                    int u = i*side + j;
                    int v = (i+1) * side + j + 1;
                    vertex[u] = 1, vertex[v] = 1;
                    G.Union(u, v);
                    E++;
                } 
                else if (grid[i][j] == '/') {
                    int u = i*side + j + 1;
                    int v = (i+1) * side + j;
                    vertex[u] = 1, vertex[v] = 1;
                    G.Union(u, v);
                    E++;
                }
            }
        }

        int V = vertex.count();
        int component = max(1, V - G.merge);
        int F = E-V + 1 + component;

        // output
        //cout<< "V="<<V<<", E="<<E<<", component="<<component<<", F="<<F<< endl;
        
        return F - 1; // Final face count
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();