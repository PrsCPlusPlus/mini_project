#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // adjacency list is created
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0 ; i < edges ; ++i)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dist(vertices);
    for(int i = 0 ; i < vertices ; ++i)
    {
        dist[i] = INT_MAX;
    }
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert(make_pair(0 , source));
    while(!st.empty())
    {
        auto top = *(st.begin());
        int node_distance = top.first;
        int top_node = top.second;
        //erase top record
        st.erase(st.begin());
        //traverse on neighbours
        for(auto neighbour : adj[top_node]){
            if(node_distance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first));
                if(record != st.end()){
                    st.erase(record);
                }
                dist[neighbour.first] = node_distance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first] , neighbour.first));
            }
        }
    }
    return dist;
}
int main() {
    // Number of vertices and edges in the graph
    int vertices = 6;
    int edges = 9;
    
    // Sample graph represented as a 2D vector (u, v, w)
    vector<vector<int>> graph = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1},
        {3, 5, 5},
        {4, 5, 2},
        {2, 5, 7}
    };
    
    int source = 0;  // Source vertex
    
    vector<int> shortestDistances = dijkstra(graph, vertices, edges, source);
    
    // Output the shortest distances from the source vertex
    for (int i = 0; i < vertices; i++) {
        cout << "Shortest distance from " << source << " to " << i << " is: " << shortestDistances[i] << endl;
    }
    
    return 0;
}
