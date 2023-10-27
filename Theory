project@007

*Dijkstra's Shortest Path Algorithm*

Input:
- `vec`: A 2D vector representing the graph with each row containing (u, v, w) denoting an edge from vertex u to vertex v with weight w.
- `vertices`: The total number of vertices in the graph.
- `edges`: The total number of edges in the graph.
- `source`: The source vertex from which the shortest paths are calculated.

Output:
- `dist`: A vector of integers representing the shortest distance from the source vertex to every other vertex.

Algorithm:

1. Create an empty adjacency list `adj` to represent the graph.

2. Populate the adjacency list `adj` with edges and their corresponding weights:
   - For each edge (u, v, w) in `vec`:
     - Add (v, w) to `adj[u]` (since it's an undirected graph, add (u, w) to `adj[v]` as well).

3. Initialize a vector `dist` of size `vertices` with all elements set to `INT_MAX`, representing initial distances.

4. Create an empty set `st` to store pairs (distance, vertex).

5. Set the distance of the `source` vertex to 0 and insert (0, `source`) into `st`.

6. While `st` is not empty:
   - Get the top element `(node_distance, top_node)` from `st`.
   - Remove the top element from `st`.
   - For each neighbor of `top_node` in `adj`:
     - Calculate the new distance `node_distance + neighbor.weight`.
     - If the new distance is less than the current distance in `dist` for the neighbor:
       - Find and erase the existing record of the neighbor from `st` if it exists.
       - Update `dist[neighbor]` with the new distance.
       - Insert `(new_distance, neighbor)` into `st`.

7. Return the vector `dist` containing the shortest distances.

Time Complexity:
- The time complexity of Dijkstra's algorithm with a binary heap is O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph.

This algorithm efficiently finds the shortest path between a given source vertex and all other vertices in a weighted, undirected graph using Dijkstra's shortest path algorithm.

# Code

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
    
    int source;  // Source vertex
    cout<<"ENTER THE SOURCE VERTEX : ";
    cin>>source;
    vector<int> shortestDistances = dijkstra(graph, vertices, edges, source);
    
    // Output the shortest distances from the source vertex
    for (int i = 0; i < vertices; i++) {
        cout << "Shortest distance from " << source << " to " << i << " is: " << shortestDistances[i] << endl;
    }
    
    return 0;
}

# Theory:

*Theory for the Program:*

The provided program implements Dijkstra's shortest path algorithm to find the shortest distances from a given source vertex to all other vertices in a weighted, undirected graph. Here's an explanation of the program:

1. Header and Libraries:
   - The program begins by including the necessary libraries. In this case, `#include <bits/stdc++.h>` includes most standard libraries, making it convenient for competitive programming.

2. Function `dijkstra`:
   - This function takes four parameters:
     - `vec`: A 2D vector representing the graph.
     - `vertices`: The total number of vertices in the graph.
     - `edges`: The total number of edges in the graph.
     - `source`: The source vertex from which the shortest paths are calculated.
   - It returns a vector `dist` containing the shortest distances.

3. Creating the Adjacency List:
   - An unordered map `adj` is created to represent the adjacency list of the graph. It maps a vertex to a list of pairs, where each pair represents a neighbor and its corresponding edge weight.

4. Populating the Adjacency List:
   - The program iterates over the edges represented by `vec` and adds them to the adjacency list. For each edge (u, v, w), it adds (v, w) to `adj[u]` and (u, w) to `adj[v]`.

5. Initializing Distances:
   - A vector `dist` of size `vertices` is created and initialized with `INT_MAX` to represent initial distances.

6. Initializing a Set `st`:
   - A set `st` of pairs `(distance, vertex)` is created. This set will be used to keep track of vertices and their current distances from the source.

7. Setting Source Distance to 0:
   - The distance of the `source` vertex is set to 0, and `(0, source)` is inserted into the set `st`.

8. Dijkstra's Algorithm Loop:
   - The program enters a loop that continues until `st` is not empty.
   - In each iteration, it extracts the top element `(node_distance, top_node)` from `st`.
   - It then explores the neighbors of `top_node`.

9. Relaxation:
   - For each neighbor, it checks if the distance through `top_node` is shorter than the current distance stored in `dist`.
   - If so, it updates the distance and updates `st` accordingly.

10. Returning the Shortest Distances:
    - Once the loop completes, the function returns the vector `dist` containing the shortest distances from the source vertex to all other vertices.

11. Main Function:
    - In the `main` function, a sample graph is provided along with the number of vertices, edges, and the source vertex.

12. User Input and Output:
    - The user is prompted to enter the source vertex.
    - The program then calls `dijkstra` and prints out the shortest distances from the source vertex to all other vertices.

Dijkstra's Algorithm Points:

1. Single-Source Shortest Path:
   - Dijkstra's algorithm finds the shortest paths from a single source vertex to all other vertices in a weighted graph.

2. Greedy Algorithm:
   - It is a greedy algorithm because at each step, it selects the vertex with the smallest distance and explores its neighbors.

3. Non-Negative Edge Weights:
   - Dijkstra's algorithm works only for graphs with non-negative edge weights.

4. Maintains a Priority Queue:
   - It maintains a priority queue (in this case, a set) to efficiently select the vertex with the smallest distance.

5. Optimal Substructure:
   - The shortest path from the source to any vertex is composed of the shortest path to some intermediate vertex and the shortest path from that vertex to the target vertex.

6. Time Complexity:
   - With a binary heap, Dijkstra's algorithm has a time complexity of O((V + E) log V), where V is the number of vertices and E is the number of edges.

# Output

<img width="652" alt="Screenshot 2023-10-24 194239" src="https://github.com/007-cmyk/-project007/assets/124464721/9508388a-f8de-432a-9015-fff7e51652e8">
