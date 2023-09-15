//Approach-1 (Using 2-D matrix graph) - Prim's Algorithm
class Solution {
public:
    // Function to find the index of the minimum key in 'key' vector that is not yet included in MST
    int minKey(vector<bool>& inMST, vector<int>& key) {
        int minIndex = 0;
        int minVal   = INT_MAX;
        // Loop through all vertices to find the minimum key
        for(int i = 0; i < key.size(); i++) {
            // Check if the vertex is not in MST and its key is smaller than the current minimum value
            if(!inMST[i] && key[i] < minVal) {
                minIndex = i;
                minVal   = key[i];
            }
        }
        return minIndex; // Return the index of the minimum key
    }

    // Function to calculate the minimum spanning tree (MST) of a given 'graph' with 'V' vertices
    int MST(vector<vector<int>>& graph, int V) {
        vector<int>  key(V, INT_MAX); // Initialize key values for all vertices to be infinity
        vector<bool> inMST(V, false); // Initialize all vertices as not included in MST
        key[0] = 0; // Start with the first vertex as the source
        
        // Loop through V-1 vertices (all except the first one)
        for(int count = 1; count <= V - 1; count++) {
            int u    = minKey(inMST, key); // Find the vertex with the minimum key not in MST
            inMST[u] = true; // Include the selected vertex in MST
            
            // Update the key values of adjacent vertices
            for(int v = 0; v < V; v++) {
                // If there is an edge from 'u' to 'v', 'v' is not in MST, and the edge weight is smaller than 'key[v]'
                if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v]; // Update the key value of 'v'
                }
            }
        }
        
        int cost = 0;
        for(int i : key) {
            cost += i; // Calculate the sum of key values, which represents the minimum cost of MST
        }
        return cost; // Return the minimum cost of MST
    }

    // Function to calculate the minimum cost to connect all points using Prim's Algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n)); // Create a 2D matrix 'graph' to represent the distances between points
        
        // Calculate the Manhattan distance (md) between all pairs of points and populate the 'graph' matrix
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                vector<int> p1 = points[i];
                vector<int> p2 = points[j];
                int md         = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]); // Calculate Manhattan distance
                graph[i][j]    = md; // Store the distance in both directions since it's an undirected graph
                graph[j][i]    = md;
            }
        }
        
        return MST(graph, n); // Find and return the minimum cost of connecting all points using MST
    }
};